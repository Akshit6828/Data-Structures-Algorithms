#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Case 1: Using recursion:
// Important: while calling recursive call, dont forget to add return statement else it gona generate random value
/* Thus
 'return BS_Rec(x,mid +1 ,high, e)'
 is important than
 'BS_Rec(x,mid +1 ,high, e)'
*/
int BS_Rec(vector<int> x, int low, int high, int e)
{

    // Base case
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    cout <<"Mid = " << mid << "\n";

    if (e < x[mid])
        return BS_Rec(x, low, mid - 1, e);
    else if (e > x[mid])
        return BS_Rec(x, mid + 1, high, e);
    else
    { // x[mid] == e
        cout << "x[mid] == e" << endl;
        if (mid == 0 || x[mid - 1] != x[mid])
        {
            cout << "Returing mid = " << mid << " \n";
            return mid;
        }

        else
            return BS_Rec(x, low, mid - 1, e);
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
            if (mid == 0 || x[mid - 1] != x[mid]){
                return mid;
            }
            else
                high = mid - 1;
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