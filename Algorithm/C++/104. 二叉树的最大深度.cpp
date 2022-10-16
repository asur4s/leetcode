// DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};

// BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        queue<TreeNode*> Q;
        Q.push(root);

        int size, ans;
        ans = 0;
        TreeNode *cur;
        while(!Q.empty()){
            size = Q.size();
            while(size > 0){
                cur = Q.front();
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                Q.pop();

                size--;
            }
            ans++;
        } 
        return ans;
    }
};