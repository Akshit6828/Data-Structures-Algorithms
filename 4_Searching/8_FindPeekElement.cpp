#include <bits/stdc++.h>
#include <iostream>
#define deb(x) cout<<#x<<" = "<<x<<endl;
using namespace std;

int peekElement(vector<int> &x){
    int n = x.size();
        int low = 0, high = x.size() - 1;

        while(low <= high){
        int mid = (low + high) >>1;
        deb(mid);

       /*     
        Condition 1: Checking if we have reachd the first element
        OR
        Cond 2: If we are in the mid way of the array and x[mid -1] <=x[mid]
        AND 
        Cond 3: If we have reached the end of the array
        Cond 4: If not, the peak element then x[mid +1]  < x[mid]
        
        */
        if( (mid ==0 || x[mid-1] <= x[mid]) 
        && 
        (mid == n-1 || x[mid+1] <= x[mid] ))
            return mid;
        else{ // If x[mid] is not a peak

            if(mid > 0 && x[mid - 1] >= x[mid]) // Shortening and checking on left side of array
                high  = mid -1;
            else
                low = mid +1; // Shortening and Checking on right side of array
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cout<<peekElement(x);
    return 0;
} 