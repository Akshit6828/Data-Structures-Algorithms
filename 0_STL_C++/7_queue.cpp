#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void explainQueue(){
    queue<int> q;
    q.push(1); // 1
    q.push(2); // 2
    q.emplace(3); // 1 2 3

    q.back()+= 5; // Adds 5 to the last element. --> 1 2 8

    q.front(); // Tells the front element --> 1
    q.pop(); // Pops the first element in the queue // 23
    
}
int main(){
    explainQueue();
    return 0;
}