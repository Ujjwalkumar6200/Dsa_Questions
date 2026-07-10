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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode*temp =head;
        while(temp){
            length++;
            temp=temp->next;
        }
          // Delete head
        if (n == length) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        temp = head;
        for(int i =1;i<length-n;i++)temp=temp->next;
        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;
        return head;

    }
};