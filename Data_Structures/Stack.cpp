#include <iostream>

using namespace std;

class Node
{
public:
    int Data;
    Node *next;

    Node()
    {
        Data = 0;
        next = NULL;
    }
};

class Stack
{
private:
    Node *Top;

public:
    Stack()
    {
        Top = NULL;
    }

    bool IsEmpty()
    {
        return (Top == NULL);
    }

    void Push(int item)
    {
        Node *newNode = new Node;
        newNode->Data = item;

        if (IsEmpty())
            newNode->next = NULL;
        else
            newNode->next = Top;

        Top = newNode;
    }

    int Pop()
    {
        Node *del = Top;
        Top = Top->next;

        int Value = del->Data;
        delete del;
        return Value;
    }

    void Display()
    {
        Node *temp = Top;
        while (temp != NULL)
        {
            cout << " " << temp->Data;
            temp = temp->next;
        }
    }

    int Peek()
    {
        return Top->Data;
    }

    int Count()
    {
        int counter = 0;
        Node *temp = Top;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }

        return counter;
    }

    bool isFound(int item)
    {
        Node *temp = Top;
        while (temp != NULL)
        {
            if (temp->Data == item)
                return true;

            temp = temp->next;
        }
        return false;
    }
};
int main()
{

    Stack test;

    cout << "Empty : " << test.IsEmpty() << endl;
    cout << "\nCount = " << test.Count() << endl;

    int item;
    cout << "Enter the first item : ";
    cin >> item;
    test.Push(item);
    cout << "Stack = ";
    test.Display();
    cout << "\nCount = " << test.Count() << endl;

    cout << "\nEnter the second item : ";
    cin >> item;
    test.Push(item);
    cout << "Stack = ";
    test.Display();
    cout << "\nCount = " << test.Count() << endl;

    cout << "\nEnter the third item : ";
    cin >> item;
    test.Push(item);
    cout << "Stack = ";
    test.Display();
    cout << "\nCount = " << test.Count() << endl;

    cout << "Enter the item to search for : ";
    cin >> item;
    cout << "Found = " << test.isFound(item) << endl;

    cout << "Enter the item to search for : ";
    cin >> item;
    cout << "Found = " << test.isFound(item) << endl;

    cout << "\n";
    system("pause");

    return 0;
}