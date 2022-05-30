#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *p = head, *q, *pre;
        if (head == nullptr || head->next == nullptr)
            return head;
        else
        {
            head = head->next;
            q = p->next;
            p->next = q->next;
            q->next = p;
            pre = p;
            p = p->next;
        }

        while (p != nullptr)
        {
            if (p->next != nullptr)
            {
                q = p->next;
                pre->next = q;
                p->next = q->next;
                q->next = p;
                pre = p;
                p = p->next;
            }
            else
                return head;
        }
        return head;
    }
};
// @lc code=end
