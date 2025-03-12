/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 struct TreeNode* contruirArvore(int* preorder, int* inorder, int* preorderIndex, 
    int inorderStart, int inorderEnd, int inorderSize) {
if (inorderStart > inorderEnd) {
return NULL;
}

int raiz = preorder[*preorderIndex];
(*preorderIndex)++; 

struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
node->val = raiz;
node->left = node->right = NULL;

if (inorderStart == inorderEnd) {
return node;
}

int raizIndex = -1;
for (int i = inorderStart; i <= inorderEnd; i++) {
if (inorder[i] == raiz) {
raizIndex = i;
break;
}
}

node->left = contruirArvore(preorder, inorder, preorderIndex, inorderStart, raizIndex - 1, inorderSize);
node->right = contruirArvore(preorder, inorder, preorderIndex, raizIndex + 1, inorderEnd, inorderSize);

return node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
int preorderIndex = 0;  
return contruirArvore(preorder, inorder, &preorderIndex, 0, inorderSize - 1, inorderSize);
}