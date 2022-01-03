#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
Set solution
*/
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        auto seen = set<int>();
        
        for(auto num : nums) {
            if(seen.find(num) != seen.end()) return true;
            seen.insert(num);
        }

        return false;
    }
};

/*
Sort solution
*/
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1]) return true;
        }
        
        return false;
    }
};