/* Read input from STDIN. Print your output to STDOUT*/
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

using namespace std;

void solveTestCase(){
    long n,g;
    cin>>n>>g;

    vector<long long int> x(g);

    for(long i = 0; i < g;i++)
        cin>>x[i];

    std::stable_sort(x.begin(), x.end());

    long long amount = 0;
    amount = accumulate(x.begin(), x.begin() + n, amount);
    
    cout<<amount<<endl;

}
int main(int argc, char *a[])
{
    //Write code here
    int t;
    cin>>t;

    while(t--){
        solveTestCase();
    }

}
