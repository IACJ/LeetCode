/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL){}
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr) {
            return nullptr;
        }

        ListNode *l3 = new ListNode(0);
        ListNode *head = l3;
        int a = 0;
        int b = 0;
        int c = 0;

        while (l1 != nullptr || l2 != nullptr || c !=0)
        {
            if (l1 == nullptr){
                a = 0;
            }
            else
            {
                a = l1->val;
            }
            if (l2 == nullptr)
            {
                b = 0;
            }
            else
            {
                b = l2->val;
            }
            int sum = a + b + c;
            l3->val = sum % 10;
            c = sum / 10;
            if (l1 != nullptr){
                l1 = l1->next;
            }
            if (l2 != nullptr){
                l2 = l2->next;
            }
            if (l1 != nullptr || l2 != nullptr || c != 0) {
                l3->next = new ListNode(0);
                l3 = l3->next;
            }else {
                break;
            }
        }

        return head;
    }
};

// int main() {
//     cout << "Come on!" << endl;
// }
