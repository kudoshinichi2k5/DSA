#include<iostream>
#include<cmath>
#include<string>
using namespace std;

struct node
{
    char info;
    node* pNext;
};
//typedef struct Node NODE;

node* CreateNode(char x)
{
    node* temp = new node();
    if(temp == NULL)    exit(1);
    temp->info = x;
    temp->pNext = NULL;
    return temp;
}

// STACK
struct stack
{
    node* pHead;
};
//typedef struct Stack STACK;

bool isEmpty(stack &s)
{
    if(s.pHead == NULL)     return true;
    return false;
}

void CreateEmptyStack(stack &s)
{
    s.pHead = NULL;
}

// Add head
void push(stack &s, node* p)
{
    if(s.pHead == NULL)     s.pHead = p;
    else{
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

// Remove Head
void pop(stack &s)
{
    node* p;
    if(s.pHead == NULL)     return;
    else{
        p = s.pHead;
        s.pHead = p->pNext;
        delete p;
    }
}

// QUEUE
struct queue
{
    node* pHead;
    node* pTail;
};

bool isEmpty(queue &q)
{
    if(q.pHead == NULL)     return true;
    return false;
}

void CreateEmptyQueue(queue &q)
{
    q.pHead = q.pTail = NULL;
}

// Add tail
void enqueue(queue &q, node* p)
{
    if(q.pHead == NULL)     
        q.pHead = q.pTail = p;
    else{
        q.pTail->pNext = p;
        q.pTail = p;
    }
}

// Remove head
void dequeue(queue &q)
{
    node *p = q.pHead;
    q.pHead = p->pNext;
    if(q.pHead == NULL)     q.pTail= NULL;
    delete p;
}

int priority(char c)
{
    if(c == '+' || c == '-')    return 1;
    if(c == '*' || c == '/')    return 2;
    return 0;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool BracketMatching(string st)
{
    stack s;
    CreateEmptyStack(s);
    for(int i=0; i<st.size(); i++)
    {
        if(st[i] == '(')
            push(s, CreateNode('('));
        if(st[i] == ')')
        {
            if(isEmpty(s)==1)
            {
                return false;
            }   
            else{
                pop(s);
            }
        }
    }
    if(isEmpty(s) == 1)     return true;
    else                    return false;
}

queue infix_to_postfix(string st)
{
    //string res = "";
    stack s;
    queue q;
    CreateEmptyStack(s);
    CreateEmptyQueue(q);
    for(int i=0; i<st.size(); i++)
    {
        if(isdigit(st[i]))
            enqueue(q, CreateNode(st[i]));
        else if(st[i] == '(')  
            push(s, CreateNode(st[i]));
        else if(st[i] == ')')
        {
            while(s.pHead->info != '(')
            {
                enqueue(q, CreateNode(s.pHead->info));
                pop(s);
            }
            pop(s);
        } 
        else if(isOperator(st[i]))
        {
        	// Stack rong
            if(isEmpty(s))
                push(s, CreateNode(st[i]));
            // Stack dang co ptu
            else
            {
            	// Phan tu dau stack ko la toan tu
                if(!isOperator(s.pHead->info))
                    push(s, CreateNode(st[i]));
                // Phan tu dau stack la toan tu
                else
                {
                	// Toan tu dau stack co do uu tien nho hon x
                    int p1 = priority(s.pHead->info);
                    int p2 = priority(st[i]);
                    if(p1 < p2)
                        push(s, CreateNode(st[i]));
                    // Toan tu dau stack co do uu tien lon hon hoac bang x
                    else
                    {
                        while((!isEmpty(s)) && (isOperator(s.pHead->info)) && priority(s.pHead->info) >= p2)
                        {
                            enqueue(q, CreateNode(s.pHead->info));
                            pop(s);
                        }
                        push(s, CreateNode(st[i]));
                    }
                }
            }
        }
    }
    // Khi duyet xong, stack con ptu thi day het qua queue
    while(!isEmpty(s))
    {
        enqueue(q, CreateNode(s.pHead->info));
        pop(s);
    }
    return q;
    
}

int Calculate(int p1, int p2, char c)
{
	int res;
	switch(c)
	{
		case '+':
			res = p2 + p1;
			break;
		case '-':
			res = p2 - p1;
			break;
		case '*':
			res = p2 * p1;
			break;
		case '/':
			res = p2 * 1.0 / p1;
			break; 
	}
	return res;
}

int CalculateExpression(queue q)
{
	stack s;
	CreateEmptyStack(s);
	while(!isEmpty(q))
	{
		// La toan hang
		if(isdigit(q.pHead->info))
		{
			push(s, CreateNode(q.pHead->info));
		}
		// La toan tu
		else
		{
			int p1 = int(s.pHead->info - 48);
			pop(s);
			int p2 = int(s.pHead->info - 48);
			pop(s);
			int ans = Calculate(p1, p2, q.pHead->info);
			push(s, CreateNode(char(ans + 48)));
		}
		dequeue(q);
	}
	return int(s.pHead->info - 48);
}

int main()
{
    string a;
    cin >> a;
    queue q = infix_to_postfix(a);
    // while(q.pHead != NULL)
    // {
    // 	cout << q.pHead->info;
    // 	dequeue(q);
    // }
    // cout << endl;
    cout << CalculateExpression(q);
    return 0;
}