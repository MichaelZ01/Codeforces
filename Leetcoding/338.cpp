#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
Not sure if I would consider this question to be a bit manipulation
question. It was more trying to figure out a pattern for the O(n) sol.

nlog(n) solution is simply enough. log(n) to shift all the bits

*/

class Solution {
public:
    vector<int> countBits(int n) {
        auto ret = vector<int>();
        
        if(n == 0) {
            ret.push_back(0);
            return ret;
        } else if (n == 1) {
            ret.push_back(0);
            ret.push_back(1);
            
            return ret;
        }
        
        ret.push_back(0);
        ret.push_back(1);
        for(int i = 2; i <= n; ++i) {
            if(i % 2 == 0) {
                ret.push_back(ret[i/2]);
            } else {
                ret.push_back(ret[i/2]+1);
            }
        }
        
        return ret;
    }
};