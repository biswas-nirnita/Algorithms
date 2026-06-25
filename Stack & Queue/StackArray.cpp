#include<iostream>
using namespace std;

class Stack
{
    int *st, top , size;

public:
    Stack(int capacity)
    {
        size = capacity;
        st = new int[size];
        top = -1;
    }

    ~Stack()
    {
        // NOTE: I need to do it explicitly because int* i.e., raw pointer, 
        // if I declare this using make_unique / unique & new then this manual deallocation is not needed
        delete[] st;
    }

    void push(int element)
    {
        // NOTE: This is because top = -1, increment first approach, 
        // If top is 0 then its an insert first approach, then overflow condition will be top == size
        if (top == size - 1)
        cout << "StacK Overflow!!\n";
        
        st[++top] = element;
    }

    int pop()
    {
        if (top == -1)
        cout << "Stack Underflow!!\n";

        return st[top--];
    }

    int getSize()
    {
        return top+1;
    }

    int getTopElement()
    {
        return st[top];
    }
};

int main()
{
    Stack stObj(10);

    stObj.push(10);
    stObj.push(20);
    cout << stObj.pop() << '\n';

    stObj.push(10);
    stObj.push(20);
    cout << stObj.pop() << '\n';

    cout << stObj.pop() << '\n';
    cout << stObj.pop() << '\n';
    stObj.push(20);
    cout << stObj.pop() << '\n';

    return 0;
}

// T.C. = O(1) , S.C = O(n) , n = size of stack

// NOTE: if it's a dynamic size array, need to declare resize funcion & while pushing back 
// if we reach the size then double the size, allocate memory on heap, copy the elements, delete the array & insert new element