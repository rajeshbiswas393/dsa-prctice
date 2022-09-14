/*
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

*/
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    unordered_map<int,int> mp;
    void traversal(TreeNode* root)
    {
        if(root==NULL) return;
        mp[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            int tem=0;
            for(int i=1;i<=9;i++)
            {
                if(mp[i]%2==1)
                    tem++;
            }
            if(tem<=1) ans++;
        }
        traversal(root->left);
        traversal(root->right);
        mp[root->val]--;
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        mp.clear();
        ans=0;
        traversal(root);
        return ans;
    }
};
