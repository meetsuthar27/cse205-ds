class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> great;
        stack<int> s;

        for (int num : nums2)
        {
            while (!s.empty() && s.top() < num)
            {
                great[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        vector<int> result;
        for (int num : nums1)
        {
            if (great.find(num) != great.end())
            {
                result.push_back(great[num]);
            }
            else
            {
                result.push_back(-1);
            }
        }

        return result;
    }
};