class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MIN;

        for(auto it: piles)
        {
            r = max(r, it);
        }

        while(l < r)
        {
            int mid = floor(l + (r-l)/2);

            int hrs = 0;
            for(auto it: piles)
            {
                hrs += ceil((float)it/(float)mid);
            }

            if (hrs <= h) r = mid;
            else l = mid;
        }

        return mid;
    }
};
