#include <iostream>
#include <string>
#include <vector>
using namespace std;


int maxSubArray(vector<int>& nums)
{
    int sum = INT_MIN;
    int b = INT_MIN;

    int besti = 0;
    int bestj = 0;
    int begin_num = 0;

    int size_array = nums.size();
    for (int i=0; i<size_array;i++)
    {
        if (b>0) b+=nums[i];
        else{
            b = nums[i];
            begin_num = i;
        }
        if (b>sum){
            sum = b;
            besti = begin_num;
            bestj = i;
        }
    }
    cout<<"start:"<<besti<<",end:"<<bestj<<"."<<endl;
    return sum;

}


int main()
{
    int va[]={-1};
    std::vector<int> nums(va,va+1);
    int sum = maxSubArray(nums);
    cout << sum << endl;
    return 0;
}
