typedef struct {
    struct TreeNode** stack;
    int top;
} BSTIterator;

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj->stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    obj->top = -1;
    while (root != NULL) {
        obj->stack[++obj->top] = root;
        root = root->left;
    }
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* top = obj->stack[obj->top--];
    int value = top->val;
    if (top->right != NULL) {
        top = top->right;
        while (top != NULL) {
            obj->stack[++obj->top] = top;
            top = top->left;
        }
    }
    return value;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top != -1;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->stack);
    free(obj);
}
