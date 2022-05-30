#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    static bool cmp(int a, int b) //精髓在这
    {
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }

    string largestNumber(vector<int> &nums)
    {
        string str;
        sort(nums.begin(), nums.end(), cmp);
        for (auto i : nums)
        {
            if (i != 0)
                str += to_string(i);
        }
        if (*(nums.end() - 1) == 0)
            str += "0";
        return str;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 5, 3, 4, 9, 8, 6, 5, 0};
    Solution sol;
    cout << sol.largestNumber(nums);
    return 0;
}
