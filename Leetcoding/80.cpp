#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
A 2-pointer question. It was useful to work through the logic with pen and paper

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j = 0;    
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[j]) {
                nums[++j] = nums[i];
            } else {
                if(j == 0 or nums[j-1] != nums[i]) {
                    nums[++j] = nums[i];
                }
            }
        }
        
        return j + 1;
    }
};