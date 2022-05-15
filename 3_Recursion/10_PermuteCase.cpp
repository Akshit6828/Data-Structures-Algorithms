#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(string input, string output){
    if(input.size() == 0){
        cout<<output<<" \n";
        return;
    }

    string output1 = output;
    string output2 = output;

    output1.push_back(input[0]);
    output2.push_back(toupper(input[0]));
    input.erase(input.begin() + 0);
    solve(input, output1);
    solve(input, output2);
    return;

}
int main(){
    solve("ab", "");
    return 0;
}