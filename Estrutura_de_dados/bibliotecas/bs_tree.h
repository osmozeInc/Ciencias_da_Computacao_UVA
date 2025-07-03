typedef struct BST BST;
typedef struct BST_node BST_node;

struct BST_node {
    void *value;
    BST_node *left, *right;
};

struct BST {
    int size;
    struct BST_node *root;
    int (*cmp)(void *, void *);
};

BST *BST_init(int (*cmp)(void *, void *));
void BST_free(BST *bst);
void BST_insert(BST *bst, void *value);
void *BST_search(BST *bst, void *value);
void *BST_remove(BST *bst, void *value);
void BST_print(BST *bst);


/*
void Tree_print(Tree *t);
int Tree_returnResult(Tree *t);
Tree *Tree_initSetTree();
int Tree_searchItemAndReturnParent(Tree *t, int item);
*/