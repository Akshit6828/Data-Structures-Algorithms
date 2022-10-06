/*
Link: https://practice.geeksforgeeks.org/problems/non-repeating-element3958/1

*/

class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
        // Complete the function
        unordered_map<int,int> mp; // Because it's average time is O(1)
        
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        for(int i = 0; i <n; i++){ // Re traversing the array in order to get the elements in the same order of the array it was (ie. sorted)
            if(mp[arr[i]] == 1)
                return arr[i];
        }
        
    } 
  
};