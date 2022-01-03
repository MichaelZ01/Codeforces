#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
Fancy bit manipulation solution I found on Discuss

Basically the idea is that ^= (XORing) the same number twice will
not change that number. For one number, it will only be XOR'ed once.

A number XOR by 0 (the orignal result) will just be the number.

I might want to read more about bit manipulation, because I know
how to do it but I'm not too familiar with the application.

I believe this is essentially a bitset.
*/

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        
        return result;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); ++i) {
            if(i != nums[i]) return i;
        }
        
        return nums.size();
    }
};