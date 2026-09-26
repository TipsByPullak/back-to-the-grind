class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.length() - 1;

        while(begin <= end)
        {
            if (!iswalnum(s[begin])) begin++;
            if (!iswalnum(s[end])) end--;

            if (begin > end) break;

            if (tolower(s[begin]) != tolower(s[end]))
            {
                return false;
            }

            begin++;
            --end;
        }

        return true;
    }
};
