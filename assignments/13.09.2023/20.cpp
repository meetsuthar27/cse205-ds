class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
            }
            else if (c == ')' && !stack.empty() && stack.top() == '(')
            {
                stack.pop();
            }
            else if (c == ']' && !stack.empty() && stack.top() == '[')
            {
                stack.pop();
            }
            else if (c == '}' && !stack.empty() && stack.top() == '{')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }

        return stack.empty();
    }
};
