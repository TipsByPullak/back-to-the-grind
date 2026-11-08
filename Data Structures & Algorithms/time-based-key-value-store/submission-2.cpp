class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (m.find(key) == m.end())
        {
            vector<pair<int, string>> v;
            v.push_back({timestamp, value});

            m[key] = v;
        }
        else
        {
            auto v = &m[key];
            v->push_back({timestamp, value});
        }
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end())
        {
            return "";
        }
        else if (m[key].size() == 0)
        {
            return "";
        }
        else
        {
            int l = 0, r = m[key].size() - 1, mid;

            while(l <= r)
            {
                mid = l + (r - l)/2;

                if (m[key][mid].first == timestamp) break;
                else if (m[key][mid].first > timestamp) r = mid - 1;
                else l = mid + 1;
            }

            if (m[key][mid].first > timestamp && mid != 0) return m[key][mid - 1].second;
            else if (m[key][mid].first > timestamp && mid == 0) return "";
            else return m[key][mid].second;
        }
    }
};
