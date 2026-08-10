class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
        {
            return false;
        }

        string s_new = sort(s);
        string t_new = sort(t);

        for(int i = 0; i < s.length(); ++i)
        {
            if (s_new[i] != t_new[i])
            {
                return false;
            }
        }

        return true;
    }
};
