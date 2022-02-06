#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
One of the topics I feel I need to work more on is backtracking. Basically
back tracking is a form of brute force where you build adjacent solutions. Kinda
like a tree. This solution reuses the same vector which is pretty clever.

Classic backtracking format:

- Recursive
- Endcase (typically, the length of solution)
- Change current case. (If we change the original, you need to change it back)
- Call recursive function on each of the different new cases
*/

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> ret;

        backtracking(nums, 0, ret);

        return ret;
    }

    void backtracking(vector<int> &nums, int done, vector<vector<int>> &results)
    {

        if (done >= nums.size())
        {
            results.push_back(nums);
            return;
        }

        for (int i = done; i < nums.size(); ++i)
        {
            swap(nums[done], nums[i]);

            backtracking(nums, done + 1, results);

            swap(nums[done], nums[i]);
        }
    }
};