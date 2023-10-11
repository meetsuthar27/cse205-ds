
unordered_map<char, int> mp;
for (int i = 0; i < s.length(); i++)
{
    mp[s[i]]++;
}
vector<pair<int, char>> vect;
for (auto it : mp)
{
    vect.push_back({it.second, it.first});
}
sort(vect.begin(), vect.end());
s = "";
for (int i = vect.size() - 1; i >= 0; i--)
{
    int count = vect[i].first;
    char c = vect[i].second;
    while (count > 0)
    {
        s += c;
        count--;
    }
}
return s;