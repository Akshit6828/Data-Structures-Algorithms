/* Read input from STDIN. Print your output to STDOUT*/
#include<bits/stdc++.h>
#include<iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


/*
Constraints
00<= hh <=23

00<= mm <=59

*/
using namespace std;

void printHour(int total_hour){
    if(total_hour <=9 && total_hour>=0){
        cout<<"0"<<total_hour;
    }
    else{
        cout<<total_hour;
    }
}

void printMinute(int total_min){
    if(total_min <=9 && total_min >= 0)
        cout<<"0"<<total_min;
    else
        cout<<total_min;
}
int main(int argc, char *a[])
{
    //Write code here
    int h, m;
    cin>>h>>m;
    int h1,m1;
    cin>>h1>>m1;

    int total_min = m + m1;
    int total_hour = h + h1;

    int carry_hr = 0;
    // 21 80
    if(total_min > 59){ // 110
        int temp = total_min;
        total_min = total_min%60;
        carry_hr = temp/60;
    }
    total_hour+=carry_hr;

    if(total_hour > 23){
        total_hour = total_hour%24;
    }

    printHour(total_hour);
    cout<<" ";
    printMinute(total_min);

}
