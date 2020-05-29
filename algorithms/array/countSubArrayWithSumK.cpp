// Link to question : https://leetcode.com/problems/subarray-sum-equals-k/
// Difficulty : MEDIUM
// Given an array of integers and an integer k, you need to find the total number of 
// continuous subarrays whose sum equals to k.

// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2

// // Approach : 
// 1) We will compute the presum of the array.
// 2) We will iterate over each element in presum.
// 3) As we know we need to find the subarray with sum k, idea here is find whether 
// need = presum[i] - k is already present in presum or not.


#include <bits/stdc++.h> 
using namespace std; 
  
int findSubarraySum(int arr[], int n, int sum) { 
    unordered_map<int, int> prevSum; //count of prefix sum encountered earlier

    int res = 0; 
    int currsum = 0; 
    prevSum[currsum]++;
    for (int i = 0; i < n; i++) { 
      currsum += arr[i];
      int need = currsum - sum;
      res += (prevSum[need]);
      prevSum[currsum]++; 
    }
    return res; 
} 
  
int main() { 
    int arr[] = {1,2,3,3,3,2}; 
    int sum = 3; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << findSubarraySum(arr, n, sum)<<endl; 
    return 0; 
} 
