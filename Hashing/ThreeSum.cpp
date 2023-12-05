class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) // Making sure we dont pick the next 'i' index value same as previous
                continue;
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k]; // Important to declare sum here bcz for each i at constant place, j and k will keep moving until the required triplet is found. So we need to make sure the sum also gets updated accordingly.
                if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                { // We found a triplet
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    ans.push_back(triplet);

                    j++; // Okay now move j to right to find another triplet
                    k--; // Okay now move k to left to find another triplet

                    while (j < n && nums[j] == nums[j - 1]) // Moving j to right so that its previous value is not same as new value. Also including check j <n so that we dnt go outside the array
                        j++;
                    while (k > 0 && nums[k] == nums[k + 1]) // Moving k to left so that its previous value is not same as new value. Also including check k>0 so that we dnt go outside the array
                        k--;
                }
            }
        }
        return ans;
    }
};