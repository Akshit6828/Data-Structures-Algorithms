#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int searchBinary(vector<int> x, int e){ // TC(Logn) SC: O(1+)
    int low = 0, high = x.size() - 1;

    
    while(low <= high){
        int mid = (low + high) >> 1;

        cout<<"Mid = "<<mid<<endl;
        if(x[mid] == e)
            return mid;
        
        else if( x[mid] > x[low] ) { // Left half is sorted.

            if(e>=x[low] && e<=x[mid]) // Element lies in the left range which is sorted
                high = mid - 1;
            else // Element lies in right half which is not sorted.
            low = mid + 1;
        }

        else{ // Right half is sorted
            if( e >= x[mid] && e<=x[high]){ // Element lies in the right range which is sorted
                low = mid + 1;
            }
            else // Element lies in the left half which isnt sorted
                high = mid - 1;
        }
    }

    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> x;

    for(int i = 0; i< n; i++){
        int t;
        cin>>t;
        x.emplace_back(t);
    }

    int e;
    cin>>e;
    cout<<searchBinary(x, e);
    return 0;
}