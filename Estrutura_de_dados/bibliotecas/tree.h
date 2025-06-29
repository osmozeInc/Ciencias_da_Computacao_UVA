typedef struct Tree Tree;

typedef enum {
    INT_TYPE,
    CHAR_TYPE,
} ValueType;

struct Tree {
    void *value;
    ValueType type;
    struct Tree *left;
    struct Tree *right;
};

Tree *Tree_init(void *value, ValueType type, Tree *left, Tree *right);
void Tree_free(Tree *t);
void Tree_print(Tree *t);
int Tree_returnResult(Tree *t);
Tree *Tree_initSetTree();
int Tree_searchItemAndReturnParent(Tree *t, int item);