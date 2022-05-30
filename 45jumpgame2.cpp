#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int end = 0, steps = 0;
        ;
        for (int i = 0; i < n - 1; ++i)
        {
            if (nums[i] + i > end)
            {
                end = nums[i] + i;
                ++steps;
            }
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
