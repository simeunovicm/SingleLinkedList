#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SingleLinkedList.h"

void addLast(struct node** head, int_least32_t val)
{
    /* Create a new node */
    struct node* newNode = malloc(sizeof(struct node));
    assert(newNode);
    newNode->value = val;
    newNode->next = NULL;

    /* If head is NULL, it is an empty list */
    if (*head == NULL)
    {
        *head = newNode;
    }
    /* Otherwise, find the last node and add the newNode */
    else
    {
        struct node* lastNode = *head;
    /* Last node's next address will be NULL */
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
    /* Add the newNode at the end of the linked list */
        lastNode->next = newNode;
    }
}

void moveNode(struct node** destRef, struct node** sourceRef)
{
    /* If the source list empty, do nothing */
    if (*sourceRef == NULL)
    {
        return;
    }
    struct node* newNode = *sourceRef;
    assert(newNode != NULL);
    *sourceRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
}

void alternatingSplit(struct node* source, struct node** aRef, struct node** bRef)
{
    /* Split the nodes into `a` and `b` lists */
    struct node* a = NULL;
    struct node* b = NULL;
    struct node* current = source;

    while (current != NULL)
    {
        moveNode(&a, &current);
        if (current != NULL)
        {
            moveNode(&b, &current);
        }
    }
    *aRef = a;
    *bRef = b;
}

void printList(struct node* head)
{
    struct node* temp = head;

    /* Iterate the entire linked list and print the data */
    while (temp != NULL)
    {
         printf("%d\n", temp->value);
         temp = temp->next;
    }
}


void deleteList(struct node** head)
{
    struct node* prev = *head;

    while (*head)
    {
        *head = (*head)->next;
        free(prev);
        prev = *head;
    }
}
