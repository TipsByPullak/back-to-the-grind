class Solution {
public:

    void getResult(vector<vector<int>> &result, vector<int> &search, int target)
    {
        int l = 0, r = search.size() - 1;

        while(l < r)
        {
            if (search[l] + search[r] > target) r--;
            else if (search[l] + search[r] < target) l++;
            else
            {
                result.push_back({target, search[l], search[r]});
                return;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.size() == 3)
        {
            if (nums[0] + nums[1] + nums[2] == 0)
            {
                result.push_back(nums); 
            }

            return result;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; ++i)
        {
            vector<int> search(nums.begin() + i + 1, nums.end());

            getResult(result, search, nums[i]);
        }

        return result;
    }
};
