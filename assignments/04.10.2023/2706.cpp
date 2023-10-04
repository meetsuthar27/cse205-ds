class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int n = prices.size() - 1;
        int sum = 0;

        mergeSort(prices, 0, n);

        sum = prices[0] + prices[1];

        if (sum <= money)
        {
            return money - sum;
        }

        return money;
    }

    void mergeSort(vector<int> &arr, int l, int h)
    {
        int mid;

        if (l < h)
        {
            mid = (l + h) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, h);
            merge(arr, l, mid, h);
        }
    }

    void merge(vector<int> &arr, int l, int mid, int h)
    {
        vector<int> temp;
        int left = l;
        int right = mid + 1;

        while (left <= mid && right <= h)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= h)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = l; i <= h; i++)
        {
            arr[i] = temp[i - l];
        }
    }
};