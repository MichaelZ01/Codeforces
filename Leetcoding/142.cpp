#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;    ListNode(int x) : val(x), next(NULL) {}
};


/*
Okay, so this is how I understand it

Slow node travels:

Start to cycleStart (L1)

cycleStart to meetpoint (L2)

some number of cycles (s * C)

Total distance: L1 + L2 + s * C

fast node travels:

Start to cycleStart (L1)

cycleStart to meetpoint (L2)

some larger number of cycles (f * C)

Total Distance: L1 + L2 + f * C

Distance traveled by fast is 2 * distance of slow:

2 ( L1 + L2 + s * C) = L1 + L2 + F * C

L1 + L2 + 2 * s * C = F * C
L1 + L2 = C (F - 2 * s)

F - 2 * s is an integer value, as F and S are integers

This means L1 + L2 is a whole number multiple of C

What does this mean?

In the time it takes to travel L1 + L2, you would travel a whole number times
around the cycle.

How is this useful?

If we have a pointer at the start of the cycle, and it travels L1 + L2 distance,
it's now at the start of the cycle again.

We move a pointer to the meet point which is currently L2 into a cycle

We have another pointer at the start

When the start pointer moves L1, it will be at the cycle start

When we move the meet point pointer L2, it will have moved L1 + L2 into a cycle. 
We don't know how many cycles this is, but we know it has finished a cycle. This means it will once again be at the cycle start.

Thus, after L1 steps, both pointers meet at the cycle start.
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            // Cycle found
            if(slow == fast) {
                fast = head;
                
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
                
            }
        }
        
        return NULL;   
    }
};