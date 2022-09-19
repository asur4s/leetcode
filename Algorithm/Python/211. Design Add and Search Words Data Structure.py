class TrieNode(object):
    def __init__(self):
        self.isEnd = False
        self.children = {}

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()
        
        
    def addWord(self, word: str) -> None:
        head = self.root
        
        for c in word:
            if c not in head.children:
                head.children[c] = TrieNode()
            head = head.children[c]
        head.isEnd = True
            

    def search(self, word: str) -> bool:
        currLevel = [self.root]
        
        for c in word:
            nextLevel = []
            # Add to next
            if c == ".":
                for node in currLevel:
                    nextLevel.extend(node.children.values())
            else:
                for node in currLevel:
                    if c in node.children:
                        nextLevel.append(node.children[c])
            # Not found
            if not nextLevel:
                return False
            # Update curr
            currLevel = nextLevel
        
        # Find end
        for node in currLevel:
            if node.isEnd:
                return True
        return False