#include<bits/stdc++.h>
using namespace std;

int main(){
 set<int> st = {1,2,3,4,2,2,3,4,5};
 
	cout << st.size() <<"\n"; 
    
	// erase functionality 
	// log n 
	st.erase(st.begin()); // st.erase(iterator) // st -> {2, 5}
    cout<<st.max_size() <<"\n"; 
    
    unordered_set<int> s2 = {1,2,3,};
    cout << s2.size() <<"\n"; 
    
	// erase functionality 
	// O(1) average:
    // IF TLE, shift to set
	s2.erase(s2.begin()); 
    cout<<s2.max_size() <<"\n"; 

}