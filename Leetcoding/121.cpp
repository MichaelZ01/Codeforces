#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
Apparently this question is under the dp section, but I 
feel like it's just a greedy
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int curMin = 1e9;
        int curMax = -1;
        int maxProfits = 0;
        
        for(int i = 0; i < prices.size(); ++i) {
            if(prices[i] < curMin) {
                curMin = prices[i];
                curMax = prices[i];
            }
            
            if(prices[i] > curMax) {
                curMax = prices[i];
            }
            
            maxProfits = max(maxProfits, curMax - curMin);
        }
        
        return maxProfits;
    }
};
