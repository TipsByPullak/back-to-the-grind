class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Brute force solution 1st
        int maxArea = 0;

        for(int i = 0; i < heights.size(); ++i)
        {
            cout << i << " - begin" << endl;
            int h = heights[i];

            // left iteration
            int minHeightLeft = h;
            for(int j = i; j >= 0; --j)
            {
                int newH = heights[j];
                if (newH < minHeightLeft) minHeightLeft = newH;

                int area = (i - j + 1) * minHeightLeft;

                if (area > maxArea) maxArea = area;
            }

            // right iteration
            int minHeightRight = h;
            for(int j = i; j < heights.size(); ++j)
            {
                int newH = heights[j];
                if (newH < minHeightRight) minHeightRight = newH;

                int area = (j - i + 1) * minHeightRight;

                if (area > maxArea) maxArea = area;
            }
        }

        return maxArea;
    }
};
