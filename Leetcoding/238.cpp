#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
1 2 3 4 5 6 7 8 
      *
      
1 * 2 * 3 + 5 * 6 * 7 * 8

1 * 2 * 3 = prefix[3]
5 * 6 * 7 * 8 = suffix[5]

Pretty sure I've seen this question before but on the other
hand I'd completely forgotten how to do it and figured it 
out.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix[100005];
        int suffix[100005];
        
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            prefix[i] = prefix[i-1] * nums[i];
        }
        
        suffix[nums.size() -  1] = nums[nums.size() - 1];
        for(int i  = nums.size()-2; i >= 0; --i) {
            suffix[i] = suffix[i +1] * nums[i];
        }
        
        vector<int> sol;
        

        for(int i = 0; i < nums.size(); ++i) {
            if(i == 0) {
                sol.push_back(suffix[i+1]);
            } else if(i == nums.size() - 1) {
                sol.push_back(prefix[i-1]);
            } else {
                sol.push_back(prefix[i-1] * suffix[i+1]);
            }
            
        }
        
        
        return sol;
    }
};