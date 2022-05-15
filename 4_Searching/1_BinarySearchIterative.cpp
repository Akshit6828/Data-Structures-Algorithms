#include<bits/stdc++.h>
#include<iostream>
using namespace std;


// 1 2 3 5
// 0 3 -> 1  
int binary_search(vector<int> x, int element){

    int low = 0, high = x.size() -1 ;
    while(low <=high){
        int mid = (low + high) >> 1;
        if(x[mid] == element)
        return mid;
        else if(x[mid] > element)
        high = mid - 1;
        else
        low = mid + 1;
    }
    return high + 1; // Returning high + 1 if element not found and its the right position to enter.

}

int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i = 0; i< n; i++){
        cin>>x[i];
    }

    sort(x.begin(), x.end());

    int element;
    cin>>element;
    cout<<binary_search(x,element);
    return 0;
}