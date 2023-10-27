#ifndef _SINGLELINKEDLIST_H_
#define _SINGLELINKEDLIST_H_

#include <inttypes.h>

struct node{
    int_least32_t value;
    struct node* next;
};

void addLast(struct node** head, int_least32_t val);
void printList(struct node* head);
void moveNode(struct node** destRef, struct node** sourceRef);
void alternatingSplit(struct node* source, struct node** aRef, struct node** bRef);
void deleteList(struct node** head);


#endif