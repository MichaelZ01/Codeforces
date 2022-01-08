#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;


/*
Similar quesiton to 236.

Using the fact that ^= (XOR) the same number results in the original,
the number that appears once will be XOR'ed once. This will equal
that number
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for(auto num: nums) {
            result ^= num;
        }
        
        return result;
    }
};