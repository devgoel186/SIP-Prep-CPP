#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node
{
    string key;
    T value;
    Node *next;

    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    ~Node()
    {
        delete this->next;
    }
};

template <typename T>
struct Map
{
    Node<T> **buckets;
    int size;
    int numBuckets;

    Map()
    {
        this->size = 0;
        this->numBuckets = 5;
        this->buckets = new Node<T> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~Map()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }
};

// int size()
// {
//     return count;
// }

Map<int> *m;

void rehash();

int getSize()
{
    return m->size;
}

int getBucketIndex(string key)
{
    int hashCode = 0;
    int currentCoeff = 1;
    for (int i = key.length() - 1; i >= 0; i--)
    {
        hashCode += key[i] * currentCoeff;
        hashCode = hashCode % m->numBuckets;
        currentCoeff *= 37;
        currentCoeff = currentCoeff % m->numBuckets;
    }
    return hashCode % m->numBuckets;
}

int getValue(string key)
{
    int bucketIndex = getBucketIndex(key);
    Node<int> *head = m->buckets[bucketIndex];
    while (head != NULL)
    {
        if (head->key == key)
            return head->value;
        head = head->next;
    }
    return 0;
}

void insert(string key, int value)
{
    int bucketIndex = getBucketIndex(key);
    Node<int> *head = m->buckets[bucketIndex];
    while (head != NULL)
    {
        if (head->key == key)
        {
            head->value = value;
            return;
        }
        head = head->next;
    }
    head = m->buckets[bucketIndex];
    Node<int> *temp = new Node<int>(key, value);
    temp->next = head;
    m->buckets[bucketIndex] = temp;
    m->size++;
    double loadFactor = (1.0 * m->size) / m->numBuckets;
    if (loadFactor > 0.7)
        rehash();
}

void rehash()
{
    Node<int> **temp = m->buckets;
    m->buckets = new Node<int> *[2 * m->numBuckets];
    for (int i = 0; i < 2 * m->numBuckets; i++)
    {
        m->buckets[i] = NULL;
    }
    int oldNumBuckets = m->numBuckets;
    m->numBuckets *= 2;
    m->size = 0;
    for (int i = 0; i < oldNumBuckets; i++)
    {
        Node<int> *head = temp[i];
        while (head != NULL)
        {
            string key = head->key;
            int value = head->value;
            insert(key, value);
            head = head->next;
        }
    }
    for (int i = 0; i < oldNumBuckets; i++)
    {
        Node<int> *head = temp[i];
        delete head;
    }
    delete[] temp;
}

int removeElement(string key)
{
    int bucketIndex = getBucketIndex(key);
    Node<int> *head = m->buckets[bucketIndex];
    Node<int> *prev = head;
    while (head != NULL)
    {
        if (head->key == key)
        {
            int temp = head->value;
            prev->next = head->next;
            head->next = NULL;
            delete head;
            m->size -= 1;
            return temp;
        }
        prev = head;
        head = head->next;
    }
    return 0;
}

double getLoadFactor()
{
    return (1.0 * m->size) / m->numBuckets;
}

/* COMPLEXITY ANALYSIS
* Hash computation time = O(L) where L is length of string key.
* On an average, there will be n/b elements in a bucket, where total elements are n and buckets are b
* (n/b) <- Load Factor
* We try to ensure that load factor is less than 0.7 
* In case this load factor increases, we increase the bucket size and do rehashing
*
*
*
*
*
*
*
*
*
*
*/

int main()
{
    m = new Map<int>();
    for (int i = 1; i <= 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        insert(key, i);
        cout << "LF = " << getLoadFactor() << endl;
    }
    cout << "Size : " << getSize() << endl;
    cout << getValue("abc3") << endl;
    cout << getValue("abc7") << endl;
    int re = removeElement("abc4");
    cout << "Removed Element = " << re << endl;
    re = removeElement("abc7");
    cout << "Removed Element = " << re << endl;
    cout << "Size : " << getSize() << endl;
}