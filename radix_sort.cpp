#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMax(vector<int> nums)
{
    int max = INT32_MIN;
    int len = nums.size();
    for(int i = 0; i < len; ++i)
    {
        if(nums[i] > max)
        {
            max = nums[i];
        }
    }
    return max;
}

void countSort(vector<int>& nums, int n, int exp, int base)
{
    
    vector<int> rez(n);
    vector<int> count(base, 0);
 
    for(int i = 0; i < n; ++i)
        count[(nums[i] / exp) % base]++;

    for(int i = 1; i < base; ++i)
        count[i] += count[i - 1];
 
    for(int i = n - 1; i >= 0; --i) {
        rez[count[(nums[i] / exp) % base] - 1] = nums[i];
        count[(nums[i] / exp) % base]--;
    }

    for (int i = 0; i < n; ++i)
        nums[i] = rez[i];
}

void radixsort(vector<int>& nums, int n, int base)
{
 
    int m = getMax(nums);

    for(int exp = 1; m / exp > 0; exp *= base)
        countSort(nums, n, exp, base);
}

int main()
{
    vector<int> nums = { 543, 5444, 66, 9229, 101 };
    int n = nums.size();

    radixsort(nums, n, 10);
    cout << verifSort(nums);
    return 0;
}