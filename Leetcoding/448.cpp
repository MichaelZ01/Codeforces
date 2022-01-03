#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;


/*
Similar quesiton to 268, except this time there are multiple missing.
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        auto res = vector<int>();
        
        auto appear = set<int>(nums.begin(), nums.end());
        
        for(int i = 1; i <= nums.size(); ++i) {
            if(appear.count(i) == 0) res.push_back(i);
        }
        
        return res;
    }
};

/*
Extra condition: No extra space in liner time

Solution is quite clever, I do remember something similar to this in the 
past

The idea is you use the sign of the value to use the same input
array as an boolean array. Something like negative indicates that
the value has been seen.

You can then loop over the boolean array to find which values are 
missing (positive)
*/

