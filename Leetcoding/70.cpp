#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
I can immediately tell this is a very simple dp question.

It is esssentially fibonacci's sequence
*/

class Solution {
public:
    int dp[50];
    
    int climbStairs(int n) {
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};