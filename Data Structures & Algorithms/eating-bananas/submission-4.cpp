class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MIN;

        for(auto it: piles)
        {
            r = max(r, it);
        }

        int mid, ans;

        while(l <= r)
        {
            mid = l + (r-l)/2;

            int hrs = 0;
            for(auto it: piles)
            {
                hrs += (it + mid - 1LL) / mid;
            }

            if (hrs <= h) 
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;
    }
};
