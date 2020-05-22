#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class BinarySearch{
    private:
        int start, end, mid;
    public:
        int binarySearch(vector<int> array, int);
};

int BinarySearch::binarySearch(vector<int> array, int element){
    start = 0;
    end = array.size();
    mid = (start + end) / 2;
    while(start <= end){
        if(array[mid] == element){
            return mid;
        }
        if(array[mid] < element){
            start = mid + 1;
            mid = (start + end) / 2;
        }
        else{
            end = mid - 1;
            mid = (start + end) / 2;
        }
    }    
    return -1;
}
