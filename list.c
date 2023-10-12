#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct List
{
  struct Node *start;
  int size;
};

struct List createList(){
    struct List list;
    list.start = NULL;
    list.size = 0;

    return list;
};

void insertIntoPosition(struct List list, int value, int position){
    struct Node newNode;
    newNode.data = value;

    if (position < 0 || position > list.size){
        return "Posição invalida";
    }

    if (position == 0){
        newNode.next = list.start;
        *list.start = newNode;
    } else {
        struct Node *tempNode;
        tempNode = list.start;


    }
};

