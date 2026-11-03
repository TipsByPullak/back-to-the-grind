class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;

        while(l <= r)
        {
            mid = l + (r - l)/2;

            if (nums[mid] == target) return mid;

            if (nums[mid] > nums[r])
            {
                if (target < nums[l]) l = mid + 1;
                else r = mid - 1;
            }
            else
            {
                if (nums[mid] < target) r = mid - 1;
                else l = mid + 1;
            }
        }

        if (nums[mid] == target) return mid;
        else return -1;
    }
};
