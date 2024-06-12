    #include <bits/stdc++.h>
using namespace std;
struct trie_node
{
    trie_node *links[26];
    bool EndOfWord;

    // checks wheather the node contains the key or not;
    bool containsKey(char ch)
    {
        return links[ch - 'a'];
    }

    // put a new reference node
    void put(trie_node *reference_trieNode, char ch)
    {
        links[ch - 'a'] = reference_trieNode;
    }

    //get the node which a character ch is pointing
    trie_node *getNode(char ch)
    {
        return links[ch - 'a'];
    }

    // this will set the EndOfWord to true
    void setEndOfWord()
    {
        EndOfWord = true;
    }

    // returns the state of EndOfWord
    bool getEnd()
    {
        return EndOfWord;
    }
};
class Trie
{
private:
    trie_node *root;

public:
    // initialize data structure
    Trie()
    {
        root = new trie_node();
    }
    // insert a word into the trie
    void insert(string word)
    {
        trie_node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];          // curr char
            if (!node->containsKey(ch)) // if the character is not present then then it will be added
            {
                trie_node *temp = new trie_node();
                node->put(temp, ch);
            }
            node = node->getNode(ch); // moving the pointer to next reference node
        }
        node->setEndOfWord();
    }
    // Search for a word in trie
    bool searchWord(string word)
    {
        trie_node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i])) // if the node does not contain the key that is the letter word[i], hence it's obvious that the trie doesn't contains that word, so we return false;
                return false;
            node = node->getNode(word[i]); // else we will continue to the next node;
        }
        return node->getEnd(); // if we reached here that means all the letters of the word exist into the trie, means if the last node EndOfWord is true then it's word and if not then its not a word;
    }

    // IsStartsWith:: it return true if there is any word with a matching prefix;
    bool IsStartsWithPrefix(string word)
    {
        trie_node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->getNode(word[i]);
        }
        return true;
    }
};
int main()
{
    Trie a;
    a.insert("apple");
    a.insert("apps");
    a.insert("apples");
    a.insert("rock");
    a.insert("rocket");
    cout << a.IsStartsWithPrefix("rock") << endl
         << a.searchWord("apps") << endl
         << a.searchWord("appless");
    return 0;
}