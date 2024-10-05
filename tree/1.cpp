#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

typedef struct node
{
    int key;
    node* left;
    node* right;
}*TREE;

void CreateTree(TREE &t)
{
    t = NULL;
}

void Input(TREE& a)
{
    int tmp;
    cin >> tmp;
    if(tmp==-1)     return;
    a->key = tmp;
    while(1)
    {
        cin >> tmp;
        if(tmp==-1)             return;
        else if(tmp<a->key)     a->left = tmp;
        else                    a->right = tmp;
    }
}

int Node1Con(TREE a)
{
    int sum = 0;
    while(a!=NULL)
    {
        if(a->left==NULL && a->right!=NULL)
        {
            sum++;
            sum+=Node1Con(a->right);
        }
        if(a->left!=NULL && a->right==NULL)
        {
            sum++;
            sum+=Node1Con(a->left);
        }
        sum+=Node1Con(a->left);
        sum+=Node1Con(a->right);
    }
    return sum;
}

void inOrder(NODE* root)
{
    if(root == NULL)    return;
     inOrder(root->left);
     cout << root->data;
     inOrder(root->right);
}

int Height(Node* root)
{
    if(root == NULL)       return 0;
    return 1 + max(Height(root->left), Height(root->right));
}

//Print theo level cua cay

//c1
// void PrintLevel(Node* root, int i)
// {
//     if(root == NULL)     return;
//     if(i == 1)
//     {
//         cout << root->data;
//         return;
//     }
//     else{
//         PrintLevel(root->left, i-1);
//         PrintLevel(root->right, i-1);
//     }
// }

//c2
// void PrintLevel(Node* root)
// {
//     if(root == NULL)    return;
//     queue<Node*> Q;
//     Q.push(root);
//     while(Q.empty() == false)
//     {
//         Node* u = Q.front();
//         cout << u->data << " ";
//         Q.pop();
//         if(u->left != NULL)     Q.push(u->left);
//         if(u->right != NULL)    Q.push(u->right);
//     }
// }

int main()
{
    TREE a;
    CreateTree(a);
    Input(a);
    return 1;
}