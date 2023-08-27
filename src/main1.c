#include <stdio.h>
#include <bool.h>

struct treenode {
    int val;
    struct treenode* left;
    struct treenode* right;
};
typedef struct treenode TreeNode;

int main( void ) {

}

bool isCousins( struct TreeNode* root, int x, int y ){
    TreeNode* aux = root;

    while( aux->right != NULL ) {
        aux = aux->right;
    }
    while( aux->left != NULL ) {
        aux = aux->left;
    }
    int valueX = aux->val;

    TreeNode* temp = root;
    while( temp->left != NULL ) {
        temp = temp->left;
    }
    while( temp->left != NULL ) {
        temp = temp->left;
    }
    int valueY = temp->val;

    if( valueX == x && valueY == y ) {
        return true;
    } else {
        return false;
    }
}