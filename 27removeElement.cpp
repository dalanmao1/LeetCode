#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 27. �Ƴ�Ԫ��
 * ����һ������ nums?��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ����?val?��Ԫ�أ��������Ƴ���������³��ȡ�
 * ��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
 * Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
��
 */

/**��
 * ˼·��
 *
 */

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int fast = 0, low = 0;
        for (; fast < nums.size(); ++fast)
        {
            if (nums[fast] == val)
            {
                continue;
            }
            else
            {
                nums[low++] = nums[fast];
            }
        }
        return low;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num{0, 1, 2, 2, 3, 0, 4, 2};
    Solution sol;
    cout << sol.removeElement(num, 2) << endl;
    for (auto i : num)
    {
        cout << i << ' ';
    }
    return 0;
}
