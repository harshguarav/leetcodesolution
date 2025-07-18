// class Solution {
// public:
//     void lSum(TreeNode* root,int level,unordered_map<int,int> &levelSum,unordered_map<TreeNode*,int>& sibSum){
//         if(!root) return;

//         levelSum[level]=levelSum[level]+root->val;

//         //now here i am calculating the value of the sibling node only then i will subtract the vlaue of level node to the sinling noe to get the value of the cousin node 

//         if(root->left && root->right){
//             int sum=root->left->val+root->right->val;
//             sibSum[root->left]=sum;
//             sibSum[root->right]=sum;
//         }

//         lSum(root->left,level+1,levelSum,sibSum);
//         lSum(root->right,level+1,levelSum,sibSum);
//     }

//     //my calculation is done till now 
//     void assign(TreeNode* root,int level,unordered_map<int,int>& levelSum,unordered_map<TreeNode*,int>& sibSum){
//         if(!root) return ;
//         int totalAtLevel=levelSum[level];
//         if(sibSum.count(root)){
//             root->val=totalAtLevel-sibSum[root];
//         }
//         else{
//             root->val=totalAtLevel-root->val;
//         }
//         assign(root->left,level+1,levelSum,sibSum);
//         assign(root->right,level+1,levelSum,sibSum);


//     }

//     TreeNode* replaceValueInTree(TreeNode* root) {
//         unordered_map<int,int> levelSum;
//         unordered_map<TreeNode*,int> sibSum;
//         // sibSum[root]=root->val;
//         lSum(root,0,levelSum,sibSum);
//         assign(root,0,levelSum,sibSum);
//         return root;
        
//     }
// };


// this is optimized soltion

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        root->val = 0; // root has no cousins
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            unordered_map<TreeNode*, int> siblingSum; // child -> sibling sum
            vector<TreeNode*> currLevel;
            int levelSum = 0;

            // First pass: calculate sibling sums and level sum
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front(); q.pop();
                currLevel.push_back(node);

                int sum = 0;
                if (node->left)  sum += node->left->val;
                if (node->right) sum += node->right->val;

                if (node->left) {
                    siblingSum[node->left] = sum;
                    q.push(node->left);
                    levelSum += node->left->val;
                }
                if (node->right) {
                    siblingSum[node->right] = sum;
                    q.push(node->right);
                    levelSum += node->right->val;
                }
            }

            // Second pass: assign cousin sum
            for (TreeNode* node : currLevel) {
                if (node->left)
                    node->left->val = levelSum - siblingSum[node->left];
                if (node->right)
                    node->right->val = levelSum - siblingSum[node->right];
            }
        }

        return root;
    }
};
