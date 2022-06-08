/*
Problem link LC: https://leetcode.com/problems/merge-intervals/
*/

class Solution {
public:
    
    /*static bool sortCmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }*/

    vector<vector<int>> merge(vector<vector<int>>& intervals) { // O(N + NlogN) : O(N) for iterating and NlogN for sorting.
    
        //sort(intervals.begin(), intervals.end(), sortCmp); -> used had it been the times given in opposite order
        sort(intervals.begin(), intervals.end()); // By default the sort will arrange in sorted order of start times. As it sorts based on 1st index.
        vector<vector<int>> uniqueIntervals;
        
       vector<int> currentInterval = intervals[0]; // Lets push the first interval in the current Interval.
        
        for(int i = 0; i< intervals.size(); i++){
            int start_time = intervals[i][0];
            int end_time = intervals[i][1];
  
            if(start_time <= currentInterval[1]) // Merge operation will occur if the start time is <= currentInterval
                currentInterval[1] = max(end_time,currentInterval[1]) ; // Updating the end time of current interval to maxest btween both the currentInterval and ith interval end time.
            else{
                uniqueIntervals.push_back(currentInterval);
                currentInterval = intervals[i];     
                }
        }
        
        uniqueIntervals.push_back(currentInterval); // pushing the last unique interval as it wont be facing any
        return uniqueIntervals;
        
        
    }
};