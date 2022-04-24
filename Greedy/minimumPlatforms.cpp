// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep, dep + n);
    	int platforms = 1, maxPlat = 1;
    	int s = 1,e = 0;
    	while(s<n && e<n){
    	    if(arr[s]<=dep[e]){ // If arrival train came before departure train.
    	        platforms++;// inc plat. as train has arrived
    	        s++; // move to next train
    	    }
    	    else if(arr[s] > dep[e]){ // if arrival train came after dept train
    	        platforms--;// We vacant 1 platform
    	        e++; // Says that this train is departed now, lets move to next departed train
    	    }
    	    
    	    maxPlat = max(maxPlat, platforms);
    	   
    	}
    	return maxPlat;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends