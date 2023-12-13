#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    sort(nums.begin(), nums.end());
    sort(nums.begin() + 2, nums.begin() + 5); // Sorts from ind-2 to ind-5
    sort(nums.begin(), nums.end(), greater<int>()); // SORTS IN DESCENDING ORDER using inbuilt comparator called greater<int>();

    reverse(nums.begin(), nums.end());

    bool found = binary_search(nums.begin(), nums.end(), 3); // Make sure the array is sorted before applying

    auto lower = lower_bound(nums.begin(), nums.end(), 2);
    auto upper = upper_bound(nums.begin(), nums.end(), 2);

    string str = "124";
    do {
        cout<<str<<" ";
    } while (next_permutation(str.begin(), str.end()));
    
    int max_val = *max_element(nums.begin(), nums.end());
    int min_val = *min_element(nums.begin(), nums.end());
    // or we can get its iterator by
    auto max_val_it = max_element(nums.begin(), nums.end());
    auto min_val_it = min_element(nums.begin(), nums.end());

    int sum = accumulate(nums.begin(), nums.end(), 0); // O is the initial sum which we have

    vector<pair<int, int>> vp;
    vp.push_back({1,2});
    vp.push_back({2,4});
    vp.push_back({2,5});

    // Custom sort the vp with following condition
    /**
     * Sort with pair having highest second should come first
     * If 2 pairs have same second, then the one having lowest first should come
     */

    sort(vp.begin(), vp.end(), comp); // comp defined below. Comp is custom comparator
    return 0;
}

bool comp(pair<int, int> &p1, pair<int, int> &p2 ){
    // Building a custom comparator which sorts in our defined manner.
    // NOTE: CUSTOM COMPARATOR ALWAYS RETURN "bool" and return true for a condition when you feel yes, we want this.
    // RETURN FALSE FOR A CONDITION WHEN YOU FEEL IT SHOULD NOT BE LIKE THIS
    if(p1.second < p2.second)
        return true;
    if(p1.second > p2.second)
        return false;

    if(p1.second == p2.second){
        if(p1.first <= p2.first)
            return true;
        else
            return false;
    }
}

/* COMPLEXITIES:
sort: Time Complexity: O(N log N)
reverse:Time Complexity: O(N)
binary_search:Time Complexity: O(log N)
lower_bound and upper_bound:Time Complexity: O(log N)
next_permutation:Time Complexity: O(N)
max_element and min_element:Time Complexity: O(N)
accumulate:Time Complexity: O(N)
*/