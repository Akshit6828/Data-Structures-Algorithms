#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
Parameterized Recursion uses cases:
1) When the base case returning the answer is not in our answer, so here we update the passed parameter with our base case.
Eg: For Sub-set problem, our base case is if(i == n) then we insert the subset formed into vector containing all subsets.

2) When we need to print the current state(ith) of any recursion and futher printing (i+1) or (i-1) states are also answer.
Eg: Tower of Hanoii Problem, we print the source, destination of disks into current recursive call.

*/
void Sum_1_to_N(int i, int sum){
    if( i < 1){
        cout<<sum<<endl;
        return;
    }
    
    Sum_1_to_N(i-1, sum + i);
}

void factorial(int i, int fact){
    if(i < 1){
        cout<<fact<<endl;
        return;
    }
    factorial(i - 1, i * fact);
}
int main(){
    int n;
    cin>>n;
    
    cout<<"Sum from 1 to N = ";
    Sum_1_to_N(n, 0);
    cout<<"Factorial of N = ";
    factorial(n, 1);

    return 0;
}