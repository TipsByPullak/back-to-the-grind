class Brick {
    public:
        int height;
        int index;
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        stack<Brick> stk;

        for(int i = 0; i < heights.size(); ++i)
        {
            if (stk.empty() || stk.top().height < heights[i])
            {
                Brick b;
                b.height = heights[i];
                b.index = i;

                stk.push(b);
            }
            else if (stk.top().height > heights[i])
            {
                Brick currB; currB.height = heights[i]; currB.index = i;

                while(!stk.empty() && (stk.top().height > heights[i]))
                {
                    Brick topB = stk.top();

                    maxArea = max(abs(topB.height * (currB.index - topB.index)), maxArea);

                    cout << "max area 1- " << maxArea << endl;

                    currB.index = topB.index;

                    stk.pop();
                }

                stk.push(currB);
            }
        }

        while(!stk.empty())
        {
            Brick topB = stk.top();

            maxArea = max(abs(topB.height * ((int)heights.size() - topB.index)), maxArea);
            cout << "max area 2- " << maxArea << endl;

            stk.pop();
        }

        return maxArea;
    }
};
