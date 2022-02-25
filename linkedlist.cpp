#include <iostream>
using namespace std;

//***************
// unordered linked list
//***************

template <class Type>
struct Node
{

    Type data;
    Node *link;
};

template <class Type>
class linkedList
{
private:
    Node<Type> *first;
    Node<Type> *last;
    Node<Type> *before_cur_node;
    int count;

public:
    //**********
    // constructors and destructor
    //**********
    linkedList();
    linkedList(const linkedList<Type> &anotherList)
    {
        copy(anotherList);
    }
    ~linkedList();

    //*************
    //*************
    int Length() const;
    //******************
    // return size of array
    //******************
    bool IsEmptyList() const;
    //*******************
    // check if list emtpy
    //*******************
    bool Insert(const Type &);
    //****************************
    //***************************
    int Search(const Type &) const; // return index node;
    bool Delete(const Type &);      // delete node
    void print() const;             // print all nodes;
    Type front() const;             // retrun data in first node;
    Type back() const;              // retrun data in last node;
    Node<Type> *begin() const;      // return pointer to first node
    Node<Type> *end() const;
    void reverse();
    void destroy();
    void copy(const linkedList<Type> &);
};

//*********
//*********
template <class Type>
linkedList<Type>::linkedList()
{
    first = NULL;
    last = NULL;
    before_cur_node = NULL;
    count = 0;
}
//*********
//*********
// here copy constructor

//*********
//*********
template <class Type>
linkedList<Type>::~linkedList()
{
    destroy();
    delete first;
    delete last;
}
//*********
//*********
template <class Type>
bool linkedList<Type>::IsEmptyList() const
{
    if (count == 0)

        return true;
    else
        return false;
}

//*********
//*********
template <class Type>
int linkedList<Type>::Length() const
{
    return count;
}

//*********
//*********
template <class Type>
bool linkedList<Type>::Insert(const Type &data)
{
    Node<Type> *new_node = new Node<Type>;
    new_node->data = data;
    new_node->link = NULL;
    if (first == NULL)
    {
        new_node->link = NULL;
        first = new_node;
        last = new_node;
    }
    else
    {
        last->link = new_node;
        last = new_node;
    }
    count++;
    return true;
}

//*********
//*********
template <class Type>
void linkedList<Type>::print() const
{
    if (first == NULL)
        return;

    Node<Type> *current = first;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->link;
    }
}

//*********
//*********
template <class Type>
int linkedList<Type>::Search(const Type &data) const
{
    int index = 1;

    Node<Type> *current = first;

    while (current != NULL)
    {
        if (current->data == data)
            return index;
        current = current->link;
        index++;
    }

    return -1;
}

//*********
//*********
template <class Type>
bool linkedList<Type>::Delete(const Type &data)
{
    if (first == NULL)
        return false;

    Node<Type> *current = first;
    if (current->data == data)
    {
        first = first->link;
        delete current;
        count--;
        return true;
    }
    while (current != NULL)
    {
        if (current->data == data)
        {
            before_cur_node->link = current->link;
            delete current;
            count--;
            return true;
        }
        else
        {
            before_cur_node = current;
            current = current->link;
        }
    }

    return false;
}
//*********
//*********
template <class Type>
Type linkedList<Type>::back() const
{
    return last->data;
}

//*********
//*********
template <class Type>
Type linkedList<Type>::front() const
{
    return first->data;
}

//*********
//*********
template <class Type>
Node<Type> *linkedList<Type>::begin() const
{
    return first;
}

//*********
//*********
template <class Type>
void linkedList<Type>::reverse()
{

    Node<Type> *prevNode = NULL, *currentNode, *nextNode = NULL;
    last = first;
    currentNode = first;

    while (currentNode != NULL)
    {
        first = currentNode;

        nextNode = currentNode->link;
        currentNode->link = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
}

//*********
//*********
template <class Type>
void linkedList<Type>::destroy()
{
    while (first != NULL)
    {
        Node<Type> *current = first;
        first = first->link;
        delete current;
    }
    first = NULL;
    last = NULL;
    count = 0;
}

//*********
//*********
template <class Type>
Node<Type> *linkedList<Type>::end() const
{
    return last;
}

//********************
//********************
template <class Type>
void linkedList<Type>::copy(const linkedList<Type> &otherList)
{

    if ((first != NULL) || (otherList.first == NULL)) // if list is not empty and onther list not empty
    {
        destroy();
    }
    else
    {
        Node<Type> *current = otherList.first;
        count = otherList.count;

        //? copy first node
        first = new Node<Type>;
        first->data = current->data;
        first->link = NULL;
        last = first;

        current = current->link;

        while (current != NULL)
        {
            Node<Type> *new_node = new Node<Type>;
            new_node->data = current->data;
            new_node->link = NULL;

            last->link = new_node;

            last = new_node;

            current = current->link;
        }
    }
}
//*****************
//*****************
template <class Type>
void display(linkedList<Type> &List)
{
    Type data;

    while (true)
    {
        cout << "\n1 -   Insert\n";
        cout << "2 -   Delete\n";
        cout << "3 -   Search\n";
        cout << "4 -   Check is empty ? \n";
        cout << "5 -   Size\n";
        cout << "6 -   Reverse\n";
        cout << "7 -   Data in first\n";
        cout << "8 -   Data in last\n";
        cout << "9 -   Print\n";
        cout << "10 -  destory\n";
        cout << "11 -  Exist  \n\n";

        cout << "Choose: ";

        int ch;
        cin >> ch;

        if (ch > 8 && ch < 1)
        {
            cout << "\n invalid number\n\n";
        }
        else if (ch == 1)
        {
            cout << "\nEnter your data: ";
            cin >> data;
            bool check = List.Insert(data);
            if (check)
                cout << "\nInsert Successfully\n";
        }
        else if (ch == 2)
        {
            cout << "\nEnter your data: ";
            cin >> data;

            bool check = List.Delete(data);

            if (check)
                cout << "\ndelete Successfully\n";
            else
                cout << "\nData is not found";
        }
        else if (ch == 3)
        {
            cout << "\nEnter your data: ";

            cin >> data;

            int index = List.Search(data);

            if (index == -1)
                cout << "\ndata is not in list\n";
            else
                cout << "\ndata in index : " << index << endl;
        }
        else if (ch == 4)
        {
            bool check = List.IsEmptyList();
            if (check)
                cout << "\nlist is empty\n";
            else
                cout << "\nlist is not empty\n";
        }
        else if (ch == 5)
        {
            cout << "\nSize of list : " << List.Length() << "\n";
        }
        else if (ch == 6)
        {
            List.reverse();
            cout << "\nreverse Successfully.\n";
        }
        else if (ch == 7)
        {
            cout << "\ndata in first Node : " << List.front() << "\n";
        }
        else if (ch == 8)
        {
            cout << "\ndata in last Node : " << List.back() << "\n";
        }
        else if (ch == 9)
        {
            cout << "\n";
            List.print();
        }
        else if (ch == 10)
        {
            List.destroy();
        }
        else if (ch == 11)
        {
            cout << "\nTHANKS (:\n";
            break;
        }
    }
}

//******************
//  main function
//******************
int main()
{

    while (true)
    {
        cout << "1 - int\n";
        cout << "2 - char\n";
        cout << "3 - double\n";
        cout << "4 - float\n";
        cout << "5 - string\n";
        cout << "choose your data type: ";

        int ch;
        cin >> ch;

        if (ch == 1)
        {
            linkedList<int> list;
            display(list);
        }
        else if (ch == 2)
        {
            linkedList<char> list;
            display(list);
        }
        else if (ch == 3)
        {
            linkedList<double> list;
            display(list);
        }
        else if (ch == 4)
        {
            linkedList<float> list;
            display(list);
        }
        else if (ch == 5)
        {
            linkedList<string> list;
            display(list);
        }
        else
        {
            cout << "\ninvalid number\n\n";
            continue;
        }
        break;
    }
}