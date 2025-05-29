typedef struct Stack Stack;

Stack *Stack_init(int size);
void Stack_free(Stack *stk);
int Stack_isEmpty(Stack *stk);
int Stack_isFull(Stack *stk);
void Stack_push(Stack *stk, int value);
int Stack_pop(Stack *stk);
int Stack_top(Stack *stk);