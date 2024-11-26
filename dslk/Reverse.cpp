
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

void insert_node(SinglyLinkedList *llist, int llist_item)
{
    SinglyLinkedListNode* p = new SinglyLinkedListNode(llist_item);
    if(llist->head == NULL)
        llist->head = llist->tail = p;
    else
    {
        llist->tail->next = p;
        llist->tail = p;
    }
}

void reverseLinkedList(SinglyLinkedList* llist)
{
    SinglyLinkedListNode* prev = NULL;
    SinglyLinkedListNode* next = NULL;
    SinglyLinkedListNode* cur = llist->head;
    llist->tail = llist->head;
    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    llist->head = prev;
}

void printLinkedList(SinglyLinkedList* llist)
{
    SinglyLinkedListNode* p = llist->head;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

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
