class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        unsigned long long maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0}); // Start with root at index 0

        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = q.back().second;

            maxWidth = max(maxWidth, right - left + 1);

            for (int i = 0; i < size; ++i) {
                auto [node, index] = q.front();
                q.pop();

                index -= left; // Normalize index

                if (node->left) q.push({node->left, 2 * index});
                if (node->right) q.push({node->right, 2 * index + 1});
            }
        }

        return static_cast<int>(maxWidth);
    }
};
