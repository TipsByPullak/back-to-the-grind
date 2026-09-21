class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<int> time(position.size(), -1);
        vector<int> index(position.size(), - 1);

        for(int i = 0; i < index.size(); ++i)
        {
            index[i] = i;
        }

        sort(index.begin(), index.end(), [&](int a, int b) {return position[a] > position[b];});

        for(int i = 0; i < position.size(); ++i)
        {
            time[i] = (target - position[i])/speed[i];
        }

        stack<int> monoTonic;

        for(auto it: index)
        {
            if (monoTonic.empty()) monoTonic.push(time[it]);
            else if (monoTonic.top() >= time[it]) continue;
            else monoTonic.push(time[it]);
        }

        return monoTonic.size();

    }
};
