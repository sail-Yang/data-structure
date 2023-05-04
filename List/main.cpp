#include <iostream>
#include <vector>
#include "SqList.h"
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right_sum = 0,left_sum = 0;
        int mid_i = 0;
        for(int i=1;i<nums.size();i++){
            right_sum += nums[i];
        }
        if(left_sum == right_sum)
            return mid_i;
        while((left_sum != right_sum) && mid_i<nums.size()){
            mid_i++;
            left_sum+=nums[mid_i-1];
            right_sum-=nums[mid_i];
            if(left_sum == right_sum){
                return mid_i;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums = {2,5};
    Solution solution;
    cout << solution.pivotIndex(nums) << endl;
    
    
    return 0;
}