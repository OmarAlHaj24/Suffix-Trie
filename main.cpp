/**
 * Alaa Mahmoud Ebrahim 20190105
 * Rana Ihab Ahmed      20190207
 * Omar Khaled Al Haj   20190351
 */

#include <iostream>

using namespace std;

struct SuffixTrieNode;

struct Node {
    char nodeChar = ' ';
    SuffixTrieNode *data = NULL;
    Node *next = NULL;
    Node *prv = NULL;
};

class LinkedList {
private:
    Node *head = NULL;
    Node *tail = NULL;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void add(Node *newData)
    {
        Node *newNode = newData;
        //newNode->data = newData;
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prv = tail;
            tail = newNode;
        }
    }

    SuffixTrieNode *getNode(char inputChar)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->nodeChar == inputChar)
            {
                return temp->data;
            }
            temp = temp->next;
        }
        return NULL;
    }

    Node *getHead()
    {
        return head;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
};

struct SuffixTrieNode{
    LinkedList *nodeList = new LinkedList();
    int endOfWord = -1;
};

size_t my_strlen(const char *str)
{
    size_t i;
    for (i = 0; str[i]; i++);
    return i;
}

class SuffixTrie {
private:
    SuffixTrieNode *root;
public:
    SuffixTrie(char input[])
    {
        size_t sz = my_strlen(input);
        root = new SuffixTrieNode;
        for (int i = 0; i < sz; i++)
        {
            SuffixTrieNode *tempRoot = root;
            for (int j = i; j < sz; j++)
            {
                SuffixTrieNode *temp = tempRoot->nodeList->getNode(input[j]);
                if (temp == NULL)
                {
                    Node *tempNode = new Node;
                    tempNode->nodeChar = input[j];
                    tempNode->data = new SuffixTrieNode;
                    tempRoot->nodeList->add(tempNode);
                    temp = tempNode->data;
                }
                tempRoot = temp;
            }
            tempRoot->endOfWord = i;
        }
    }

    void Search(char input[])
    {
        size_t sz = my_strlen(input);
        SuffixTrieNode *temp = root;
        for (int i = 0; i < sz; i++)
        {
            temp = temp->nodeList->getNode(input[i]);
            if (temp == NULL)
                break;

        }
        if (temp == NULL)
        {
            cout << "Not Found";
        }
        else
            {
            printIndex(temp);
        }
        cout << endl;
    }

    void printIndex(SuffixTrieNode *node)
    {
        Node *tempNode = node->nodeList->getHead();
        while (tempNode != NULL)
        {
            if (tempNode->data->endOfWord != -1)
            {
                cout << tempNode->data->endOfWord << " ";
            }
            else
            {
                printIndex(tempNode->data);
            }
            tempNode = tempNode->next;
        }
    }
    ~SuffixTrie()
    {
        delete root;
    }
};

int main()
{
    // Construct a suffix trie containing all suffixes of "bananabanaba$"
    //            0123456789012
    SuffixTrie t("bananabanaba$");
    t.Search("ana"); // Prints: 1 3 7
    t.Search("naba"); // Prints: 4 8
    return 0;
}
