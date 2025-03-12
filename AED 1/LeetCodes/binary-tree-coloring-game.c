/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool btreeGameWinningMove(struct TreeNode* root, int n, int x) {
    struct TreeNode* target = NULL;
    
    void findNode(struct TreeNode* node) {
        if (!node) return;
        if (node->val == x) {
            target = node;
            return;
        }
        findNode(node->left);
        findNode(node->right);
    }
    findNode(root);
    
    int leftCount = countNodes(target->left);
    int rightCount = countNodes(target->right);
    
    int parentCount = n - (leftCount + rightCount + 1);
    
    int maxPartition = leftCount;
    if (rightCount > maxPartition) maxPartition = rightCount;
    if (parentCount > maxPartition) maxPartition = parentCount;
    
    return maxPartition > n / 2;
}
