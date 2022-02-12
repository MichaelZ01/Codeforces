#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
The classic reversing a linked list.

I did struggle to remember how many pointers I needed but it was good that 
I managed to figure out the building foundation of computer science.

I read a solution that is technically more clean.

1. We only set next in the loop. We can set the loop condition as cur != NULL and
we can avoid the first null check
2. Similarly, if we check cur, then we won't have the extra node at the end that 
we didn't do. 

*/

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == NULL or head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *next = head->next;

        while (next != NULL)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }

        cur->next = prev;
        return cur;
    }
};