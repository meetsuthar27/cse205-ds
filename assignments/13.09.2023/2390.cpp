class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> stack;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            if (c != '*')
            {
                stack.push(c);
            }
            else if (!stack.empty() && c == '*')
            {
                stack.pop();
            }
        }

        string snew;
        while (!stack.empty())
        {
            snew += stack.top();
            stack.pop();
        }

        reverse(snew.begin(), snew.end());
        return snew;
    }
};