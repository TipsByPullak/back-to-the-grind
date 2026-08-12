class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        int totalProduct = 1;
        int totalProductWithoutNil = 1;
        int countOfNils = 0;
        for(auto &it: nums)
        {
            totalProduct *= it;

            if (it == 0)
            {
                countOfNils++;
            }
            else
            {
                totalProductWithoutNil *= it;
            }
        }

        for(auto &it: nums)
        {
            if (countOfNils == 1 && it == 0)
            {
                result.push_back(totalProductWithoutNil);
            }
            else if (it == 0)
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(totalProduct / it);
            }
            
        }

        return result;
    }
};
