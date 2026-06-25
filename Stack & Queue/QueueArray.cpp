#include<iostream>
using namespace std;

class Queue
{
    int start, end, *q, size;

public:
    Queue(int capacity)
    {
        size = capacity + 1; // Because one slot is reserved to differentiate if the queue is full / empty
        q = new int[size];
        start = end = 0;
    }

    ~Queue()
    {
        delete[] q;
    }

    bool isEmpty()
    {
        return start == end;
    }

    bool isFull()
    {
        return (end + 1) % size == start;
    }

    void enQueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is full" <<'\n';
            return;
        }

        q[end] = element;
        end = (end + 1) % size; // NOTE: This means end always point to the space where incoming element can be inserted
    }

    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" <<'\n';
            return;
        }
        
        start = (start + 1) % size;
    }

    int rear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" <<'\n';
            return -1;
        }

        int elePos = (end == 0) ? size - 1 : end - 1; 
        return q[elePos];
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" <<'\n';
            return -1;
        }

        return q[start];
    }

};

int main()
{
    Queue qObj(10);

    qObj.enQueue(10);
    qObj.enQueue(20);
    qObj.enQueue(30);

    qObj.deQueue();
    qObj.enQueue(7);

    qObj.enQueue(11);
    qObj.enQueue(21);
    qObj.enQueue(31);

    cout << qObj.front() << '\n';
    cout << qObj.rear() << '\n';

    qObj.deQueue();
    qObj.deQueue();

    cout << qObj.front() << '\n';
    cout << qObj.rear() << '\n';

    return 0;
}

// T.C. = O(1) , S.C. = O(N)
// NOTE: This is an implementation for circular queue, for linear queue we can't move the end pointer to the start of the array
// The only change we need to do for linear array is that whenever we are doing dequeue, remove the first element, then move all the rest of elements to the left by 1 -> O(N)
// Advantage of cicrcular queue over linear queue: Maximum space utilization in less time