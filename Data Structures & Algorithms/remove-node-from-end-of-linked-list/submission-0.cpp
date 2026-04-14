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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        
        int i = 1,N=0;
        ListNode* curr = head;
        while(curr)
        {
            N++;
            curr = curr->next;
        }

        N= N - n;
        if(N ==0)
        {
            return head->next;
        }
        curr = head;
        while (i < N && curr) {
            i++;
            curr = curr->next;
        }
        
        // Remove the node ahead of curr
        if (curr && curr->next) {

            curr->next = curr->next->next;
        }
        return head;

    }
};
