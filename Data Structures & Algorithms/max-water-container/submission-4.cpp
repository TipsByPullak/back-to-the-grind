class Solution {
public:
    int maxArea(vector<int>& heights) {

        // Two pointer solution
        int l = 0; int r = heights.size() - 1;

        int maxWater = 0;

        while(l < r)
        {
            cout << heights[l] << ", " << heights[r] << "|";
            maxWater = max(min(heights[l], heights[r]) * (r - l), maxWater);

            if (l < r) ++l;
            else --r;
        }
        
        return maxWater;
    }
};
