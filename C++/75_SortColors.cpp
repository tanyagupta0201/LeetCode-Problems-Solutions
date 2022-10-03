// Name: Laasya Gupta
// Date: 03/10/2022

class Solution
{
public:
    void sortColors(vector<int> &arr)
    {
        int n = arr.size();

        int low = 0, mid = 0, high = n - 1;

        while (mid <= high)
        {
            switch (arr[mid])
            {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;

            case 1:
                mid++;
                break;

            case 2:
                swap(arr[mid], arr[high--]);
                break;
            }
        }
    }
};