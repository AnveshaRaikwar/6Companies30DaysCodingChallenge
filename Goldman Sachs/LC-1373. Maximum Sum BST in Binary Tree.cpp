class Solution {
public:
    int ans;

    vector<int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {INT_MAX, INT_MIN, 0};
        }

        vector<int> leftSubtree = dfs(root->left);
        vector<int> rightSubtree = dfs(root->right);

        if (root->val > leftSubtree[1] && root->val < rightSubtree[0]) {
            int currSum = leftSubtree[2] + rightSubtree[2] + root->val;
            ans = max(ans, currSum);
            int minVal = min(root->val, leftSubtree[0]);
            int maxVal = max(root->val, rightSubtree[1]);
            return {minVal, maxVal, currSum};
        }

        int maxSum = max(leftSubtree[2], rightSubtree[2]);
        return {INT_MIN, INT_MAX, maxSum};
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};