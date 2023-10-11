class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums[nums.size() - k];
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