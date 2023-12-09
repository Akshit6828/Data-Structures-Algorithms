#include<bits/stdc++.h>
using namespace std;
/*
- Works on LIFO
- All operations are O(1) time complexity
*/
void explainStack(){

    stack<int> st;
    st.push(1);
    st.emplace(2);
    st.emplace(3);
    st.emplace(4);
    cout<<"before swapping stacks\n";
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }

    // cout<<st[0]<<endl; // Gives error since we cant access sequently
    st.top(); // top element
    st.pop(); //removes top

    stack<int> s2;
    s2.push(11);
    s2.push(12);
    s2.push(13);

    s2.swap(st); // Swaps stacks s2 with st.

    cout<<"before swapping stacks\n";
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    
    int sz = st.size(); // Size of stack

    while(!s2.empty()){
        cout<<s2.top();
        s2.pop();
    }


}
int main(){
    explainStack();
    return 0;
}