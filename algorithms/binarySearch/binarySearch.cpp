#include <iostream>
#include "binarySearch.h"
using namespace std;

int main(){
    BinarySearch search;
    int element = 3;
    vector<int> array = {1,2,3,4,5};    
    cout<<search.binarySearch(array, element)<<endl;
}