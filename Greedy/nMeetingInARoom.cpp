// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
    struct meet{
        int start;
        int end;
        int turn;
    };
    public:
    //Function to find the maximum number of meetings that can be performed in a meeting room.
    bool static cmp(struct meet m1, struct meet m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.turn < m1.end) return true;
        return false;
        
    }    
    vector<int> maxMeetings(int start[], int end[], int n){
        struct meet meetings[n];   
        for(int i = 0; i<n;i++){
            meetings[i].start = start[i];
            meetings[i].end = end[i];
            meetings[i].turn = i+1;
        }
        
        sort(meetings, meetings + n, cmp);
        vector<int> meets;
        meets.push_back(meetings[0].turn);
        int last_ending_time = meetings[0].end;
        for(int i = 1; i<n;i++){
            if(meetings[i].start > last_ending_time){
                meets.push_back(meetings[i].turn);
                last_ending_time = meetings[i].end;
            }
        // There is no case for last_ending_time = nextMeetingStartTime;
        // else we could have checked if(meetings[i].start == last_ending_time){
        }
        return meets;
    }
    int possibleMeetings(int start[], int end[], int n){
        struct meet meetings[n];   
        for(int i = 0; i<n;i++){
            meetings[i].start = start[i];
            meetings[i].end = end[i];
        }
        
        sort(meetings, meetings + n, cmp);
        int meets = 1;
       
        int last_ending_time = meetings[0].end;
        
        for(int i = 1; i<n;i++){
            if(meetings[i].start > last_ending_time){
                meets++;
                last_ending_time = meetings[i].end;
            }
        // There is no case for last_ending_time = nextMeetingStartTime;
        // else we could have checked if(meetings[i].start == last_ending_time){
        }
        return meets;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        
        int possibleMeeting = ob.possibleMeetings(start, end, n);
        cout << endl << "Possible Meetings = "<<possibleMeeting << endl;
        vector<int> ans = ob.maxMeetings(start, end, n);
        cout << "Meetings Indexes are = ";
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

      
    }
    return 0;
}  // } Driver Code Ends