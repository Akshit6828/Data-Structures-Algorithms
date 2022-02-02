#include<bits/stdc++.h>
#include<iostream>

int secondLargest(std::vector<int> arr){
	
int secondLargest = -1;
	int largest = arr[0];
	for(int i = 1; i < arr.size(); i++){
    int currentElement = arr[i];
	if(currentElement > largest){ 
			secondLargest = largest;
			largest = currentElement;
		}
	else if(currentElement < largest ){
		if(currentElement > secondLargest)
			secondLargest = currentElement;
}
}

return secondLargest;
	
}


using namespace std;
    int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0; i<n;i++){
        cin>>arr[i];
    }
    cout<<secondLargest(arr);
    
    return 0;
}