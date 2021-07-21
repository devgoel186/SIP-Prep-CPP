#include <bits/stdc++.h>
using namespace std;
#define long long ll

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *insertNode(Node *head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return head;
    }
    Node *temp = new Node(data);
    Node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    return head;
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
    Node *head1 = NULL;
    Node *head2 = NULL;
    int n1, n2;
    cin >> n1 >> n2;

    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        head1 = insertNode(head1, x);
    }

    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        head2 = insertNode(head2, x);
    }

    Node *head3 = NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;
    for (int i = 0; i < n1; i++)
    {
        if (temp1 == NULL || temp2 == NULL)
            break;
        if (temp1->data == temp2->data)
        {
            head3 = insertNode(head3, temp1->data);
        }
        temp1 = temp1->next;
        while (temp1 != NULL && temp2 != NULL && temp1->data > temp2->data)
            temp2 = temp2->next;
    }

    print(head1);
    print(head2);
    print(head3);
}