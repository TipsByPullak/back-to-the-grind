class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> count(2001, pair{0,0});
        for (int i = 0; i < nums.size(); ++i)
        {            
            count[nums[i] + 1000].first = nums[i];
            count[nums[i] + 1000].second++;
        }

        vector<int> result;

        sort
        (
            count.begin(), count.end(), [](pair<int, int> p1, pair<int, int> p2)
            {
                return p1.second > p2.second;
            }
        );

        for (int i = 0; i < k; ++i)
        {
            result.push_back(count[i].first);
        }

        return result;
    }
};
