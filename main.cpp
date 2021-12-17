#include <iostream>
using namespace std;

struct  SuffixTrieNode;

struct Node{
    char nodeChar = ' ';
    SuffixTrieNode* data = NULL;
    Node* next = NULL;
    Node* prv = NULL;
};

class LinkedList{
private:
    Node* head = NULL;
    Node* tail = NULL;

public:
    void add(Node* newData){
        Node* newNode = newData;
        //newNode->data = newData;
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prv = tail;
            tail = newNode;
        }
    }

    SuffixTrieNode* getNode(char inputChar){
        if(head == NULL){
            return NULL;
        }
        Node* temp = head;
        while(temp != NULL){
            if(temp->nodeChar == inputChar){
                return temp->data;
            }
            temp = temp->next;
        }
        return NULL;
    }

    Node* getHead(){
        return head;
    }

    ~LinkedList(){
        Node* temp = head;
        while(temp != NULL){
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
};

struct SuffixTrieNode{
    LinkedList* nodeList = new LinkedList();
    int endOfWord = -1;
};

class SuffixTrie{
private:
    SuffixTrieNode* root;
public:
    SuffixTrie(string input){
        for(int i = 0; i < input.size(); i++){
            SuffixTrieNode* tempRoot = root;
            for(int j = i; j < input.size(); j++){
                SuffixTrieNode* temp = tempRoot->nodeList->getNode(input[j]);
                if(temp == NULL){
                    Node* tempNode = new Node;
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
    void search(string input){

    }
};

int main() {
   // SuffixTrie t("bananabanaba$");
    LinkedList test;
    Node* temp = new Node;
    temp->nodeChar = 'i';
    test.add(temp);
    SuffixTrieNode* temp2 = test.getNode('i');
    if(temp2 != NULL) cout << "HI";
    if(temp2 == NULL) cout << "HI2";
}
