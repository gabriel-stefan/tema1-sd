#include <iostream>
#include <vector>

using namespace std;

void MergeSort(vector<int>& nums, int st, int dr)
{
    if(st < dr)
    {
        int m = (st + dr) / 2;
        MergeSort(nums, st , m);
        MergeSort(nums, m + 1 , dr);

        vector<int> tmp(nums.size());
        int i = st, j = m + 1, k = 0;
        while(i <= m && j <= dr )
            if(nums[i] < nums[j])
                tmp[++k] = nums[i++];
            else
                tmp[++k] = nums[j++];
        while(i <= m)
            tmp[++k] = nums[i++];
        while(j <= dr)
            tmp[++k] = nums[j++];
        for(i = st , j = 1 ; i <= dr ; i ++ , j ++)
            nums[i] = tmp[j];
    }
}


int main()
{
    vector<int> nums = {453, 543, 33, 134, 39};
    MergeSort(nums, 0, nums.size()-1);
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << ' ';
    }
    return 0;
}