/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    
    if(!root){
    struct TreeNode* NewRoot = (struct TreeNode *) malloc (sizeof(struct TreeNode));
      NewRoot->left = NULL;
      NewRoot->right = NULL;
      NewRoot->val = val;

      return NewRoot;
    }

    if(root->val < val){
       root->right = insertIntoBST(root->right, val);
    }else if(root->val > val){
       root->left = insertIntoBST(root->left, val);
    }

    return root;
}