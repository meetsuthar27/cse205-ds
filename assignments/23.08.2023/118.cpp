class Solution
{
public:
    vector<int> gen(int row)
    {
        long long ans = 1;
        vector<int> ansrow;
        ansrow.push_back(1);

        for (int i = 1; i < row; i++)
        {
            ans = ans * (row - i);
            ans = ans / i;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;

        for (int j = 1; j <= numRows; j++)
        {
            ans.push_back(gen(j));
        }

        return ans;
    }
};