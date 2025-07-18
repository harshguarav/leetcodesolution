class Solution {
public:
    void lSum(TreeNode* root,int level,unordered_map<int,int> &levelSum,unordered_map<TreeNode*,int>& sibSum){
        if(!root) return;

        levelSum[level]=levelSum[level]+root->val;

        //now here i am calculating the value of the sibling node only then i will subtract the vlaue of level node to the sinling noe to get the value of the cousin node 

        if(root->left && root->right){
            int sum=root->left->val+root->right->val;
            sibSum[root->left]=sum;
            sibSum[root->right]=sum;
        }

        lSum(root->left,level+1,levelSum,sibSum);
        lSum(root->right,level+1,levelSum,sibSum);
    }

    //my calculation is done till now 
    void assign(TreeNode* root,int level,unordered_map<int,int>& levelSum,unordered_map<TreeNode*,int>& sibSum){
        if(!root) return ;
        int totalAtLevel=levelSum[level];
        if(sibSum.count(root)){
            root->val=totalAtLevel-sibSum[root];
        }
        else{
            root->val=totalAtLevel-root->val;
        }
        assign(root->left,level+1,levelSum,sibSum);
        assign(root->right,level+1,levelSum,sibSum);


    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int,int> levelSum;
        unordered_map<TreeNode*,int> sibSum;
        // sibSum[root]=root->val;
        lSum(root,0,levelSum,sibSum);
        assign(root,0,levelSum,sibSum);
        return root;
        
    }
};