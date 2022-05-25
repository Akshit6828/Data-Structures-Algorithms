#include<bits/stdc++.h>
#include<iostream>
using namespace std;


struct Point
{
    int x, y;
};

bool cmp(Point p1, Point p2){
    return p1.x < p2.x;
}

int main(){
    
    Point arr[3] = { {1,2}, {3, 6}, {10,3}};
    
    sort(arr, arr+3, cmp);
    
    for(auto i: arr){
        cout<<i.x << " "<< i.y<< endl;
    }
    
    return 0;
}