#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Helper function from my library
void display_binary(int n){
    cout<<"The Binary Representation of "<<n<<" is :";
    string res = ""; // 5 2 1 0
    if(n == 0)
        res+="0";
        
    while(n>0){
        if(n&1)
            res+="1";
        else
            res+="0";
        n=n>>1; // n = n/2;
    }
    reverse(res.begin(), res.end());
    cout<<res<<endl;
}

/* 
The idea is to iterate till the MSB(Most Significant Bit) and count each time if we find any bit as '1' by doing n&1.
*/
int NaiveSolution(int n){ // TC: O(d) where d = no of bits from 0 to MSB.  SC: O(1)
    int total_setbits = 0;
    while(n > 0){
        if(n&1 != 0)
            total_setbits++;
        n/=2; // n>>1 can also be used;
    }
    return total_setbits;
}

/*
Method 2: USING BRIAN KERNINGAM's ALGORITHM.
This method basically works in O(no. of setbits) in a number.
It says that when we perform (&) AND Operation of N with N-1, the last set bit gets unset and all the trailing 0's after that are converted into 1.

Why N & (N-1) would reset last bit?
Because if you want to form N-1 from N, just unset the last set bit and invert all the rest of bits.

So basically whenever we perform, N & N-1, we end up setting all the bits as 0 from the last set bit on RHS of the last set bit there would be combinations of (0&1) or (1&O) or (0&0) which all are equal to 0.
20 = 10100
19 = 10011
*/

int Optimize_Using_Brian_Kernighan_Algo(int n){ // TC: O(no of setbits) SC: O(1)
    int count = 0; 
    while(n>0){
        n = n&(n-1); // Unset the last set bit and updates the 'n'.
        count++;
    }
    return count;
}

/*
The idea is to set count bits in O(1) time with some preprocessing involved.
We will assume that the integers would be 32 bits only ie.. having 32 bits in binary so we can count setbit query in O(1) time.
PROGRAMMING STYLE: If we have multiple queries regarding the same, we can always use PRE-PROCESSING technique to store the desired result of the answer so that it could save us some time.

Idea 1: 
One idea might be to preprocess the count of set bits of all 32 bits number(0 to 2^32-1) and store into a vector
Note: This vector can be so larger is size and would be a waste of time. Thus, its not a good idea.

Idea 2: 
Count the total set bits for a smaller number of bits (8 bits only or 1 Segment) and use this smaller stored segment(table) to calculate further segment one by one.
So for 32 bits, we will make a table of 256 values (= One Segment of 8 Bits) ONLY.

So, a 32 Bit Num looks something like this 
| ********         ********    32 Bits    ********      ********    |
|**** 8 bits ****|**** 8 bits ****|**** 8 bits ****|**** 8 bits ****|
/  Segment-1     /  Segment-2     /   Segment-3    /  Segment-4     /

Now we can count set bits in Segment-4 using table which we have precomputed.
So we use table to count no of setbits in each segment and then we sum the count.
So F(Seg-1) + F(Seg-2) + F(Seg-3) + F(Seg-4) = Total Set Bits in N.

QUESTION: How do we count set bit in all 4 Segments using the values on only 1 segment(ie Segment-4)
Answer:
Step 1 - If we perform AND(&) of 'N' with 0xff(hexadecimal) or 255(= All 8 BITS SET) we get the count of set bits in Segment-4 as 255 has all 0's in Segment 1,2,3.
Step 2 - Then right shift the number 'N' by 8, and perform step1 again, this time you can get count of set bits in Segment-3.
Step 3 - Then again right shift the number 'N' by 16, and perform step1 again, this time we get count of set bits in Segment-2.
Step 4 - Then again right shift the number 'N' by 24, this time we get count of set bits in Segment-1.
NOTE: In Step 4, We need not to perform AND by 255, as our integer in 32 bit only, so when a 32 bit integer is right shifted by 24, only the bits in the first segment are left whose value is always less than 255(ie as it would be having max 8 bits)

Flow of Pre-Computation:
Step 1:
Eg: N   =   00000001 00000011 00000111 00001111 => 16975631
    255 =   00000000 00000000 00000000 11111111 => 255
    &(And)  ------------------------------------------------
            00000000 00000000 00000000 00001111 => 15 

Recursive Flow: Count+= Table[15] = Table[15/2] + 15&1 --> Table[7/2] + 7&1 --> Table[3/2] + 3&1 --> Table[1/2] + 1&1 --> Table[0] + 0&1.
Count += 4

N>>8

Step 2:
    N   =   00000000 00000001 00000011 00000111 => 66311
    255 =   00000000 00000000 00000000 11111111 => 255
    &(And)  --------------------------------------------
            00000000 00000000 00000000 00000111 => 7

Recursive Flow:Count+= Table[7] = Table[7/2] + 7&1 --> Table[3/2] + 3&1 --> Table[1/2] + 1&1 --> Table[0] + 0&1
Count += 3

N>>16

Step 3: 
    N   =   00000000 00000000 00000001 00000011 => 259
    255 =   00000000 00000000 00000000 11111111 => 255
    &(And)  --------------------------------------------
            00000000 00000000 00000000 00000011 => 3

Recursive Flow:Count+= Table[3] = Table[3/2] + 3&1 --> Table[1/2] + 1&1 --> Table[0] + 0&1
Count += 2

n>>24

Step 4:
    N   =   00000000 00000000 00000000 00000001 = 1;

Recursive Flow: Count+= Table[1] = Table[1/2] + 1&1 = 1
Count += 1

Thus Count = 4 + 3 + 2 + 1 = 8

QUESTION: HOW TO MAKE LOOKUP TABLE?
ANSWER:
If we observe, for any smallest number having least no ofset bits { = 1 (lets say it as old_num) }. 
We can do any two operation:
1) Move this bit(MSB) one step towards left.   (It makes n = old_num * 2)     --> N = 1*2 = 2 
2) Add one bit another towards its left of MSB.(It makes n = old_num * 2 + 1) --> N = 1*2 + 1 = 3

Thus, number 1 can form numbers 2 and 3.

Similarly,
Using operation 1): 2 can form 4 and 6 --> 4 can form 8 and 12 using operation 1 and 2 respectively.
                        AND 
Using operation 2): 3 can form 5 and 7 --> 5 can form 9 and 13 ... and so on.

Thus in General form:
A set of bits of number(i) can form number(i*2) and number(i*2 + 1) from operation 1 and 2 respectively.

NOTE: 
In operation 1, the count of set bits remains same because we are not adding any new set bit. ie.. (countOfSetBits(i) = countOfSetBits(i*2) = countOfSetBits(i*4) ....)
                          BUT
In Operation 2, the count of set bits is increased by 1 from the old_num as we are adding 1 new set bit at the MSB. ie.. (countOfSetBits(i)+1 = countOfSetBits(i*2)) .......

Also we know that 
countOfSetBits(0) = 0

So, countOfSetBits(2) = countOfSetBits(0) +  
So, we can apply tabulation from bottom to top and precompute CountOfSetBits(1)

*/
int Optimize_Using_LookUpTable(int n){
    
}
int main(){
    int n = 31;
    cout<<NaiveSolution(n)<<endl;
    cout<<Optimize_Using_Brian_Kernighan_Algo(n);
    return 0;
}
