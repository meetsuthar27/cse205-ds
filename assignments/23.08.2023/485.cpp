class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int cnt = 0;
        vector<int> cntv;
        int max_elem = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }

            max_elem = max(max_elem, cnt);
        }

        return max_elem;
    }
};