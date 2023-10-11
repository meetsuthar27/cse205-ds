class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;

        for (int num : nums)
        {
            mp[num]++;
        }

        vector<vector<int>> vec(nums.size() + 1);

        for (const auto &pair : mp)
        {
            vec[pair.second].push_back(pair.first);
        }

        vector<int> result;

        for (int i = vec.size() - 1; i >= 0 && result.size() < k; i--)
        {
            if (!vec[i].empty())
            {
                result.insert(result.end(), vec[i].begin(), vec[i].end());
            }
        }

        return result;
    }
};