class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {

        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < tickets.size(); i++)
        {
            q.push(make_pair(tickets[i], make_pair(i, 0)));
        }

        int cnt = 1;

        while (!q.empty())
        {

            if (q.front().first == 0)
            {
                int index = q.front().second.first;
                tickets[index] = q.front().second.second;
                q.pop();
            }

            if (q.front().first != 0)
            {
                q.front().first--;
                q.front().second.second = cnt;
                cnt++;
            }

            q.push(q.front());
            q.pop();
        }

        return tickets[k];
    }
};
