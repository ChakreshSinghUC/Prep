/*
In-place linked list reversal is a common technique used to reverse the nodes of a linked list without using extra space. This technique involves manipulating the pointers of the nodes to reverse the direction of the list.

Example Problem: Reverse a Singly Linked List
Given the head of a singly linked list, reverse the list and return the new head.

In-Place Linked List Reversal Solution
Here is a C++ implementation to reverse a singly linked list in place:
*/

#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *nextTemp = curr->next; // Store the next node
        curr->next = prev;               // Reverse the current node's pointer
        prev = curr;                     // Move prev to the current node
        curr = nextTemp;                 // Move to the next node
    }

    return prev; // prev will be the new head of the reversed list
}

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    ListNode *reversedHead = reverseList(head);

    cout << "Reversed list: ";
    printList(reversedHead);

    // Free the allocated memory
    delete reversedHead->next->next->next->next;
    delete reversedHead->next->next->next;
    delete reversedHead->next->next;
    delete reversedHead->next;
    delete reversedHead;

    return 0;
}