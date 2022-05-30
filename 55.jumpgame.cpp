#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int length = nums.size();
        int end = 0;
        int maxstep = 0;
        if (length == 1)
        {
            return 1;
        } //只有一个数的肯定
        else
        {
            if (nums[0] == 0)
            {
                return 0;
            }
        }

        for (int i = 0; i < length - 1; ++i)
        {
            maxstep = max(maxstep, nums[i] + i);
            if (maxstep >= length - 1)
                return 1;
            if (i == end)
            {
                if (maxstep == end)
                    return 0;
                end = maxstep;
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
