#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

//void push( TreeNode** p, int value );
bool isSibling( TreeNode* root, int a, int b );
int nodeDepth( TreeNode* root, int value, int depth );
bool isCousins( TreeNode* root, int x, int y );
void destroy( TreeNode* root );
//TreeNode* insert( TreeNode* root, int value );
TreeNode* newNode (int value);

int main( void ) {
    TreeNode* root = newNode( 1 );

    root->left = newNode( 2 );
    root->left->right = newNode( 4 );
    root->right = newNode( 3 );
    root->right->right = newNode( 5 );

    int x = 5, y = 4;

    bool test = isCousins(root, x, y);
    printf( "%s\n", test ? "True!" : "False!" );

    destroy( root );
}

TreeNode* newNode( int value ) {
    TreeNode *newNode = ( TreeNode* ) malloc ( sizeof( TreeNode ));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int nodeDepth( TreeNode* root, int value, int depth ) {
    if( root == NULL ) {
        return -1;
    }
    if( root->val == value ) {
        return depth;
    }
    
    int leftDepth = nodeDepth( root->left, value, depth + 1 );
    if( leftDepth != -1 ) {
        return leftDepth;
    }
    
    int rightDepth = nodeDepth( root->right, value, depth + 1 );
    return rightDepth;
}

bool isSibling( TreeNode* root, int a, int b) {
    if( root == NULL ){
        return false;
    }

    if( root->left != NULL && root->right != NULL ) {
        if(( root->left->val == a && root->right->val == b ) ||
            ( root->left->val == b && root->right->val == a )) {
            return true;
        }
    }
    return isSibling( root->left, a, b ) || isSibling( root->right, a, b );
}

bool isCousins( TreeNode* root, int x, int y ) {
    int left = nodeDepth( root, x, 0 );
    int right = nodeDepth( root, y, 0 );
 
    if( left != -1 && right != -1 && left == right && !isSibling( root, x, y )) {
        return true;
    }
    return false;
}

void destroy( TreeNode* root ) {
    if( root == NULL ) {
        return;
    }
    destroy( root->left );
    destroy( root->right );
    
    free( root );
}
