#include <iostream>
#include <conio.h>
#include <exception>
#include <ctime>

using namespace std;

class Array
{
private:
    int size;
    int length;
    int *items;

public:
    Array(int arr_size) : size(arr_size), length(0)
    {
        items = new int[arr_size];
    }

    void Fill()
    {
        int num_of_items = 0;

        try
        {
            cout << "\nHow many items do you want to fill? ";
            cin >> num_of_items;
            if (num_of_items > size)
                throw num_of_items;
            else
            {
                for (int i = 0; i < num_of_items; i++)
                {
                    cout << "Value of item " << i << " = ";
                    cin >> items[i];
                    length++;
                }
            }
        }
        catch (int num_of_items)
        {
            cout << "\nThe number of items can't exceed the array size!.\n";
            Fill();
        }
    }

    void Display()
    {
        cout << "\nYour array is = [ ";

        for (int i = 0; i < length; i++)
        {
            cout << items[i] << " ";
        }
        cout << "]\n";
    }

    void Append(int newItem)
    {
        int *newArray = new int[size + 1];
        if (length < size)
        {
            items[length] = newItem;
            length++;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                newArray[i] = items[i];
            }
            newArray[length] = newItem;
            size++;
            length++;
            delete[] items;
            items = newArray;
        }
    }

    void Insert(int index, int newItem)
    {
        try
        {
            if (length == size)
                cout << "\nThe array is full!.\n";
            else if (index >= 0 && index < length)
            {
                for (int i = length; i > index; i--)
                {
                    items[i] = items[i - 1];
                }
                items[index] = newItem;
                length++;
            }
            else if (index < 0 || index >= size)
                throw index;
        }
        catch (int index)
        {
            cout << index << " is an invalid index!."
                 << "\n Enter a valid index: ";
            cin >> index;
            Insert(index, newItem);
        }
    }

    void Delete(int index)
    {
        length--;
        for (int i = index; i < length; i++)
            items[i] = items[i + 1];
    }

    int Search(int key)
    {
        try
        {
            int index = 0;
            for (index; index < length; index++)
            {
                if (items[index] == key)
                    return index;
            }
            throw key;
        }
        catch (int key)
        {
            cout << "\nThe value you are looking for ( " << key << " ) doesn't exist in this array!.\n";
            return -1;
        }
    }

    void Enlarge(int newSize)
    {
        int *old = items;
        items = new int[newSize];
        for (int i = 0; i < length; i++)
        {
            items[i] = old[i];
        }
        delete[] old;
        size = newSize;
    }

    void Merge(Array a)
    {
        int *old = items;
        size = size + a.getSize();
        items = new int[size];

        int i = 0;
        for (i; i < length; i++)
            items[i] = old[i];

        for (int j = 0; j < a.getLength(); j++)
            items[i++] = a.items[j];

        length += a.getLength();
        delete[] old;
    }

    int getSize() const
    {
        return size;
    }

    int getLength() const
    {
        return length;
    }
};

class Node
{
public:
    int Data;
    Node *next;
};

class LinkedList
{
public:
    Node *Head;

    LinkedList()
    {
        Head = NULL;
    }

    bool isempty()
    {
        return (Head == NULL);
    }

    void InsertFirst(int newItem)
    {
        Node *newnode = new Node;
        newnode->Data = newItem;

        if (isempty())
        {
            Head = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = Head;
            Head = newnode;
        }
    }

    void InsertBefore(int value, int newValue)
    {
        if (Search(value))
        {
            Node *temp = Head;
            Node *newNode = new Node;
            newNode->Data = newValue;

            while (temp->next != NULL && temp->next->Data != value)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;

            temp->next = newNode;
        }
        else
            cout << "\nSorry item not found!.\n";
    }

    void Append(int newItem)
    {
        if (isempty())
            InsertFirst(newItem);
        else
        {
            Node *temp = Head;

            Node *newNode = new Node;
            newNode->Data = newItem;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = NULL;
        }
    }

    void Delete(int item)
    {
        if (Head->Data == item)
        {
            Node* del = Head;
            Head = Head->next;

            delete del;
        }
        else
        {
            Node* temp = Head;
            while (temp->next->Data != item)
                temp = temp->next;

            Node* del = temp->next;

            temp->next = del->next;
            delete del;
        }
    }

    void Display()
    {
        Node *temp = Head;
        while (temp != NULL)
        {
            cout << temp->Data << " ";
            temp = temp->next;
        }
    }

    int Count()
    {
        int counter = 0;
        Node *temp = Head;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }

        return counter;
    }

    bool Search(int item)
    {
        bool found = false;
        Node *temp = Head;
        while (temp != NULL)
        {
            if (temp->Data == item)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }
};

int main()
{
    LinkedList list;
    cout << "Empty : " << list.isempty() << endl;

    int item;
    cout << "Enter the item to be stored in the linkedlist = ";
    cin >> item;
    list.InsertFirst(item);
    cout << "LinkedList = ";
    list.Display();

    int item1;
    cout << "\nEnter the item to be stored in the linkedlist = ";
    cin >> item1;
    list.InsertFirst(item1);
    cout << "LinkedList = ";
    list.Display();

    int item2;
    cout << "\nEnter the item to be stored in the linkedlist = ";
    cin >> item2;
    list.InsertFirst(item2);
    cout << "LinkedList = ";
    list.Display();

    cout << "\nNumber of nodes: " << list.Count() << endl;

    cout <<  "\nItem to be deleted: ";
    cin >> item;
    list.Delete(item);
    list.Display();

    cout << "\n";
    system("pause");
    return 0;
}