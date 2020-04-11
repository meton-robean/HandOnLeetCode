/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
//字典树构造
class Trie
{

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root_ = TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *p = &root_;
        for (const auto c : word)
        {
            if (p->childrean[c - 'a'] == nullptr)
            {
                p->childrean[c - 'a'] = new TrieNode();
            }
            p = p->childrean[c - 'a'];
        }
        p->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *p = find(word);
        return p && p->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *p = find(prefix);
        return p != nullptr;
    }

private:
    ///member
    struct TrieNode
    {
        TrieNode() : is_word(false), childrean(26, nullptr)
        {
        }
        //TODO
        ~TrieNode() {}

        bool is_word;
        vector<TrieNode *> childrean;
    };

    //helper func
    TrieNode *find(string prefix)
    {
        TrieNode *cur = &root_;
        for (const auto c : prefix)
        {
            if (cur->childrean[c - 'a'] != nullptr)
            {
                cur = cur->childrean[c - 'a'];
            }
            else
            {
                cur = cur->childrean[c - 'a'];
                break;
            }
        }
        return cur;
    }

    TrieNode root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end




// @lc code=end

