//
// Implement the List class
//

#include <stdio.h>
#include "List.h"
#include <stdlib.h>

//
// Inserts a new element with value "val" in
// ascending order.
//
void
List::insertSorted( int val )
{
  	// Complete procedure

	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_value = val;

	if (_head == NULL) {

		_head = newnode;
		_head->_next = NULL;

	}

	else {

		ListNode* temphead = _head;
		ListNode* prev = temphead;

   		if(val < temphead->_value) {

	   		newnode->_next=temphead;
	   		_head=newnode;

	   		return;

	  	}

		while (temphead != NULL && temphead->_value <= val) {

			prev = temphead;
			temphead = temphead->_next;

		}

	      prev->_next = newnode;
		  newnode->_next = temphead;

	}

}

//
// Inserts a new element with value "val" at
// the end of the list.
//
void
List::append( int val )
{
  	// Complete procedure

	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_value = val;

	if (_head == NULL) {

		_head = newnode;
		_head->_next = NULL;

	}

	else {

		ListNode* temphead = _head;
		ListNode* prev = temphead;

		while (temphead != NULL) {

			prev = temphead;
			temphead = temphead->_next;

		}

		prev->_next = newnode;
		newnode->_next = temphead;

	}

}

//
// Inserts a new element with value "val" at
// the beginning of the list.
//
void
List::prepend( int val )
{
  	// Complete procedure

  	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_value = val;

  	if (_head == NULL) {

	  	_head = newnode;
	  	_head->_next = NULL;

  	}

	else {

		ListNode* temphead = (ListNode*)malloc(sizeof(ListNode));
		temphead = _head;
		newnode->_next = temphead;
		_head = newnode;

	}

}

// Removes an element with value "val" from List
// Returns 0 if succeeds or -1 if it fails
int
List:: remove( int val )
{
  	// Complete procedure

	ListNode* node = _head;

	while (node->_next != NULL) {

		if (node->_next->_value == val) {

			node->_next = node->_next->_next;
			return 0;

		}

		node = node->_next;

	}

  	return -1;
}

// Prints The elements in the list.
void
List::print()
{
	// Complete procedure

	ListNode* node = _head;

	while (node != NULL) {

		printf("%d\n", node->_value);

		node = node->_next;

	}

}

//
// Returns 0 if "value" is in the list or -1 otherwise.
//
int
List::lookup(int val)
{
  	// Complete procedure

	ListNode* node = _head;

	while (node != NULL) {

		if (node->_value == val) {

			return 0;

		}

		node = node->_next;

	}

	return -1;
}

//
// List constructor
//
List::List()
{
  	// Complete procedure

	_head = NULL;

}

//
// List destructor: delete all list elements, if any.
//
List::~List()
{
  	// Complete procedure

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	while (node->_next != NULL) {

		free(node);

	}

}

