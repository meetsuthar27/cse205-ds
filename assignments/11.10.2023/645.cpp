class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        unordered_set<int> numset;

        int sum = nums.size() * (nums.size() + 1) / 2;
        int target = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum -= nums[i];
            numset.insert(nums[i]);

            if (!target && numset.size() == i)
            {
                target = nums[i];
            }
        }

        return {target, (target + sum)};
    }
};