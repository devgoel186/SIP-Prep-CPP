#include <bits/stdc++.h>
using namespace std;
#define long long ll;

struct Node
{
    int data;
    Node *next;
    Node()
    {
    }
};

Node *evenOdd(Node *head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenStart = even;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    if (odd->next == NULL)
        even->next = NULL;
    return head;
}

Node *insertAtBeginning(Node *head, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = head;
    return temp;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 21);
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 121);
    head = insertAtBeginning(head, 24);
    head = insertAtBeginning(head, 221);
    head = insertAtBeginning(head, 1);
    head = evenOdd(head);
    print(head);

    // 1 221 24 121 3 21 2
    // 1 24 3 2 221 121 21
    // 1 221 24 121 3 21 2
}