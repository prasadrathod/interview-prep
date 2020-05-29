#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashMap;
        for (string str : strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            if (hashMap.find(temp) != hashMap.end())
            {
                hashMap[temp].push_back(str);
            }
            else
            {
                vector<string> init{str};
                hashMap[temp] = init;
            }
        }

        for (auto const &x : hashMap)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};

int main()
{
    Solution sln;
    vector<string> anagramsList{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> v = sln.groupAnagrams(anagramsList);
    for (auto iterator = v.begin(); iterator != v.end(); iterator++)
    {
        vector<string> y = *iterator;
        for (auto itr = y.begin(); itr != y.end(); itr++)
        {
            cout << *itr << " ";
        }
        cout << endl;
    }
    return 1;
}