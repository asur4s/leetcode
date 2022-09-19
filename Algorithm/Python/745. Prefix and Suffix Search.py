class Trie:
    def __init__(self):
        self.root = {}
        self.end = 'end'
    
    def insert(self, word, idx):        
        word = word + '#' + word
        
        for i in range(len(word)):
            node = self.root
            
            for j in range(i, len(word)):
                if word[j] not in node:
                    node[word[j]] = {}
                
                node = node[word[j]]
            
                node[self.end] = idx
                
    def search(self, suf_pref):
        node = self.root
        
        for char in suf_pref:
            if char not in node:
                return - 1
            
            node = node[char]

        return node[self.end]
    
class WordFilter:
    def __init__(self, words: List[str]):
        self.t = Trie()
        
        for idx in range(len(words)):
            self.t.insert(words[idx], idx)

    def f(self, prefix: str, suffix: str) -> int:
        return self.t.search(suffix + '#' + prefix)