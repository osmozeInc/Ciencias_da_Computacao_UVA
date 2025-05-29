typedef struct List List;
typedef struct Node Node;

List *List_init();
void List_free(List *l);
void List_insert(List *l, int value);
int List_remove(List *l, int value);
int List_getLength(List *l);
void List_print(List *l);