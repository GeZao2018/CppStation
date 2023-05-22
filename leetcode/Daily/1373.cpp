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
    int maxSumBST(TreeNode* root) {
        int INF = 0x3f3f3f3f, ans = 0;
        function<tuple<int,int,int>(TreeNode*)> dfs = [&](TreeNode* node) -> tuple<int,int,int> {
            if (!node) return {INF, -INF, 0};
            auto [ll, lr, ls] = dfs(node->left);
            auto [rl, rr, rs] = dfs(node->right);
            int x = node->val;
            if (x <= lr || x >= rl)
                return {-INF, INF, 0};
            ans = max(ans, ls + rs + x);
            return {min(ll, x), max(rr, x), ls + rs + x};
        };
        dfs(root);
        return ans;
    }
};