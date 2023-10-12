#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
    int size
};

struct Stack createStack() {
    struct Stack stack;
    stack.top = NULL;
    stack.size = 0;

    return stack;
};

void stackUp(struct Stack stack, int value){
    struct Node newNode;
    newNode.data = value;
    newNode.next = stack.top;
    *stack.top = newNode;
    stack.size = stack.size + 1;
};

int unstack(struct Stack stack) {
    if (stack.top == NULL){
        return -1;
    };

    struct Node *tempNode = stack.top;
    int value = tempNode->data;
    stack.top = tempNode->next;
    free(tempNode);
    
    stack.size = stack.size - 1;

    return value;
};

int stackLength(struct Stack stack){
    return stack.size;
}

void destroyStack(struct Stack stack){
    for (int i = 0; stack.size != NULL; i++){
        unstack(stack);
    };
}