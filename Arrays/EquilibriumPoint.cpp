// { Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n)
    {

        // 1 2 3 5 5 1
        /*
        r = 16, l = 0;
        r = 14 , l = 1
        r = 11, l = 3
        r = 6, r =  6
        Found
        */

        if (n == 1) // Corner Case 1: If onl 1 element is present
            return 1;
        long r_sum = 0;
        for (int i = 1; i < n; i++)
            r_sum += a[i];
        long l_sum = 0;
        int i = 0, j = 1;
        bool equi_found = false;
        int equi_point = 0;
        while (!equi_found)
        {

            if (i < n && j < n)
            {
                if (l_sum != r_sum && i < n && j < n)
                {
                    l_sum += a[i];
                    r_sum -= a[j];
                    i++;
                    j++;
                }
                else
                {
                    equi_point = i + 1;
                    equi_found = true;
                }
            }
            else
            {
                if (!equi_found)
                {
                    equi_point = -1;
                    equi_found = true;
                }
            }
        }

        return equi_point;
    }
};

// { Driver Code Starts.

int main()
{

    long long t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        // taking input n
        cin >> n;
        long long a[n];

        // adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        // calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends