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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int n = lists.size();

        while (n > 1) {
            int mid = (n + 1) / 2;

            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwo(lists[i], lists[i+mid]);
            }

            n = mid;
        }

        return lists[0];
    }

private:
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val <= b->val) {tail->next = a; a = a->next;}
            else                  {tail->next = b; b = b->next;}
            tail = tail->next;
        }

        tail->next = a ? a : b;
        return dummy.next;
    }
};
