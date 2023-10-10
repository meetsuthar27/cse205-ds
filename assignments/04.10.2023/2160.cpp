class Solution
{
public:
    int minimumSum(int num)
    {
        string str = to_string(num);
        vector<int> ns;

        for (int i = 0; i < 4; i++)
        {
            ns.push_back(str[i] - '0');
        }

        mergeSort(ns, 0, 3);

        string new1, new2;
        for (int i = 0; i < 4; i++)
        {
            if (i % 2 == 0)
            {
                new1 += to_string(ns[i]);
            }
            else
            {
                new2 += to_string(ns[i]);
            }
        }

        int intNew1 = stoi(new1);
        int intNew2 = stoi(new2);

        return intNew1 + intNew2;
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