#include <iostream>
#include <vector>
using namespace std;

struct PriorityQueue
{
    vector<int> *v;

    PriorityQueue()
    {
        v = new vector<int>();
    }
};

PriorityQueue *p;

int getSize()
{
    return p->v->size();
}

bool isEmpty()
{
    if (getSize())
        return false;
    return true;
}

int getMin()
{
    if (isEmpty())
        return -1;
    return p->v->at(0);
}

void insertElement(int element)
{
    p->v->push_back(element);
    int child = getSize() - 1;
    while (child > 0)
    {
        int parent = (child - 1) / 2;
        if (p->v->at(child) < p->v->at(parent))
        {
            swap(p->v->at(parent), p->v->at(child));
        }
        else
            break;
        child = parent;
    }
}

void removeMin()
{
    if (isEmpty())
        return;
    int temp = p->v->at(getSize() - 1);
    p->v->at(0) = temp;
    p->v->pop_back();

    // down-heapify
    int i = 0;
    int parent = 0;
    int child1 = 2 * parent + 1;
    int child2 = 2 * parent + 2;

    while (child1 < getSize())
    {
        int minIndex = parent;
        if (p->v->at(minIndex) > p->v->at(child1))
            minIndex = child1;
        if (child2 < getSize() && p->v->at(minIndex) > p->v->at(child2))
            minIndex = child2;
        if (parent == minIndex)
            break;
        swap(p->v->at(parent), p->v->at(minIndex));
        parent = minIndex;
        child1 = 2 * parent + 1;
        child2 = 2 * parent + 2;
    }
}

int main()
{
    p = new PriorityQueue();
    insertElement(2);
    cout << "Size = " << getSize() << endl;
    cout << "Min = " << getMin() << endl;
    insertElement(4);
    cout << "Min = " << getMin() << endl;
    insertElement(21);
    removeMin();
    insertElement(132);
    cout << "Size = " << getSize() << endl;
    removeMin();
    insertElement(90);
    cout << "Size = " << getSize() << endl;
    insertElement(7);
    insertElement(145);
    cout << "Min = " << getMin() << endl;
    removeMin();
    cout << "Min = " << getMin() << endl;
}