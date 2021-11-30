// create a single linked list
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
void print(node *head)
{
    node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void insert(node *&head, int data)
{
    node *p = new node;
    p->data = data;
    // insert at the end
    if (head == NULL)
    {
        head = p;
        p->next = NULL;
    }
    else
    {
        node *q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->next = NULL;
    }
}

// reverse a linked list
void reverse(node *&head)
{
    node *p = head;
    node *q = NULL;
    node *r = NULL;
    while (p != NULL)
    {
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    head = q;
}

void changeListOrder(node *&head)
{
    // find the middle node
    node *p = head;
    node *q = head;
    while (q->next != NULL && q->next->next != NULL)
    {
        p = p->next;
        q = q->next->next;
    }
    node *mid = p->next;
    p->next = NULL;
    // reverse the second half
    reverse(mid);
    // merge the two list together
    // print(mid);
    // print(head);
    node *firstNode = head;
    node *secondNode = mid;
    node *newHead = NULL;
    while (firstNode != NULL && secondNode != NULL)
    {
        node *temp = firstNode;
        firstNode = firstNode->next;
        temp->next = newHead;
        newHead = temp;
        temp = secondNode;
        secondNode = secondNode->next;
        temp->next = newHead;
        newHead = temp;
    }
    // add the remaining nodes
    if (firstNode != NULL)
    {
        node *temp = firstNode;
        firstNode = firstNode->next;
        temp->next = newHead;
        newHead = temp;
    }
    if (secondNode != NULL)
    {
        node *temp = secondNode;
        secondNode = secondNode->next;
        temp->next = newHead;
        newHead = temp;
    }
    reverse(newHead);
    head = newHead;
}
void clear(node *&head)
{
    node *p = head;
    while (p != NULL)
    {
        head = head->next;
        delete p;
        p = head;
    }
}
int main()
{
    node *head = NULL;

    // input number of nodes
    int n;
    cin >> n;
    // input data
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        insert(head, data);
    }
    // cout << "before change order: ";
    // print(head);

    changeListOrder(head);

    // cout << "after change order: ";
    print(head);
    // delete the list
    clear(head);
    return 0;
}
