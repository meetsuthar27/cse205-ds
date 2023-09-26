class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int cs, rs = 0;
        int ce = matrix[0].size() - 1;
        int re = matrix.size() - 1;

        vector<int> v1;

        while (ce >= cs && re >= rs)
        {
            for (int i = cs; i <= ce; i++)
            {
                v1.push_back(matrix[rs][i]);
            }
            rs++;
            if (rs > re)
            {
                break;
            }

            for (int i = rs; i <= re; i++)
            {
                v1.push_back(matrix[i][ce]);
            }
            ce--;

            if (cs > ce)
            {
                break;
            }

            for (int i = ce; i >= cs; i--)
            {
                v1.push_back(matrix[re][i]);
            }
            re--;

            if (rs > re)
            {
                break;
            }

            for (int i = re; i >= rs; i--)
            {
                v1.push_back(matrix[i][cs]);
            }
            cs++;
            if (cs > ce)
            {
                break;
            }
        }

        return v1;
    }
};