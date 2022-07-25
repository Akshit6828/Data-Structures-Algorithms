#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void fun_n_to_1(int n){
    if(n<1)
        return;
    cout<<n<<endl;
    fun_n_to_1(n-1);
}

void Backtrack_N_to_1(int n){
     cout<<"f("<<n<<") is called\n";
    if(n < 1){
        cout<<"N < 1 base case has arrived! Thus ending recursion and returning"<<endl;
        return;
    }
    cout<<"calling f("<<n-1<<")\n";
    Backtrack_N_to_1(n-1);
    cout<<n<<endl;
}

int main(){
    int n;
    cin>>n;
    cout<<"Printing N to 1 without backtracking"<<endl;
    fun_n_to_1(n);
    cout<<"Printing N to 1 With Backtracking"<<endl; // Without using  i--;
    Backtrack_N_to_1(n);
    return 0;
}