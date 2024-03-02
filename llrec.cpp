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