
#include <stdio.h>
#include <stdlib.h>

// The name says it all on what is going to be done in this file
// Implementing a stack in pure C
// What will come next is algorithmic complexity

// an item ahead of another one with a value of 0 signify an empty slot
// defs

struct Stack *makeStack(int size);
int pushItem(struct Stack *stack, int item);
int popItem(struct Stack *stack);
int isStackFull(struct Stack *stack);
int isStackEmpty(struct Stack *stack);
void showItems(struct Stack *stack);

struct Stack
{
    int *content;
    int top;
    int size;
};

int main(int argc, char *argv[])
{
    struct Stack *myStack = makeStack(4);
    printf(" Pushed item %d \n", pushItem(myStack, 2));
    printf(" Pushed item %d \n", pushItem(myStack, 3));
    printf(" Pushed item %d \n", pushItem(myStack, 4));
    printf(" Popped Item %d \n", popItem(myStack));
    printf(" Popped Item %d \n", popItem(myStack));

    return 0;
}

struct Stack *makeStack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->content = (int *)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}

int pushItem(struct Stack *stack, int item)
{
    // check if stack is full first...
    if (isStackFull(stack))
        return;
    stack->content[++stack->top] = item;
    return item;
}

int popItem(struct Stack *stack)
{
    if (isStackEmpty(stack))
        return;
    return stack->content[stack->top--];
}

int isStackFull(struct Stack *stack)
{
    return stack->top - 1 == stack->size;
}

int isStackEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
