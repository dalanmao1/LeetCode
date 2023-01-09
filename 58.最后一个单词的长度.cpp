/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int right = s.size() - 1;
        while (right >= 0 && s[right] == ' ')
            --right;
        int left = right;
        while (left >= 0 && s[left] != ' ')
            --left;
        return right - left;
    }
};
// @lc code=end
