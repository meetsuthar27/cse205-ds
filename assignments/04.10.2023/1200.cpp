class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> ans;
        vector<int> subans;
        int n = arr.size();

        mergeSort(arr, 0, n - 1);

        int mini = INT_MAX;

        for (int i = 0; i < n - 1; i++)
        {
            mini = min((arr[i + 1] - arr[i]), mini);
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (abs(arr[i] - arr[i + 1]) == mini)
            {
                subans.push_back(arr[i]);
                subans.push_back(arr[i + 1]);
                ans.push_back(subans);
                subans.clear();
            }
        }

        return ans;
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