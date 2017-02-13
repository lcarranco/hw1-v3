//doublelinkedlist.cpp

#include <iostream>
#include <string>
#include "doublelinkedlist.h"

using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
    head = NULL;
    tail = NULL;
    counter = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
    DestroyList();
}

//User defined constructor
DoubleLinkedList::DoubleLinkedList(const std::string& num, int digitsPerNode)
{
    // int size = num.length();
    // int m = size / digitsPerNode; //Gives the amount of nodes
    // int n = size % digitsPerNode; //Gives the amount of characters in the first node
    // Node* temp; //Creates temp pointer
    // Node* current; //Creates current pointer
    // int value = 0;
    // int index = size - 1; //Creates an index that is zero based
    // int p = index - digitsPerNode;
    // for (int i = m; i > 0; i--)
    // {
    //     temp = new Node();
    //     value = stoi(num[i]);
    //     temp->num = value;
    //     temp->next = head;
    //     head = temp;
    //     current = temp;
    //     counter++;
    // }
    // head->prev = NULL;
    // int counter2 = 1;
    // while (counter2 < counter)
    // {
    //     current = current->next;
    //     current->prev = temp;
    //     temp = temp->next;
    //     counter2++;
    // }
}

DoubleLinkedList::DoubleLinkedList(int digitsPerNode)
{

}

//Copy constructor
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& list)
{
    CopyList(list);
}

DoubleLinkedList& DoubleLinkedList::operator = (const DoubleLinkedList& list)
{

}

DoubleLinkedList& DoubleLinkedList::operator + (const DoubleLinkedList& list) const
 {
//     DoubleLinkedList sum;
//     Node* current = GetTail();
//     Node* current2 = list.GetTail();
//     int carry = 0;
//     while (current != NULL && current2 != NULL)
//     {
//         sum.InsertFirst((current->num + current2->num + carry) % 10);
//         carry = (current->num + current2->num + carry) / 10;
//         current = current->prev;
//         current2 = current2->prev;
//     }
//     while (current == NULL && current2 == NULL && carry > 0)
//     {
//         sum.InsertFirst(carry);
//         while (current != NULL || current2 != NULL)
//         {
//             if (current2 == NULL && current != NULL)
//             {
//                 int sum1;
//                 sum1 = current->num + carry;
//                 sum.InsertFirst(sum1);
//             }
//             else if (current == NULL && current2 != NULL)
//             {
//                 int sum1;
//                 sum1 = current2->num + carry;
//                 sum.InsertFirst(sum1);
//             }
//         }
//     }
}

DoubleLinkedList& DoubleLinkedList::operator * (const DoubleLinkedList& list) const
{

}

const Node* DoubleLinkedList::GetHead() const
{
    // Node* temp = head;
    // int value= 0;
    // value = temp->num;
    // temp = NULL;
    // delete temp; 
    // return value;
}

const Node* DoubleLinkedList::GetTail() const
{
    // Node* current;
    // while (current->next != NULL)
    // {
    //     current = current->next;
    // }
    // return current;
}

void DoubleLinkedList::Append(Node* node)
{
    Node* temp = node; //temp pointer is pointing to the node passed in the function parameter
    temp->next = NULL; //The node is pointing to NULL
    tail->next = temp; //tail pointer is pointing to temp
    temp->prev = tail; //temp pointer is pointing to tail
    tail = temp; //Move tail pointer to the last node which is the node that temp is pointing to
    temp = NULL; //temp pointer is now pointing to NULL
    delete temp; //Can now safely delete the temp pointer
    counter++;
}

void DoubleLinkedList::Print() const
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->num << endl;
        temp = temp->next;
    }
    delete temp;
}

void DoubleLinkedList::DestroyList()
{
    Node* temp; //Create temp pointer to deallocate the memory occupied by the node
    while (head != NULL) //Run the loop till head reaches NULL
    {
        temp = head; //Place temp pointer at the beginning of the list
        head = head->next; //Advance head pointer to the next node
        delete temp; //Deallocate the node
    }
    tail = NULL; /*When the loop exits head is initialized to NULL
                    Now initialize tail to NULL*/
    counter = 0; //Reset the counter to zero
}

void DoubleLinkedList::InitializeList()
{
    DestroyList(); //If the list has any nodes then delete them
}

int DoubleLinkedList::LengthOfList() const
{
    return counter;
}

void DoubleLinkedList::InsertFirst(int val)
{

}

void DoubleLinkedList::CopyList(const DoubleLinkedList& list)
{
    Node* temp; //temp ponter to create a node
    Node* current; //current pointer to traverse the list
    if (head != NULL) //if the list is nonempty then delete the list
    {
        DestroyList();
    }
    else if (list.head == NULL) //if the list that was passed through the parameter is empty
    {
        head = NULL;
        tail = NULL;
        counter = 0;
    }
    else
    {
        current = list.head;
        counter = list.counter;
        head = new Node();
        head->num = current->num;
        head->next = NULL;
        head->prev = NULL;
        counter++;
        tail = head;
        current = current->next;
        while (current != NULL)
        {
            temp = new Node();
            temp->num = current->num;
            temp->next = NULL;
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            current = current->next;
            counter++;
        }
        temp = NULL;
        delete temp;
    }
}