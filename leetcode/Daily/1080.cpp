/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int sum) {
            sum += node->val;
            vector<int> res;
            bool flag = node->left || node->right;
            if (node->left) {
                int l = dfs(node->left, sum);
                if (l + sum < limit) node->left = nullptr;
                res.push_back(node->val + l);
            }
            if (node->right) {
                int r = dfs(node->right, sum);
                if (r + sum < limit) node->right = nullptr;
                res.push_back(node->val + r);
            }
            if (flag) {
                sort(res.begin(), res.end());
                return res.back();
            }
            return node->val;
        };
        int s = dfs(root, 0);
        if (s < limit) return nullptr;
        return root;
    }
};


class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        limit -= root->val;
        if (root->left == root->right)
            return limit > 0 ? nullptr : root;
        if (root->left) root->left = sufficientSubset(root->left, limit);
        if (root->right) root->right = sufficientSubset(root->right, limit);
        return root->left || root->right ? root : nullptr;
    }
};