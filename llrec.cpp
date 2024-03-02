#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    // what were doing
    // pivot is the val that we need to split the nodes into 2 lists around
    //(smaller than pivot or larger than pivot)

    // base case:
    if (head == NULL) // if list empty (or empty bc at end of list)
    {
        smaller = NULL; // head of list 1 is null
        larger = NULL;  // head of list 2 is null
        return;
    }
    // head recursion
    //  recursive call to go into the end of list (all the way deep):
    Node *NextNode = head->next;
    llpivot(NextNode, smaller, larger, pivot);

    // process
    if (head->val <= pivot)
    {                         // if heads value is less than pivot
        head->next = smaller; // head now points to the curr val held in front of smlr
        smaller = head;       // head now becomes the front of smlr (so schooching the prev smaller down one)
    }
    else
    {
        head->next = larger; // smae thing for larger
        larger = head;
    }
}

Node *llfilter(Node *head, Comp pred) // this function removes elements form the list that match certain criteria (predicate)
{
    // base case: if list empty or end of list
    if (head == NULL)
    {
        return NULL;
    }
    // if head satifies predicate 'pred(head->val) == true'
    // remove it
    // if not go to next node, put back in list

    if (pred(head->val))
    {
        Node *NextNode = head->next;     // new node holds next node after head
        delete head;                     // delete head from list
        return llfilter(NextNode, pred); // go to next node
    }
    else
    {
        head->next = llfilter(head->next, pred); // go down into next node
        return head;                             // return current head back to list bc doesnt match
    }
}