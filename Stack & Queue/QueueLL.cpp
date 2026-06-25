#include<iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;

    Node(int data) : value(data), next(NULL){}
};

class Queue
{
    Node* start; 
    Node* end;
    int size;

public:
    Queue() : start(NULL), end(NULL), size(0) {}

    ~Queue()
    {
        while(!isEmpty())
        {
            deQueue();
        }
    }

    int isEmpty()
    {
        return start == NULL;
    }

    void enQueue(int data)
    {
        Node* newNode = new Node(data);
        if (isEmpty())
            start = end = newNode;
        else
        {
            end->next = newNode;
            end = newNode;
        }
        size ++;
    }

    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" <<'\n';
            return;
        }

        Node* oldNode = start;
        start = start->next;

        // NOTE: When there is a single node, start will already point to NULL because of the previous step
        // With this we're ensuring end is also pointing to NULL
        if (start == NULL)
            end = NULL;

        delete oldNode;
        size --;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    Queue qObj;

    qObj.enQueue(10);
    qObj.enQueue(20);
    qObj.enQueue(30);

    qObj.deQueue();
    qObj.enQueue(7);

    qObj.enQueue(11);
    qObj.enQueue(21);
    qObj.enQueue(31);

    cout << qObj.getSize() << '\n';

    qObj.deQueue();
    qObj.deQueue();

    cout << qObj.getSize() << '\n';

    return 0;
}