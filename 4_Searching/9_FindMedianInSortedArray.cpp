#include<bits/stdc++.h>
#include<iostream>
#define deb(x) cout<<#x<<" = "<<x<<endl;
using namespace std;

/*
Case 1: Even Length array
45 65
15 25 35 55
15 25 35 45 55 65

Case 2:
1 3
2
Case 3: Odd Len array:

10 15 19
1 9 14 15 20 23
*/
double median(vector<int> &v1, vector<int> &v2){
    if(v1.size() > v2.size())
        return median(v2, v1);

    int n1 = v1.size(); // 1
    int n2 = v2.size(); // 2

    bool evenLenght = (n1 + n2)%2 == 0 ? true:false; // false

    int low = 0, high = n1;

    while (low <=high){
        deb(low);
        deb(high);
        int mid1 = (low + high) / 2;// 0,1
        int mid2 = (n1 + n2 + 1) / 2 - mid1;// 2,1
        deb(mid1);
        deb(mid2);
                                                        // Case 1 -- Case 2
        int left1 = mid1 == 0 ?   INT_MIN: v1[mid1-1] ;//INT_MIN -- MIN,2 
        int left2 = mid2 == 0 ?   INT_MIN: v2[mid2-1] ; //35 --  3,1
        int right1 = mid1 == n1 ? INT_MAX: v1[mid1] ;//45 -- 2,MAX
        int right2 = mid2 == n2 ? INT_MAX: v2[mid2] ;//55 -- MAX, 3

        deb(left1);
        deb(left2);
        deb(right1);
        deb(right2);

        if(left1 <=right2 && left2 <= right1){
            if( evenLenght )
                return ( (max(left1, left2) + min(right1,right2) )/ 2.0 );
            else
                return (double)max(left1,left2);
        }
        else if( left1 > right2){
            cout<<"left1 > right2\n";
            high = mid1 - 1;
            
            cout<<"high now becomes "<<mid1 -1<<endl;
            
        }
        else{ // left2 > right1
        cout<<"left2 > right1\n";
            low = mid1 + 1;
            cout<<"low now becomes "<<mid1 +1<<endl;
        }
    }
    return 0.0;
    
}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i=0;i<n1;i++)
        cin>>v1[i];
    for(int i=0;i<n2;i++)
        cin>>v2[i];
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    cout<<median(v1,v2);
    return 0;
}