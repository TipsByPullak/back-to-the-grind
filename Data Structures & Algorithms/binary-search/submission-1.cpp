class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l < r - 1)
        {
            int mid = l + (r - l)/2;

            if (nums[mid] == target) return mid;

            if (target > nums[mid]) l = mid;
            else r = mid;
        }

        return -1;
    }
};
