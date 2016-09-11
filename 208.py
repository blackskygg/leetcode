class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.is_word = False
        self.children = [None for i in xrange(26)]
        

class Trie(object):

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
            
    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        self._insert(self.root, word, 0)
        
    def _search(self, curr_node, suffix, pos, search_word):
            
        index = ord(suffix[pos])-ord('a')
        if not curr_node.children[index]:
            return False
        
        curr_node = curr_node.children[index]
        if len(suffix) - pos == 1:
            if not search_word or curr_node.is_word:
                return True
            else:
                return False
        else:
            return self._search(curr_node, suffix, pos+1, search_word)
            
        
    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        return self._search(self.root, word, 0, True)
        
        

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie
        that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        return self._search(self.root, prefix, 0, False)
