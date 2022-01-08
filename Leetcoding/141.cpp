#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
Classic turtoise and hare algo
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(slow != NULL and fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};