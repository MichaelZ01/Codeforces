#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

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

/*
Inorder traversal: left child -> root -> right child

Recursive solution is trivial




*/

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {

        vector<int> ret;

        recurse(root, ret);

        return ret;
    }

    void recurse(TreeNode *root, vector<int> &ret)
    {
        if (root == NULL)
            return;

        recurse(root->left, ret);
        ret.push_back(root->val);
        recurse(root->right, ret);
    }
};