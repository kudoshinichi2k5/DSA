#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};




// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

void AddHead(SinglyLinkedList* l, SinglyLinkedListNode* newNode)
{
    if(l.head == NULL)
        l->head = l->tail = newNode;
    else{
        newNode->next = l->head;
        l->head = newNode;
    }
}

void insert_node(SinglyLinkedList* l, SinglyLinkedListNode* newNode)
{
    
}

void reverseLinkedList(SinglyLinkedList* l)
{
    SinglyLinkedList* l2 = new SinglyLinkedList;
    SinglyLinkedListNode* curNode1 = l->head;
    while(curNode1 != NULL)
    {
        AddHead(l2, curNode1);
        curNode1 = curNode1->next;
    }
}
void printLinkedList(SinglyLinkedList* l)
{
    SinglyLinkedNode* curNode = l->head;
    while(curNode!=NULL)
    {
        cout << curNode->data << " ";
        curNode = curNode->next;
    }
}


int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}