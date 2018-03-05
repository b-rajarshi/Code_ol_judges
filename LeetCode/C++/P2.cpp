/*
Leet Code: Problem 2
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s = 0; int r = 0;
        ListNode *head = l2;
        
        while (l1 != NULL && l2 != NULL) {
             s = l1->val + l2->val + r;
             r = s / 10;
             s = s % 10;
             l2->val = s;
             l1 = l1->next;
             l2 = l2->next;
        }
        
        ListNode *temp = head;
            while(temp->next != NULL)
                temp = temp->next;
        
        while (l1 != NULL) {
            s = l1->val + r;
            r = s / 10;
            s = s % 10;
            ListNode *newnode = new ListNode(s);
            temp->next = newnode;
            temp = temp->next;
            l1 = l1->next;
        }
        
        while (l2 != NULL) {
            s = l2->val + r;
            r = s / 10;
            s = s % 10;
            l2->val = s;
            l2 = l2->next;
        }
        
        if ( r != 0) {
         
            ListNode *newnode = new ListNode(r);
            temp->next = newnode;
        }
        return head;
        
    }
};