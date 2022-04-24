// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sort012(int a[], int n)
    {
        // Using Dutch- Flag Algorithm
        // Note always check with if, else if , else if as using only if, would result in executing multiple cases as a[mid] value is being swapped.
        // Thus its better to use if, else if condition
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high)
        {
            if (a[mid] == 0)
            {
                swap(a[low], a[mid]);
                low++;
                mid++;
            }
            else if (a[mid] == 1)
            {
                mid++;
            }
            else if (a[mid] == 2)
            {
                swap(a[high], a[mid]);
                high--;
            }
        }
    }

    void sort012_CountSort(int A[], int n)
    {
        // Using Counting Sort
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == 0)
                zeroCount++;
            if (A[i] == 1)
                oneCount++;
            if (A[i] == 2)
                twoCount++;
        }
        // All 0's
        int i = 0;
        while (zeroCount > 0)
        {
            A[i++] = 0;
            zeroCount--;
        }

        // Then all the 1s
        while (oneCount > 0)
        {
            A[i++] = 1;
            oneCount--;
        }

        // Finally all the 2s
        while (twoCount > 0)
        {
            A[i++] = 2;
            twoCount--;
        }
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends