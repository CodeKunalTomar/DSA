class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    bool searchPalindrome(TrieNode *parent, string word)
    {
        if (parent->isTerminal || word.size() == 0)
            return true;
        if (parent->children[word[0] - 'a'] != NULL)
            return searchPalindrome(parent->children[word[0] - 'a'], word.substr(1));
        else
            return false;
    }

    bool searchPalindrome(vector<string> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            string s1 = v[i], s2 = v[i];
            reverse(s1.begin(), s1.end());
            if (searchPalindrome(root, s1))
                return true;
        }
        return false;
    }

    bool isPalindromePair(vector<string> words)
    {
        // Write your code here
        for (int i = 0; i < words.size(); i++)
            add(words[i]);
        return searchPalindrome(words);
    }
};