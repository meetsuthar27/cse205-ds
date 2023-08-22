class Solution
{

    void parenthesis(int open, int closed, int n, string str, vector<string> &ans)
    {
        if (str.length() == 2 * n)
        {
            ans.push_back(str);
        }
        else
        {
            if (open < n)
            {
                parenthesis(open + 1, closed, n, str + '(', ans);
            }
            if (closed < open)
            {
                parenthesis(open, closed + 1, n, str + ')', ans);
            }
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        parenthesis(0, 0, n, "", ans);
        return ans;
    }
};