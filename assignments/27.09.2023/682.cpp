class Solution
{
public:
    int calPoints(vector<string> &op)
    {
        stack<int> st;
        int sum = 0;

        for (int i = 0; i < op.size(); i++)
        {
            string s = op[i];

            if (s == "C" && !st.empty())
            {

                sum -= st.top();
                st.pop();
            }
            else if (s == "D" && !st.empty())
            {

                int x = st.top() * 2;
                st.push(x);
                sum += x;
            }
            else if (s == "+" && !st.empty())
            {

                int a = st.top();
                st.pop();
                int b = st.top();
                int y = a + b;
                st.push(a);
                st.push(y);
                sum += y;
            }
            else
            {
                int x = stoi(s);
                st.push(x);
                sum += x;
            }
        }

        return sum;
    }
};
