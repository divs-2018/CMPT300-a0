#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate memory for a node of type struct nodeStruct and initialize
 * it with the value item. Return a pointer to the new node.
 */
struct nodeStruct* List_createNode(int item){
    struct nodeStruct* newnode = malloc(sizeof(struct nodeStruct));
    newnode->item = item;
    newnode->next = NULL;
    return newnode;
};

/*
 * Insert node at the head of the list.
 */
void List_insertHead (struct nodeStruct **headRef, struct nodeStruct *node){
    node->next = *headRef;
    *headRef = node;
}

/*
 * Insert node after the tail of the list.
 */
void List_insertTail (struct nodeStruct **headRef, struct nodeStruct *node){
    if(*headRef == NULL){
        *headRef = node;
    }
    else{
        struct nodeStruct *tail = *headRef;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = node;
    }
}

/*
 * Count number of nodes in the list.
 * Return 0 if the list is empty, i.e., head == NULL
 */
int List_countNodes (struct nodeStruct *head){
    if(head == NULL) return 0;
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

/*
 * Return the first node holding the value item, return NULL if none found
 */
struct nodeStruct* List_findNode(struct nodeStruct *head, int item){
    if(head == NULL) return NULL;
    else{
        while(head != NULL){
            if(head->item == item) return head;
            head = head->next;
        }
        return NULL;
    }
}

/*
 * Delete node from the list and free memory allocated to it.
 * This function assumes that node has been properly set to a valid node 
 * in the list. For example, the client code may have found it by calling 
 * List_findNode(). If the list contains only one node, the head of the list 
 * should be set to NULL.
 */
void List_deleteNode (struct nodeStruct **headRef, struct nodeStruct *node){
    struct nodeStruct *prev = *headRef;
    if(node == *headRef){
        *headRef = (*headRef)->next;
    }
    else{
        while(prev->next != node){
            prev = prev->next;
        }
        prev->next = node->next;
    }
    free(node);
}

/*
 * Sort the list in ascending order based on the item field.
 * Any sorting algorithm is fine.
 */
void List_sort (struct nodeStruct **headRef){
    struct nodeStruct *i, *j; 
    for (i = *headRef; i != NULL; i=i->next){         
       for (j = *headRef; j->next != NULL; j=j->next){  
            if (j->item > j->next->item){ 
                int temp = j->item;
                j->item = j->next->item;
                j->next->item = temp;
            }
       }
    }
}