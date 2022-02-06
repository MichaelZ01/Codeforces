#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
Fairly simple question. One thing is I can't remember when calling a class method
function if I need to use self or if I can just call it.
*/

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL and root2 == NULL)
        {
            return NULL;
        }
        if (root1 == NULL)
        {
            return root2;
        }
        if (root2 == NULL)
        {
            return root1;
        }

        root1->val += root2->val;

        root1->left = this->mergeTrees(root1->left, root2->left);
        root1->right = this->mergeTrees(root1->right, root2->right);

        return root1;
    }
};