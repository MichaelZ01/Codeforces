#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
Pretty interesting question. I needed the hints and topics. Also my code was 
pretty  ugly.

The idea is this quesiton is greedy. We want to make the smallest partitions 
starting fron the front, and the resulting partition will result in the lowest
number.

We need to determine how small we can make this partition. The requirement
is all the letters in this partition must be exclusively in this partition.
We can check that by storing the last occurance of each letter. If the last
occurance is inside this current partition, we have satisfied the condition.
If not, we simply extend the partition.
*/


class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> res;
        map<char, int> end;
        
        int index = 0;
        for(auto ch: s) {
            end[ch] = index;
            ++index;
        }
        
        
        int i = 0;
        while(i < s.size()) {
            auto ch = s[i];
            int ch_start = i;
            int ch_end = end[ch];
            
            while(i <= ch_end) {
                if(end[s[i]] > ch_end) {
                    ch_end = end[s[i]];
                }
                ++i;
            }
            
            int part_size = ch_end - ch_start + 1;
            res.push_back(part_size);
        }
        
        
        
        return res;
    }
};