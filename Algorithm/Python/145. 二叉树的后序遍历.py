class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        WHITE, GRAY = 0, 1
        ans = []
        stack = [(WHITE, root)]
        while stack:
            color, node = stack.pop()
            if node == None: continue
            if color == WHITE:
                stack.append((WHITE, node.right))
                stack.append((WHITE, node.left))
                stack.append((GRAY, node))
            else:
                ans.append(node.val)
        return ans