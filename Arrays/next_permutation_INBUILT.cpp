#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    vector<int> x = {1, 2 , 3};
    vector<int> y = {3, 2 , 1};
    vector<int> z = {1, 3, 4 , 2, 5};
    string str = "132";

    cout<<" x = y "<<(x == y)<<endl;
    do
    {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));

    cout<<"-----------------------------"<<endl;
    // printing next permutation of x
    while (next_permutation(x.begin(), x.end()))
    {
        for (auto i : x)
            cout << i << " ";
        cout << endl;
    }

    cout<<"-----------------------------"<<endl;

    // printing next permutation of y
    // NOTE: It will print NOTHING as Y is already the last permutation
    while(next_permutation(y.begin(), y.end()))
    {
        for (auto i : y)
            cout << i << " ";
        cout << endl;
    }


    cout<<"-----------------------------"<<endl;
    sort(z.begin(), z.end());

     while(next_permutation(z.begin(), z.end()))
    {
        for (auto i : z)
            cout << i << " ";
        cout << endl;
    }
}


/*
0010
1111 ^
1101^
0010
1111
*/