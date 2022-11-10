class Solution {
private:
    unordered_map<int, int> map;
    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder, int pre_left, int pre_right, int ino_left, int ino_right){
        if(pre_left > pre_right || ino_left > ino_right){
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[pre_left]);
        int root_index = map[preorder[pre_left]];
        int len = root_index - ino_left;
        root->left = build(preorder, inorder, pre_left+1, pre_left+len, ino_left, root_index-1);
        root->right = build(preorder, inorder, pre_left+len+1, pre_right, root_index+1, ino_right );
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        for(int i=0; i<size; i++){
            map[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, size-1, 0, size-1);
    }
};