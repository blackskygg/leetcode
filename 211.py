class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.is_word = False
        self.children = [None for i in xrange(26)]
        

class WordDictionary(object):

    def __init__(self):
        self.root = TrieNode()
        
    def _insert(self, curr_node, suffix, pos):
        index = ord(suffix[pos])-ord('a')
        if not curr_node.children[index]:
            curr_node.children[index] = TrieNode()
        
        curr_node = curr_node.children[index]
        if len(suffix) - pos == 1:
            curr_node.is_word = True
        else:
           self. _insert(curr_node, suffix, pos+1)
            
    def addWord(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        self._insert(self.root, word, 0)

    def _search_dot(self, curr_node, suffix, pos):
        if len(suffix) - pos == 1:
            for next_node in curr_node.children:
                if next_node and next_node.is_word:
                    return True
        else:
            for next_node in curr_node.children:
                if next_node and self._search(next_node, suffix, pos+1):
                    return True

        return False

    def _search(self, curr_node, suffix, pos):
        if suffix[pos] == '.':
            return self._search_dot(curr_node, suffix, pos)
        
        index = ord(suffix[pos])-ord('a')
        if not curr_node.children[index]:
            return False
        
        curr_node = curr_node.children[index]
        if len(suffix) - pos == 1:
            if curr_node.is_word:
                return True
            else:
                return False
        else:
            return self._search(curr_node, suffix, pos+1)
            
        
    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        return self._search(self.root, word, 0)
