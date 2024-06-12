#include <bits/stdc++.h>
using namespace std;
struct trieNode
{
    trieNode *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    trieNode *getNode(char ch)
    {
        return links[ch - 'a'];
    }
    void putNode(char ch, trieNode *node)
    {
        links[ch - 'a'] = node;
    }
    void increaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    void reduceEnd()
    {
        cntEndWith--;
    }
    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefix()
    {
        return cntPrefix;
    }
    bool isCompleteWord(char ch)
    {
        return links[ch - 'a']->cntEndWith > 0;
    }
};
class Trie
{
private:
    trieNode *root;

public:
    Trie()
    {
        root = new trieNode();
    }
    // insert a word into trie
    void insertWord(string word)
    {
        trieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                node->putNode(word[i], new trieNode());
            node = node->getNode(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    // it return the number of particular word present in trie
    int countWordEqualTo(string word)
    {
        trieNode *node = root;
        for (int i = 0; i < word[i]; i++)
        {
            if (!node->containsKey(word[i]))
                return 0;
            node = node->getNode(word[i]);
        }
        return node->getEnd();
    }

    // No  of words starting with prefix
    int startWithPrefix(string word)
    {
        trieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                return 0;
            node = node->getNode(word[i]);
        }
        return node->getPrefix();
    }

    // delete a word
    //NOTE:: here we are assuming that the word exist
    void eraseWord(string word)
    {
        trieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                return;
            node = node->getNode(word[i]);
            node->reducePrefix();
        }
        node->reduceEnd();
    }

    // // finds a complete word::the definition for complete word is that all the prefixes of that word should be present in the given array of strings;
    bool completeWord_Util(trieNode *node, string temp, string &ans)
    {
        for (char i = 'a'; i <= 'z'; i++)
        {
            if (node->containsKey(i) && node->isCompleteWord(i))
            {
                temp = temp + i;
                if (temp.length() > ans.length())
                    ans = temp;
                else if (temp.length() == ans.length() && temp < ans)
                    ans = temp;
                if (!completeWord_Util(node->getNode(i), temp, ans))
                    temp.pop_back();
            }
        }
        return false;
    }
    string completeWord(vector<string> str)
    {
        trieNode *node = root;
        for (int j = 0; j < str.size(); j++)
            insertWord(str[j]);
        string ans = "";
        string temp = "";
        completeWord_Util(node,temp, ans);
        return ans;
    }
};

using namespace std;
int main()
{
    Trie a;
    vector<string> str = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << a.completeWord(str);
    // cout<<a.countWordEqualTo("appley");
    // string word = "ninja";
    // cout << word;
    // for (string s : str)
    //     a.insertWord(s);

    // cout << word;
    // cout << a.countWordEqualTo(word) << "hello";
    return 0;
}