/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <deque>
#include <climits>
using namespace std;

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            
                deque<int> left, right;
                
                while (l1) { left.push_back(l1->val); l1 = l1->next; }
                while (l2) { right.push_back(l2->val); l2 = l2->next; }

                while (left.size() < right.size()) { left.push_front(0); }
                while (left.size() > right.size()) { right.push_front(0); }

                ListNode * answer = new ListNode(INT_MAX);

                int prefix = 0;
                for (int ii = left.size() - 1; ii >= 0; ii--) {
                    const int value = (left[ii] + right[ii]) + prefix;
                    
                    ListNode * temp;
                    if (value > 9) { temp = new ListNode(value % 10); prefix = 1; }
                    else { temp = new ListNode(value % 10); prefix = 0; }

                    if (answer->val == INT_MAX) { answer->val = temp->val; }
                    else { temp->next = answer; answer = temp; }
                }

                if (left.size() == right.size() && prefix == 1) { 
                    ListNode * temp = new ListNode(prefix);
                    temp->next = answer; answer = temp;
                }

                return answer;
        }
};
