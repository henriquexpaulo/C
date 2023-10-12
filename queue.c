#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *start;
    struct Node *end;
    int size;
};

struct Queue createQueue(){
    struct Queue queue;
    queue.start = NULL;
    queue.end = NULL;
    queue.size = 0;

    return queue;
};

void toQueue(struct Queue queue, int value) {
    struct Node newNode;
    newNode.data = value;
    newNode.next = NULL;

    if (queue.end == NULL){
        *queue.start = newNode;
    } else
    {
        *queue.end->next = newNode;
        *queue.end = newNode;
    }
};

int dequeue(struct Queue queue) {
    if (queue.start == NULL){
        return -1;
    }

    struct Node *tempNode = queue.start;
    int value = tempNode->data;
    queue.start = tempNode->next;

    if (queue.start == NULL){
        queue.end = NULL;
    }

    free(tempNode);
    queue.size = queue.size - 1;

    return value;    
};

int queueSize(struct Queue queue) {
    return queue.size;
};

void queueDestroy(struct Queue queue) {
    for (int i = 0; queue.start == NULL; i++){
        dequeue(queue);
    }
};

