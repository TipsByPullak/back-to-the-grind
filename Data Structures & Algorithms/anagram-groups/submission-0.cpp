class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string, int> m;

        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());

            if (m.find(s) == m.end())
            {                
                m[s] = result.size();
                result.push_back({strs[i]});
            }
            else
            {
                int index = m[s];

                result[index].push_back(strs[i]);
            }
        }
        return result;
    }

    // bool isAnagram(string s, string t)
    // {
    //     char ll[26];

    //     for (int i = 0; i < s.length(); ++i)
    //     {
    //         ll['z' - s[i]]++;
    //     }

    //     for (int i = 0; i < t.length(); ++j)
    //     {
    //         ll['z' - t[i]]--;
    //     }

    //     for (int i = 0; i < 26; ++i)
    //     {
    //         if (ll[i] != 0) return false;
    //     }

    //     return true;
    // }
};
