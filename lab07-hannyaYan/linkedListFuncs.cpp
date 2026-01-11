#include "linkedListFuncs.h"
#include <stddef.h>
#include <iostream>
using namespace std;

/*All functions MUST be implemented recursively
* No credit will be given for non-recursive solutions
*/


//head: ptr to a Node * which is the head of a linked list
//return sum of all values in linked list using a recursive approach
//if head is null return 0
int recursiveSum(Node* head) {
  Node* p = head;

  if (p == NULL) {
    return 0;
  }

  if (p->next == NULL) {
    return p->data;
  }
  else {
    return (p->data + recursiveSum(p->next));
  }
}


//head: ptr to a Node* which is the head of a linked list
//return the largest value in the linked list using a recursive approach
//you may assume the list has at least one element
int recursiveLargestValue(Node* head) {
  Node* p = head;

  if (p->next == NULL) {
    return p->data;
  }
  else {
    if (p->data > recursiveLargestValue(p->next)) {
      return p->data;
    }
    else {
      return (recursiveLargestValue(p->next));
    }
  }
}


/*Given the head of a linked list, find and return the kth node of the linked list
 *Assume head is the first node
 *If k is larger than the size of the linked list, return NULL
 *
 * Example: n1 -> n2 -> n3 -> n4 -> n5, k = 3
 * Return &n3
 */
Node* recursiveFindKthNode(Node *head, int k){
  Node* p = head;
  if (p == NULL) {
    return NULL;
  }
  else if (k == 1) {
    return p;
  }
  else {
    return recursiveFindKthNode(p->next, k-1);
  }
}


/*Given the head of a linked list, delete the kth node from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n2 and return &n1
* New list should look like this: n1 -> n3 -> n4
*/
Node* recursiveDeleteKthNode(Node *head, int k) {
  if (k == 1) {
    Node* p = head->next;
    delete(head);
    return p;
  }
  else {
    head->next = recursiveDeleteKthNode(head->next, k-1);
    return head;
  }
}


/*Given the head of a linked list, delete the first k nodes from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n1, n2 and return &n3
*/
Node* recursiveRemoveKFromFront(Node *head, int k) {
  if (k == 0) {
    return head;
  }
  else {
    Node* p = head->next;
    delete(head);
    return recursiveRemoveKFromFront(p, k-1);
  }
}


/*Given two linked lists, return a NEW linked-list where each element is the sum of the corresponding elements of the input
 * If a linked list has a longer length than the other, treat the corresponding NULL element as a node with value 0
 * 
 * Example: List 1: 1 -> 2 -> 3 -> 12
 * 	    List 2: 4 -> 5 -> 6
 * Return &head of the linked list 5 -> 7 -> 9 -> 12
 */
Node* recursiveElementwiseSum(Node *head1, Node *head2) {
  Node* p = new Node;

  if (head1 == NULL && head2 == NULL) { 
    return NULL;
  }
  else if (head1 == NULL) {
    p->data = 0 + head2->data;
    p->next = recursiveElementwiseSum(NULL, head2->next);
    return p;
  }
  else if (head2 == NULL) {
    p->data = head1->data + 0;
    p->next = recursiveElementwiseSum(head1->next, NULL);
    return p;
  }
  else {
    p->data = head1->data + head2->data;
    p->next = recursiveElementwiseSum(head1->next, head2->next);
    return p;
  }
}


/*BONUS: Given the heads of two linked lists, splice the second linked list into the first, alternating elements from each list
 * 
 * The first element of the newly arranged linked list will always be head1, unless head1 is NULL (in which case just return head2)
 *
 * You MUST modify the linked lists themselves and DO NOT create another list or any new nodes
 *
 * Example: List 1: 1->2->3, List 2: 4 -> 5 -> 6
 * Return &head of 1 -> 4 -> 2 -> 5 -> 3 -> 6
 */
Node* recursiveSplice(Node *head1, Node *head2) {
  if (head1 == NULL) {
    return head2;
  }
  if (head2 == NULL) {
    return head1;
  }

  if (head1->next == NULL && head2->next == NULL) {
    head1->next = head2;
    return head1;
  }
  else {
    head2->next = recursiveSplice(head1->next, head2->next);
    head1->next = head2;
    return head1;
  }
}
