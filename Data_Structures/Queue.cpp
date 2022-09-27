#include <iostream>

using namespace std;

class Node
{
public:
    int Data;
    Node *Next;

    Node()
    {
        Data = 0;
        Next = NULL;
    }
};

class Queue
{
private:
    Node *Head;
    Node *Tail;

public:
    Queue()
    {
        Head = NULL;
        Tail = NULL;
    }

    bool isEmpty()
    {
        return (Head == NULL);
    }

    bool isFull()
    {
        Node* ptr = new Node;
        
        if(ptr == NULL)
        {
            cout << "\nThe heap memory is full!.\n";
            return true;
        }else
            return false; 
    }

    void Enqueue(int item)
    {
        Node *newNode = new Node;
        newNode->Data = item;
      
        if (isEmpty())
            Head = Tail = newNode;
        else
        {
            Tail->Next = newNode;
            Tail = newNode;
        }
       
        newNode->Next = NULL;
    }

    int Dequeue()
    {
        int Value = 0;
        if(isEmpty())
            cout << "\nThe queue is empty!.\n";
        else
        {
            Value = Head->Data;
            Node* del = Head;

            if(Head == Tail)
                 Head = Tail =NULL;
            else
                Head = Head->Next;

            delete del;
        }
        return Value;
    }

    int Peek()
    {
        return Head->Data;
    }

    void Display()
    {
        if(isEmpty())
            cout << "\nNo items to display!.\n";
        else
        {
            Node* traverse = Head;
            while(traverse != NULL)
            {
                cout << " " << traverse->Data;
                traverse = traverse->Next;
            }
        }
    }

    void Clear()
    {
        while(!isEmpty())
            Dequeue();
    }

    int Count()
    {
        int counter = 0;
        Node* traverse = Head;
        while(traverse != NULL)
        {
            counter++;
            traverse = traverse->Next;
        }
        return counter;
    }

    bool isFound(int item)
        {
            Node *temp = Head;
            while (temp != NULL)
            {
                if (temp->Data == item)
                    return true;

                temp = temp->Next;
            }
            return false;
        }
};

int main()
{

    Queue test;

    cout << "Empty : " << test.isEmpty() << endl;
    cout << "\nCount = " << test.Count() << endl;

    int item;
    cout << "Enter the first item : ";
    cin >> item;
    test.Enqueue(item);
    cout << "Stack = ";
    test.Display();
    cout << "\nCount = " << test.Count() << endl;

    cout << "\nEnter the second item : ";
    cin >> item;
    test.Enqueue(item);
    cout << "Stack = ";
    test.Display();
    cout << "\nCount = " << test.Count() << endl;

    cout << "\nEnter the third item : ";
    cin >> item;
    test.Enqueue(item);
    cout << "Stack = ";
    test.Display();
    cout << "\nCount = " << test.Count() << endl;

    test.Clear();

    test.Display();
    cout << "\n";
    system("pause");
    return 0;
}