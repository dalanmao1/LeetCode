#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 33. ������ת��������
 * �ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ��ת��
 * ʹ�����Ϊ [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]���±� �� 0 ��ʼ ��������
 * ���磬 [0,1,2,4,5,6,7] ���±� 3 ������ת����ܱ�Ϊ?[4,5,6,7,0,1,2] ������ ��ת�� ������ nums ��һ������ target ��
 * ��� nums �д������Ŀ��ֵ target ���򷵻������±꣬���򷵻�?-1?��
 */

/**���
 * Ŀ�ģ��ھֲ�����ı����ҵ�Ŀ��ֵ
 * ���ߣ�����
 * ��� [l, mid - 1] ���������飬�� target �Ĵ�С���� [\textit{nums}[l],\textit{nums}[mid])[nums[l],nums[mid])��
 * ������Ӧ�ý�������Χ��С�� [l, mid - 1]�������� [mid + 1, r] ��Ѱ�ҡ�
 * ��� [mid, r] ���������飬�� target �Ĵ�С���� (\textit{nums}[mid+1],\textit{nums}[r]](nums[mid+1],nums[r]]��
 * ������Ӧ�ý�������Χ��С�� [mid + 1, r]�������� [l, mid - 1] ��Ѱ�ҡ�
 */

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        /********���ַ�����Ȼ���У���ʧȥ����Ŀ�����壬Ӧ��׷����õ��㷨******
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == target)
                return i;
        }
        return -1;
        ******************************************************************/
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) || (nums[0] > nums[mid]) || (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num{3, 1};
    Solution sol;
    cout << sol.search(num, 1);
    // cout << 1;
    return 0;
}