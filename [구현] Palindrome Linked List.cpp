/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        vector<int> number;
        ListNode* reverseList = head;
        
        for (; reverseList; reverseList = reverseList->next) {
            number.push_back(reverseList->val);
        }
        
        bool answer = true;
        for (auto begin = number.rbegin(); begin != number.rend(); begin++) {
            if (head->val != *begin) { answer = false; break; }
            head = head->next;
        }
        
        return answer;
    }
};
