class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        ::stack<char> stack;
        ::stack<char> stack2;

        for (int i = 0; i < s.length(); i++)
        {
            char sc = s[i];

            if (sc != '#')
            {
                stack.push(sc);
            }
            else if (!stack.empty() && sc == '#')
            {
                stack.pop();
            }
        }

        for (int i = 0; i < t.length(); i++)
        {
            char tc = t[i];

            if (tc != '#')
            {
                stack2.push(tc);
            }
            else if (!stack2.empty() && tc == '#')
            {
                stack2.pop();
            }
        }

        if (stack == stack2)
            return true;
        else
            return false;
    }
};