class Solution
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        s.clear();
        for (int i = 0; i < order.size(); i++)
        {
            while (mp[order[i]] > 0)
            {
                mp[order[i]]--;
                s.push_back(order[i]);
            }
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            while (it->second > 0)
            {
                s.push_back(it->first);
                it->second--;
            }
        }
        return s;
    }
};