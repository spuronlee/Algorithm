#include <iostream>
#include <string>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    while(left <= right){
        int middle = (right + left)/2;
        if (nums[middle] == target) return middle;
        if (target > nums[middle]) left = middle+1;
        else right = middle-1;
    }
    return -1;
    }


int main()
{
    int data[] = {-1,0,3,5,9,12};
    std::vector<int> nums(data,data+6);
    int target = 5;
    int target_index = search(nums, target);
    cout<<target_index<<endl;
    return 0;
}
