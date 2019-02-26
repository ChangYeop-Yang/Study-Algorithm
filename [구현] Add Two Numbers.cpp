/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <climits>
using namespace std;

class Solution {
    
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            
            vector<int> left, right;
            while (l1) { left.push_back(l1->val); l1 = l1->next; }
            while (l2) { right.push_back(l2->val); l2 = l2->next; }
            
            while (left.size() < right.size()) { left.push_back(0); }
            while (left.size() > right.size()) { right.push_back(0); }
            
            ListNode * head = new ListNode(INT_MAX);
            ListNode * answer = new ListNode(INT_MAX);
            
            int prefix = 0;
            for (int ii = 0; ii < left.size(); ii++) {
                const int value = (left[ii] + right[ii]) + prefix;
                
                ListNode * temp;
                if (value > 9) { temp = new ListNode(value % 10); prefix = 1; }
                else { temp = new ListNode(value % 10); prefix = 0; }
                
                if (answer->val == INT_MAX) { answer->val = temp->val; head = answer; }
                else { answer->next = temp; answer = answer->next; }
            }
            
            if (left.size() == right.size() && prefix == 1) { answer->next = new ListNode(prefix); }
            
            return head;
        }
};
