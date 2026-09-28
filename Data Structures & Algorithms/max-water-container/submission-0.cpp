class Brick
{
    public:
        int index;
        int height;
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Monotonic stack solution

        // vector<int> indices(heights.size());
        // for(int i = 0; i < indices.size(); ++i)
        // {
        //     indices[i] = i;
        // }

        // sort(indices.begin(), indices.end(), [&](int a, int b){ return heights[a] < heights[b];});

        stack<Brick> mStk;
        int maxArea = 0;

        for(int i = 0; i < heights.size(); ++i)
        {
            Brick b;
            b.index = i;
            b.height = heights[i];

            if (mStk.empty() || mStk.top().height <= b.height)
            {
                mStk.push(b);
            }
            else
            {
                Brick c;
                while(!mStk.empty() && mStk.top().height > b.height)
                {
                    c = mStk.top();

                    maxArea = max(maxArea, c.height * (i - c.index));

                    mStk.pop();
                }

                mStk.push(c);
            }
        }

        while(!mStk.empty())
        {
            Brick b = mStk.top();

            maxArea = max(maxArea, b.height * ((int)heights.size() - b.index - 1));
        }

        return maxArea;
    }
};
