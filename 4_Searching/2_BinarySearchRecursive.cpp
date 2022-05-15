#include<bits/stdc++.h>
#include<iostream>
using namespace std;


// 1 2 3 5
// 0 3 -> 1  

// Unsuccesfull search: Log(n)
// Successfull search: BigO(logn)
int binary_search(vector<int> x, int low, int high, int element){

    if(low > high)
        return high + 1;

    int mid = (low + high) >> 1;
    
    if(x[mid]  == element)
        return mid;
    else if(x[mid] > element)
        return binary_search(x,low, mid - 1, element);
    else
        return binary_search(x,mid + 1, high, element);
    

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
    cout<<binary_search(x,0, x.size() - 1, element);
    return 0;
}