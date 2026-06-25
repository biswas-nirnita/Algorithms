#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{
    Node* top;
    int size;

public:
    Stack() : top(nullptr) , size (0) {}

    // NOTE: Stack object might have nodes in-memory if not all popped, hence popping / deleting all allocated nodes in destructor
    ~Stack()
    {
        while(size != 0)
        {
            pop();
        }
    }

    // NOTE: (top) 11 : NULL => (top) 22 : -> 11 : NULL
    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size ++;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow!!\n";
            return;
        }

        Node* oldNode = top;
        top = top->next;
        delete oldNode;
        size --;
    }

    int getTopElement()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow!!\n";
            return -1;
        }

        return top->data;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    Stack stObj;

    stObj.push(10);
    stObj.push(20);
    stObj.pop();
    cout << stObj.getTopElement() << '\n';

    stObj.push(10);
    stObj.push(20);
    stObj.pop();
    cout << stObj.getTopElement() << '\n';

    stObj.pop();
    cout << stObj.getTopElement() << '\n';
    stObj.pop();
    cout << stObj.getTopElement() << '\n';

    stObj.push(20);
    stObj.pop();
    cout << stObj.getTopElement() << '\n';

    return 0;
}

// T.C. = O(1) , S.C = O(n)
// Advantage of stack with LL over stack with Array
// 1. Sizing : Stack with LL gives dynamic sizing benefits, but even if we achieve it with dynamic array / vector there is one more problem
// 2. Push T.C. : For LL, push T.C. is always constant, each time push happens it creates a new node & attches, but for dynamic size array once the size is full, 
//                it doubles the size, copy all the elements, then insert new element, hence T.C. drops to O(n)
// Problem of using LL : Memory overhead of maintaing pointer for each node