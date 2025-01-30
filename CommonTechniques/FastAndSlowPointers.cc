/*
The Fast and Slow Pointers technique, also known as the Tortoise and Hare algorithm, is a two-pointer approach used to solve problems involving cycles in linked lists or arrays. The idea is to use two pointers that move at different speeds to detect cycles or find specific elements.

Example Problem: Detect Cycle in a Linked List
Given a linked list, determine if it has a cycle in it. A cycle occurs when a node's next pointer points back to a previous node, forming a loop.

Fast and Slow Pointers Solution
Here is a C++ implementation to detect a cycle in a linked list using the Fast and Slow Pointers technique:


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

bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    // Create a linked list with a cycle
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle

    if (hasCycle(head))
    {
        cout << "The linked list has a cycle." << endl;
    }
    else
    {
        cout << "The linked list does not have a cycle." << endl;
    }

    // Free the allocated memory (in a real scenario, ensure to handle cycles properly)
    // delete head->next->next->next->next; // This would cause a double free error due to the cycle
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}