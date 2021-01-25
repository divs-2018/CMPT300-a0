// Sample test routine for the list module.
#include <stdio.h>
#include "dlist.h"
#include <stdbool.h>
#include <string.h>
#include <assert.h>

/*
 * Main()
 */
int main(int argc, char** argv)
{
	printf("Starting tests...\n");
	struct nodeStruct *head = NULL;

	// Starting count:
	assert(List_countNodes(head) == 0);
    
	// Create 3 nodes and checking prev links:
	struct nodeStruct* firstNode = List_createNode(0);
    struct nodeStruct* b = List_createNode(1);
    struct nodeStruct* c = List_createNode(2);

	List_insertHead(&head, firstNode);
    assert(head->prev == NULL);
    List_insertHead(&head, b);
    assert(head->next->prev == head);
    List_insertHead(&head, c);
    assert(head->next->next->prev == b);


    assert(List_countNodes(head) == 3);
	assert(List_findNode(head, 0) == firstNode);
	assert(List_findNode(head, 1) == b);
    assert(List_findNode(head, 5) == NULL);


	// Insert tail:
	struct nodeStruct* lastNode = List_createNode(-5);
	List_insertTail(&head, lastNode);
	assert(List_countNodes(head) == 4);
	assert(List_findNode(head, 0) == firstNode);
	assert(List_findNode(head, -5) == lastNode);
	assert(List_findNode(head, 1) == b);

	// Verify list:
	struct nodeStruct *current = head;
	assert(current->item == 2);
	assert(current->next != NULL);
	current = current->next->prev;
	assert(current->item == 2);
	assert(current->next != NULL);
    
    List_deleteNode(&head, b);
    assert(head->item == 2);
    assert(head->next == firstNode);
    assert(head->next->prev = head);
    List_deleteNode(&head, firstNode);
    List_deleteNode(&head, c);
    assert(head->item == -5);
    
    List_deleteNode(&head, lastNode);
    assert(head == NULL);

	// Sort and verify:
    struct nodeStruct* zer = List_createNode(0);
    struct nodeStruct* one = List_createNode(1);
    struct nodeStruct* two = List_createNode(2);
    List_insertTail(&head, one);
    List_insertTail(&head, two);
    List_insertTail(&head, zer);
    List_sort(&head);
	current = head;
	assert(current->item == 0);
	assert(current->next != NULL);
	current = current->next;
	assert(current->item == 1);
	assert(current->next != NULL);
    current = current->next;
    assert(current->item == 2);

    List_deleteNode(&head, zer);
    List_deleteNode(&head, one);
    List_deleteNode(&head, two);
    assert(head == NULL);
    
	printf("\nExecution finished.\n");
	return 0;
}
