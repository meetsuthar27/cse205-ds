class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> expected = heights;
        int cnt = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (expected[j] > expected[j + 1])
                {
                    swap(expected[j], expected[j + 1]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (heights[i] != expected[i])
            {
                cnt++;
            }
        }

        return cnt;
    }
};