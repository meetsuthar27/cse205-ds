class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> ans;
        map<int, int> mp;

        for (int i = 0; i < arr1.size(); i++)
        {
            mp[arr1[i]]++;
        }

        for (int i = 0; i < arr2.size(); i++)
        {
            if (mp.find(arr2[i]) != mp.end())
            {
                auto it = mp.find(arr2[i]);
                int count = it->second;
                vector<int> v(count, arr2[i]);

                ans.insert(ans.end(), v.begin(), v.end());

                mp.erase(arr2[i]);
            }
        }

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            int ele = it->first;
            int count = it->second;
            vector<int> v(count, ele);

            ans.insert(ans.end(), v.begin(), v.end());
        }

        return ans;
    }
};
