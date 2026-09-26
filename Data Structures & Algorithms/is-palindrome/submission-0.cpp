class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.length() - 1;

        while(begin <= end)
        {
            cout << s[begin] << " " << s[end] << endl;
            if (!iswalnum(s[begin])) begin++;
            if (!iswalnum(s[end])) end--;

            cout << s[begin] << " " << s[end] << endl;

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
