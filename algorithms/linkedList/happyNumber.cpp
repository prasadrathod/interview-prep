#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 
Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Approach : 

If we keep on following the loop of adding the square of digit, then at one point it comes back to same place
eg for 20 => 4 - 16 - 37 - 58 - 89 - 145 - 42 - 20

So for this we can use fast pointer and slow pointer concept which we popularly use in linkedlist to find the position in loop(once found we check if that number is 1)
*/

class Solution {
public:
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do{
            slow = sumOfDigitSquare(slow);
            fast = sumOfDigitSquare(sumOfDigitSquare(fast));
        }while(slow != fast);
        
        if(slow == 1) return true;
        return false;
        
    }
    
    int sumOfDigitSquare(int n){
        int sum = 0, digit;
        while(n > 0){
            digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }
};

int main(){
    Solution solution;
    cout<<solution.isHappy(20)<<endl;
    cout<<solution.isHappy(19)<<endl;
}