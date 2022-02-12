#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
Another backtracking question.

The mistake I was making is how I create the next recursion call.

The thing I was worried about was how would I prevent duplicate subsets from
being included. The way is to make sure the subsets are always increasing in 
index order. You do this by maintaining a start point. I incorrectly called my 
int len, it should be called start. We only consider adding numbers past the 
start. The avoid us backtracking backwards which would lead to duplciates.

The start point should be the position of the last number we added. So if we just
added the number at index i, our next start should be at index i + 1.

*/

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> ret = vector<vector<int>>();
        auto cur = vector<int>();

        backTrack(0, cur, nums, ret);

        return ret;
    }

    void backTrack(int len, vector<int> &cur, vector<int> &nums, vector<vector<int>> &ret)
    {

        ret.push_back(cur);

        for (int i = len; i < nums.size(); ++i)
        {
            cur.push_back(nums[i]);
            backTrack(i + 1, cur, nums, ret);
            cur.pop_back();
        }
    }
};