class Solution {
private:
    unordered_map<int, int> map;
    TreeNode* build(const vector<int>& preorder, const vector<int>& postorder, int pre_left, int pre_right, int post_left, int post_right){
        if(pre_left > pre_right || post_left > post_right){
            return nullptr;
        }
        if(pre_left == pre_right || post_left == post_right){
            return new TreeNode(preorder[pre_left], nullptr, nullptr);
        }
        
        TreeNode *root = new TreeNode(preorder[pre_left]);
        int left_root_index = map[preorder[pre_left + 1]];
        int len = left_root_index - post_left + 1;
        root->left = build(preorder, postorder, pre_left+1, pre_left+len, post_left, left_root_index);
        root->right = build(preorder, postorder, pre_left+len+1, pre_right, left_root_index+1, post_right-1 );
        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int size = preorder.size();
        for(int i=0; i<size; i++){
            map[postorder[i]] = i;
        }
        return build(preorder, postorder, 0, size-1, 0, size-1);
    }
};