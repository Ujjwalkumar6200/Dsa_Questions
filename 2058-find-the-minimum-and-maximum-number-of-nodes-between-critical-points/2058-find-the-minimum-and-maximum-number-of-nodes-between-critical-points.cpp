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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int cnt = 1;
        vector<int> index;
        ListNode* prev = head;
        ListNode* next = head->next;
        while(next!=nullptr){
            if(prev->val < head->val && next->val < head->val) index.push_back(cnt);
            else if(prev->val > head->val && next->val > head->val) index.push_back(cnt);
            prev = head;
            head = head->next;
            next = head->next;
            cnt++;
        }
        if (index.size() < 2)
            return {-1, -1};

        int mn = INT_MAX;

        for (int i = 1; i < index.size(); i++) {
            mn = min(mn, index[i] - index[i - 1]);
        }

        int mx = index.back() - index.front();

        return {mn, mx};
    }
};