/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) 
    {
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * prev = nullptr;
        while(fast && fast->next)
        {
            slow =slow->next;
            fast = fast->next->next;
        }
        ListNode * cur = slow->next;
        slow->next =nullptr;
        while(cur)
        {
            ListNode * fut = cur->next;
            cur->next = prev;
            prev =cur;
            cur =fut;
        }
        
        ListNode * one = head;
        ListNode * two = prev;

        while(two && one)
        {
            ListNode * tmp1 = one->next;
            ListNode * tmp2 = two->next;
            one->next = two;
            two->next =tmp1;
            two =tmp2;
            one =tmp1;
        }


    }
};
