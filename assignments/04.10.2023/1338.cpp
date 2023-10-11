class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        for (int num : arr)
        {
            mp[num]++;
        }

        vector<int> freq;
        for (const auto &pair : mp)
        {
            freq.push_back(pair.second);
        }

        sort(freq.rbegin(), freq.rend());

        int target = arr.size() / 2;
        int ans = 0;
        int remove = 0;

        for (int i = 0; i < freq.size(); i++)
        {
            remove += freq[i];
            ans++;
            if (remove >= target)
            {
                return ans;
            }
        }

        return ans;
    }
};
