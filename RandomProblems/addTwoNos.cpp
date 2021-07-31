#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
    {
        this->val = 0;
        next = NULL;
    }

    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;

    ListNode *resHead = new ListNode;
    ListNode *res = resHead;

    int carry = 0;

    while (temp1 != NULL && temp2 != NULL)
    {
        // if (resHead == NULL)
        // {
        res->next = new ListNode(temp1->val + temp2->val + carry);
        // }

        // else
        // res = new ListNode(temp1->val + temp2->val + carry);

        if (res->val > 9)
        {
            carry = 1;
            res->val = res->val % 10;
        }
        else
            carry = 0;
        res = res->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1 != NULL)
    {
        res = new ListNode(temp1->val + carry);
        if (res->val > 9)
        {
            carry = 1;
            res->val = res->val % 10;
        }
        else
            carry = 0;
        res = res->next;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        res = new ListNode(temp2->val + carry);
        if (res->val > 9)
        {
            carry = 1;
            res->val = res->val % 10;
        }
        else
            carry = 0;
        res = res->next;
        temp2 = temp2->next;
    }

    if (carry == 1)
    {
        res = new ListNode(carry);
    }

    return resHead;
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);

    ListNode *head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);

    ListNode *res = addTwoNumbers(head1, head2);

    print(res);
}