class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count_occurence;

        for (auto &it: nums)
        {
            count_occurence[nums]++;
        }

        vector<vector<int>> freq_map(nums.size());

        for (const auto &it: count_occurence)
        {
            freq_map[it.second - 1].push_back(it.first);
        }

        vector<int> result;

        for (int i = nums.size(); i > 0; --i)
        {
            for (auto &it: freq_map[i])
            {
                result.push_back(it);

                if (result.size() == k)
                {
                    return result;
                }
            }
        }

        return result;
    }
};
