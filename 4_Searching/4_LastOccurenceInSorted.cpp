#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* Note in last occurence it will be same as first occurence just we 
will change the following this:
1) Check for mid[x+1] !=x[mid] || mid == x.size() - 1
2) LOW will be updated as (MID + 1) and NOT high as we need to search right side now.

----------------------------------------------------------
FOR ITERATIVE:

if (mid == x.size() - 1 || x[mid + 1] != x[mid])
    return mid;
else
    low = mid + 1;

-----------------------------------------------------------
FOR RECURSIVE:

if (mid == x.size() - 1 || x[mid + 1] != x[mid])
            return mid;
 else
     return BS_Rec(x, mid + 1, high, e);

----------------------------------------------------------
*/


// Case 1: Using recursion:
int BS_Rec(vector<int> x, int low, int high, int e)
{

    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    cout <<"Mid = " << mid << "\n";

    if (e < x[mid])
        return BS_Rec(x, low, mid - 1, e);
    else if (e > x[mid])
        return BS_Rec(x, mid + 1, high, e);
    else
    { 
        cout << "x[mid] == "<<e << endl;
        if (mid == x.size() - 1 || x[mid + 1] != x[mid])
        {
            cout << "Returing mid = " << mid << " \n";
            return mid;
        }

        else
            return BS_Rec(x, mid + 1, high, e);
    }
}

// Iterative Solution:

int BS_Iterative(vector<int> x, int e)
{

    int low = 0, high = x.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (e < x[mid])
            high = mid - 1;
        else if (e > x[mid])
            low = mid + 1;
        else{ // x[mid] == e 
            if (mid == x.size() - 1 || x[mid + 1] != x[mid]){
                return mid;
            }
            else
                low = mid + 1;
        }
    }

    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    int e;
    cin >> e;

    cout<<BS_Rec(x, 0, n - 1, e);
    cout<<" \n ---------------"<<endl;
    cout<<BS_Iterative(x, e);
   

    return 0;
}