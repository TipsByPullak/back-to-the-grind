class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Maintain a min stack of temperature and its day
        stack<pair<int, int>> minStk;
        // keep an integer index, this tracks which day sits at the top of the stack
        int topDay;
        // initialise results array
        vector<int> result(temperatures.size(), 0);

        // reverse iteration on temperatures
        for(int i = temperatures.size() - 1; i >= 0; --i)
        {
            // if stack is empty, push and 0 result
            if (minStk.empty()) minStk.push({temperatures[i], i});
            // else if temperature is lesser than top, set result then push
            else if (temperatures[i] < minStk.top().first)
            {
                result[i] = topDay - i;
                minStk.push({temperatures[i], i});
            }
            // else if temperature is greater than top, pop until less
            else
            {
                while (!minStk.empty() && (temperatures[i] >= minStk.top().first))
                {
                    minStk.pop();
                }

                if (!minStk.empty()) 
                {
                    result[i] = minStk.top().second - i;
                }
                
                minStk.push({temperatures[i], i});
            }

            // index is always top of stack
            topDay = minStk.top().second;
        }

        return result;
    }
};
