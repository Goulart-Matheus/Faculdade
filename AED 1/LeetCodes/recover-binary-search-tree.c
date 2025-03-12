void inOrderTraversal(struct TreeNode* raiz, struct TreeNode** primeiro, struct TreeNode** segundo, struct TreeNode** anterior) {
    if (raiz == NULL) {
        return;
    }


    inOrderTraversal(raiz->left, primeiro, segundo, anterior);

    if (*anterior && raiz->val < (*anterior)->val) {
        if (*primeiro == NULL) {
            *primeiro = *anterior;
        }
        *segundo = raiz;
    }

    *anterior = raiz;

    inOrderTraversal(raiz->right, primeiro, segundo, anterior);
}

void recoverTree(struct TreeNode* raiz) {
    struct TreeNode* primeiro = NULL;
    struct TreeNode* segundo = NULL;
    struct TreeNode* anterior = NULL;

    inOrderTraversal(raiz, &primeiro, &segundo, &anterior);

    if (primeiro && segundo) {
        int temp = primeiro->val;
        primeiro->val = segundo->val;
        segundo->val = temp;
    }
}
