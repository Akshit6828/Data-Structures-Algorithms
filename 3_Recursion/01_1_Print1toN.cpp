#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*

Imp points of recursion:
1) Base condition is an answer to a the smaller/larger problem which we know.
2) We can always generate a formulae by recursive solutions.

When to apply backtracking??
Case 1) 
If we are at initial state (or beginning of our algorithm say 0th index) and we know that
we will be able to generate the current state ans if we know all (i+1) th indexes answer.

Case 2) 
If we are at last state (or ending of our algorithm say nth index) and we know that
we will be able to generate the current state ans if we know all (i - 1) th indexes answer.
Eg: fibonaci(N) can be easily computed if we know fibonacci(n - 1) and fibonacci(n-2);

*/

void fun1toN(int i, int n){ // TC: O(n) as we calling n functions. SC: O(n) as we put at max N fun calls() into stack.
    if(i > n)
        return;
    cout<<"printing "<<i<<endl;
    fun1toN(i+1,n);
}

// Try running the program and then see the output to see the backtracking working
void Backtrack_1_to_N(int n){ // TC: O(n) Sc: O(n)
    cout<<"f("<<n<<") is called\n";
    if(n < 1){
        cout<<"N < 1 base case has arrived! Thus ending recursion and returning"<<endl;
        return;
    }
      
    cout<<"calling f("<<n-1<<")\n";
    Backtrack_1_to_N(n-1);
    cout<<n<<endl;
}
int main(){
    int n;
    cin>>n;
    cout<<"printing 1 to N without backtracking"<<endl;
    fun1toN(1,n);
    cout<<"printing 1 to N With Backtracking"<<endl; // Without using i++.
    Backtrack_1_to_N(n);
    return 0;
}