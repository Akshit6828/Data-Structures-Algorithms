#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int n)
    {
        // Observations:
        /*
        1) 1st Element should be smaller than the 2nd Element
        2) Array should follow: a<b>c<d>e
        */

        char relation = '<';
        // 1 < 2 > 3 < 4 > 5 < 6
        for (int i = 0; i < n - 1; i++)
        {

            if (relation == '<')
            {

                if (arr[i] > arr[i + 1])
                    swap(arr[i], arr[i + 1]);

                relation = '>';
            }
            else
            {

                if (arr[i] < arr[i + 1])
                    swap(arr[i], arr[i + 1]);

                relation = '<';
            }
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}