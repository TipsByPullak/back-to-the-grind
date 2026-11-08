class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> final(nums1.size() + nums2.size());

        int p1 = 0, p2 = 0, pf = 0;

        while(nums1.size() != 0 && nums2.size() != 0 && p1 < nums1.size() && p2 < nums2.size())
        {
            if (nums1[p1] < nums2[p2])
            {
                final[pf++] = nums1[p1++];
            }
            else
            {
                final[pf++] = nums2[p2++];
            }
        }

        if (p1 == nums1.size())
        {
            while(p2 < nums2.size())
            {
                final[pf++] = nums2[p2++];
            }
        }
        else
        {
            while(p1 < nums1.size())
            {
                final[pf++] = nums1[p1++];
            }
        }
        
        int low = (final.size() - 1) / 2.0;
        int high = (final.size()) / 2.0;

        cout << low << endl;
        cout << high << endl;

        return (float)final[low] + (final[high] - final[low])/2.0;
    }
};
