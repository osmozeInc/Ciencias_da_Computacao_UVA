typedef struct Stack Stack;

Stack *Stack_init(int size);
void Stack_free(Stack *stk);
int Stack_isEmpty(Stack *stk);
int Stack_isFull(Stack *stk);
void Stack_push(Stack *stk, char value);
char Stack_pop(Stack *stk);
char Stack_top(Stack *stk);