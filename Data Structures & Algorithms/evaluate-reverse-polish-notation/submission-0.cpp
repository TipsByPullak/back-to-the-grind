class Solution {
public:
    vector<string> ops = {"+", "-", "*", "/"};

    stack<int> stk;

    int calculate(int s1, int s2, string op)
    {
            if (op == "+")
                return s2 + s1;
            else if (op == "-")
                return s2 - s1;
            else if (op == "*")
                return s2 * s1;
            else if (op == "/")
                return s2 / s1;
            else
                return -1;
    }

    int evalRPN(vector<string>& tokens) {
        for(auto it : tokens)
        {
            if (ops.end() == find(ops.begin(), ops.end(), it))
            {
                stk.push(stoi(it));
            }
            else
            {
                int s1 = stk.top();
                stk.pop();

                int s2 = stk.top();
                stk.pop();

                stk.push(calculate(s1,s2, it));
            }
        }

        return stk.top();
    }
};
