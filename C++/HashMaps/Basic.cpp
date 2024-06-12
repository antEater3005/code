#include <iostream>
#include <list>
#include <string>
using namespace std;
class hashtable
{
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups]; //List 1: index1,index 2,...
public:
    bool isEmpty() const;
    int hashFunc(int key);
    void insert(int key, string value);
    void remove(int key);
    string searchTable(int key);
    void printTable();
};
bool hashtable::isEmpty() const
{

    int sum{};
    for (int i{}; i < hashGroups; i++)
    {
        sum += table[i].size();
    }
    if (!sum)
        return true;
    return false;
}
int hashtable::hashFunc(int key)
{
    return key % hashGroups; // Key.905 in return ,this function will spit out 5
}
void hashtable::insert(int key, string value)
{
    int hashValue = hashFunc(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExist = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExist = true;
            bItr->second = value;
            cout << "[WARNING] Key exist. Value replaced." << endl;  // Here we are not resolving the conflict in the hashing instead we replace the old data set to a new data.
            break;
        }
    }
    if (!keyExist)
    {
        cell.emplace_back(key, value);
    }
    return;
}
void hashtable::remove(int key)
{
    int hashValue = hashFunc(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExist = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExist = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Item Removed." << endl;
            break;
        }
    }
    if (!keyExist)
    {
        cout << "[WARNING]:Item not found.Pair not removed." << endl;
    }
    return;
}
void hashtable::printTable()
{
    for (int i{}; i < hashGroups; i++)
    {
        if (table[i].size() == 0)
            continue;
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++)
        {
            cout << "[INFO]:Key:" << bItr->first << " Value:" << bItr->second << endl;
        }
    }
    return;
}
int main()
{
    hashtable HT;
    if (HT.isEmpty())
    {
        cout << "Empty. \n";
    }
    else
    {
        cout << "Not empty.";
    }
    HT.insert(201, "tim");
    HT.insert(301, "jin");
    HT.insert(202, "mike");
    HT.insert(203, "sip");
    HT.insert(207, "bob");
    HT.insert(205, "sandy");
    HT.insert(206, "barb");
    HT.insert(208, "rob");
    HT.insert(205, "rick");

    HT.printTable();
    HT.remove(208);
    HT.remove(100);
    HT.printTable();
    return 0;
}