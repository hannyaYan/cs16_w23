#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"
#include "moreLinkedListFuncs.h"

void addIntToEndOfList(LinkedList *list, int value)
{
  assert(list != NULL); // if list is NULL, we can do nothing.

  Node *p; // temporary pointer

  // TODO:
  // (1) Allocate a new node.  p will point to it.
  p = new Node;

  // (2) Set p's data field to the value passed in
  p->data = value;

  // (3) Set p's next field to NULL
  p->next = NULL;

  if (list->head == NULL)
  {
    // (4) Make both head and tail of this list point to p
    list->head = p;
    list->tail = p;
  }
  else
  {
    // Add p at the end of the list.
    // (5) The current node at the tail? Make it point to p instead of NULL
    list->tail->next = p;

    // (6) Make the tail of the list be p now.
    list->tail = p;
  
  }
}

void addIntToStartOfList(LinkedList *list, int value)
{
  assert(list != NULL); // if list is NULL, we can do nothing.

  // Add code for this.
  // HINT:
  // consider all edge cases such as when list->head is or is not null AND
  // consider all edge cases such as when list->tail is or is not null.
  // Visualizing the problem with a box and pointer diagram can help.

  Node *p = new Node;
  p->data = value;
  p->next = NULL;

  if (list->head == NULL) {
    list->head = p;
    list->tail = p;
  }
  else {
    p->next = list->head;
    list->head = p;
  }
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the largest value.
// You may assume list has at least one element
// If more than one element has largest value,
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node *pointerToMax(LinkedList *list)
{

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.
  assert(list != NULL);
  assert(list->head != NULL);

  // TODO: Insert code here to calculate and return
  //   value of pointer to max element (first one if ties.)

  Node* p = list->head;
  int maxVal = largestValue(list);
  
  if (p->data == maxVal) {
    return p;
  }

  while (p->next && p->next->data != maxVal) {
    p = p->next;
  }

  return p->next; // STUB!  Replace this line with correct code
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the smallest value.
// You may assume list has at least one element
// If more than one element has smallest value,
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node *pointerToMin(LinkedList *list)
{

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list != NULL);
  assert(list->head != NULL);

  // TODO: Insert code here to calculate and return
  //   value of pointer to min element
  //   (first one such value that occurs if there are ties.)
  
  Node* p = list->head;
  int minVal = smallestValue(list);
  
  if (p->data == minVal) {
    return p;
  }

  while (p->next && p->next->data != minVal) {
    p = p->next;
  }

  return p->next; // STUB!  Replace this line with correct code
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the largest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int largestValue(LinkedList *list)
{

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list != NULL);
  assert(list->head != NULL);

  // TODO: Insert code here to calculate and return
  //   largest value in list (which may not be unique).
  
  Node* p = list->head;
  int maxVal = p->data;

  while (p->next != NULL) {
    p = p->next;
    if (p->data > maxVal) {
      maxVal = p->data;
    }
  }

  return maxVal; // STUB!  Replace this line with correct code
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the smallest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int smallestValue(LinkedList *list)
{
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list != NULL);
  assert(list->head != NULL);

  // TODO: Insert code here to calculate and return
  //   smallest value in list (which may not be unique).
  
  Node* p = list->head;
  int minVal = p->data;

  while (p->next != NULL) {
    p = p->next;
    if (p->data < minVal) {
      minVal = p->data;
    }
  }

  return minVal; // STUB!  Replace this line with correct code
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the sum of all values in the list.
// You may assume that list is not NULL
// However, the list may be empty (i.e. list->head may be NULL)
//  in which case your code should return 0.

int sum(LinkedList *list)
{
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list != NULL);

  // TODO: Insert code here to calculate and return
  //   sum of all values in list (0 if there are none).
  Node* p = list->head;
  int sum = p->data;

  while (p->next != NULL) {
    p = p->next;
    sum += p->data;
  }

  return sum; // STUB!  Replace this line with correct code
}
