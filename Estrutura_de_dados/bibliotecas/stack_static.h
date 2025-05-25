typedef struct {
    int top;
    int itens[50];
    int size;
} Stack;

void Stack_init(Stack *stk);
void Stack_clear(Stack *stk);
int Stack_isEmpty(Stack *stk);
int Stack_isFull(Stack *stk);
void Stack_push(Stack *stk, int value);
int Stack_pop(Stack *stk);
int Stack_top(Stack *stk);
