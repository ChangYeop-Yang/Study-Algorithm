/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
#include <algorithm>
using namespace std;

#define INT_PAIR pair<TreeNode*, int>
#define INT_VECTOR vector<int>

class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            
            queue<INT_PAIR> que;            
            vector<INT_VECTOR> answer;
            
            if (root == NULL) { return answer; }
            
            int maxDepth = INT_MIN;
            vector<INT_PAIR> bucket;
            que.push(make_pair(root, 0));
            
            while (!que.empty()) {
                
                const INT_PAIR here = que.front(); que.pop();
                maxDepth = std::max(here.second, maxDepth);
                bucket.push_back(here);
                
                if (here.first->left != NULL) { que.push({here.first->left, here.second + 1}); }
                if (here.first->right != NULL) { que.push({here.first->right, here.second + 1}); } 
            }
            
            for (int index = maxDepth; index >= 0; index--) {                
                vector<int> temp;
                for (const auto node : bucket) {
                    if (index == node.second) { temp.push_back(node.first->val); }
                }
                answer.push_back(temp);   
            }
            
            return answer;
            
        }
};
