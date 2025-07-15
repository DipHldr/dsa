#include <iostream>
using namespace std;

class stacks
{
    // properties
public:
    int *arr;
    int size;
    int top;
    // behaviour
    stacks(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty " << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    stacks st(5);

    st.push(33);
    st.push(43);
    st.push(23);
    st.push(56);
    st.push(35);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    // st.pop();
    // cout<<st.peek()<<endl;
    if (st.isEmpty())
        cout << "Bruh! The Stack is empty" << endl;
    else
        cout << "Stack is not empty bruh!!" << endl;
}