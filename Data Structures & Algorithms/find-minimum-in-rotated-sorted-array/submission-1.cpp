class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, mid;

        if (nums.size() == 2 || nums.size() == 3)
        {
            return *min_element(nums.begin(), nums.end());
        }

        while(l <= r)
        {
            mid = l + (r - l)/2;

            if (mid == 0)
            {
                if (nums[nums.size() - 1] > nums[mid] && nums[mid + 1] > nums[mid]) break;
                else if (nums[nums.size() - 1] < nums[mid] && nums[mid + 1] > nums[mid])
                {
                    l = mid + 1;
                    r = nums.size() - 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else
            {
                if (nums[mid - 1] > nums[mid] && nums[mid + 1] > nums[mid]) break;
                else if (nums[mid - 1] < nums[mid] && nums[mid + 1] > nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }

        return nums[mid];
    }
};
