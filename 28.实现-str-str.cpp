#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {

        if (needle.empty())
            return 0;
        if (haystack.empty())
            return -1;

        int len = -1, i = 0;
        vector<int> b(needle.size() + 1);
        b[i] = len;
        while (i < needle.size())
        {
            while (len >= 0 && needle[i] != needle[len])
                len = b[len];
            i++;
            len++;
            b[i] = len;
        }

        int Index1 = 0;
        int Index2 = 0;
        while (Index1 < haystack.size())
        {
            while (Index2 >= 0 && haystack[Index1] != needle[Index2])
                Index2 = b[Index2];

            Index1++;
            Index2++;
            if (Index2 == needle.size())
                return Index1 - needle.size();
        }
        return -1;
        }
    };
    // @lc code=end
