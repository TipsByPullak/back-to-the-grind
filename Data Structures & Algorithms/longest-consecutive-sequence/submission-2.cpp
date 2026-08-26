class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ss;

        for(auto it: nums)
        {
            ss.insert(it);
        }

        int maxWindowSize = 0;

        vector<int> parent(nums.size(), 100001);

        for(int i = 0; i < nums.size(); ++i)
        {
            int currWindowSize = 1;

            int next = nums[i] + 1;
            while(ss.find(next) != ss.end())
            {
                ss.erase(next);
                currWindowSize++;
                next++;
            }

           maxWindowSize = max(maxWindowSize, currWindowSize);
        }

        return maxWindowSize;
    }
};
