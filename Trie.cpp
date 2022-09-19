#include<bits/stdc++.h>
using namespace std;
class Trie{
    public:
    Trie* child[26];
    int num;
    Trie(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        num = 0;
    }
    void insert(string &s){
        Trie* cur = this;
        for(auto x:s){
            int index = x - 'a';
            if(cur->child[index]==NULL) cur->child[index] = new Trie();
            cur = cur->child[index];
            cur->num++;
        }
    }
    int findAns(string &s){
        Trie* cur = this;
        int ans = 0;
        for(auto x:s){
            int index = x - 'a';
            cur = cur->child[index];
            ans += cur->num;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(auto x:words) trie.insert(x);
        vector<int> ans;
        for(auto x:words){
            int y = trie.findAns(x);
            ans.push_back(y);
        }
        return ans;
    }
};
