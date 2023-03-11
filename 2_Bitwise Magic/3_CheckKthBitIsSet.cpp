#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Given a number 'n', in decimal. Tell that if kth bit of 'n' in binary is set(=1) or not(=0)
// K will always be less than no of bits of the number. ie k <= floor( log2(n) ). Because log(n) is the no of bits in binary


/*
How to approach solution:
1) How do we check if 1st bit is set or not?
- We do (n&1) and if (n&1)!= 0 it means it's set. 
- This is how we can even check if the  is odd or even.

Now how do we check if only the kth bit is set or not?
- We do '&'(AND) operation of "n" with a number who's only kth bit is set( lets say: kthSetBitNum).

How to find kthSetBitNum?
Way 1: if we want a number who's kth bit is set, we can perform 1<<(k-1). (1 left shifted by k-1 times -> if following 1st bit at first position(1 based indexing) and (1<<k) -> if following 0 based indexing))
Way 2: kthSetBitNum = 2^(k-1) = pow(2, k-1);

Way 1 is efficient because it involves bit operations which is better efficient.

Note: Bitwise Shift operator take O(1) time. Why?
- Bitwise operators map directly to CPU instructions. 
The cpu has 'hardware' to perform bitwise operations on certain data types in constant time. The time depends on the data type and memory addressing mode. I think somewhere in an intel manual, can find the cycles it would take for each opcode
- Complexity, with the O(…) notation, is an asymptotic characterization of the time an algorithm takes when the input size becomes larger and larger. 
It is meaningless for algorithms that can take only a finite number of inputs. 
'<<' can take 2^32 * 32 different inputs, hence a finite number of inputs, therefore it is constant-time (O(1)).

*/

void BruteForce(int n, int k){  // TC: O(k), SC: O(1)
    int kthSetBitNum = 1;
    for(int i = 0; i < (k-1); i++)
        kthSetBitNum = kthSetBitNum*2;

    if( (n & kthSetBitNum) != 0)
        cout<<"Set"<<endl;
    else
        cout<<"Not set"<<endl;
}

void Optimize_Using_LeftShift(int n, int k){ // TC: O(1), SC: O(1)
    int kthSetBitNum;
    // kthSetBitNum = pow(2, k-1); // Using Way2 but commenting it because its not optimal
    kthSetBitNum = 1<<(k-1); // = 2^(k-1) and is O(1) Operation as bitwise shift is performed by the hardware and it depends on the CPU Clock Cycle and not dependent on time or n.
    // Note we can also shift "n", k bits towards right as explained in function next to it.
    if( (n & kthSetBitNum) != 0)
        cout<<"Set"<<endl;
    else
        cout<<"Not set"<<endl;

}

void Optimize_Using_RightShift(int n, int k){ // TC: O(1), SC: O(1)
    n = n>>(k-1);
    if( (n & 1) != 0)
        cout<<"Set"<<endl;
    else
        cout<<"Not set"<<endl;
}

int main(){
    int n = 35, k = 6; //  1 0 0 0 1 1 
    BruteForce(n,k);
    Optimize_Using_LeftShift(n,k);
    Optimize_Using_RightShift(n,k);
    return 0;
}