#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int removeDuplicates(std::vector<int>& arr) { // TC: O(n)
        
        if(arr.size()<1)
            return 0;
        int latestUniqueIndex = 1; // The index where the new unique element will be inserted.
	    for(int i = 1; i<arr.size(); i++){
		    if(arr[i] != arr[latestUniqueIndex - 1]){ 
		        arr[latestUniqueIndex] = arr[i];
                latestUniqueIndex++;
            }
        }
    
        return (latestUniqueIndex);

    }
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0; i<n;i++){
        cin>>arr[i];
    }
    cout<<removeDuplicates(arr);
    
    return 0;
}