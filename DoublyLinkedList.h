// COMSC-210 | Lab 21 | Dat Hoang Vien
// IDE used: Visual Studio Code

#pragma once

// Libraries
#include <iostream>
#include <string>
#include "Goat.h"
using namespace std;

// Constants
const int MIN_NR = 10;
const int MAX_NR = 99;
const int MIN_LS = 5;
const int MAX_LS = 20;

// DoublyLinkedList class
class DoublyLinkedList
{
private:
    // Node struct
    struct Node
    {
        Goat goat;         // Goat object
        Node *prev;        // Pointer to the previous node
        Node *next;        // Pointer to the next node

        // Default constructor for the Node struct
        Node(Goat g, Node *p = nullptr, Node *n = nullptr)
        {
            goat = g;        // Copy all the data from g
            prev = p;        // Set the previous pointer to null
            next = n;        // Set the next pointer to null
        }
    };

    Node *head;        // Pointer to the head of the Linked list
    Node *tail;        // Pointer to the tail of the Linked list

public:
    // Constructor
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor
    ~DoublyLinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Member functions
    /*
        push_back()
        Adds a value to the back (tail) of the doubly linked list.
        Arguments:
            - value: an integer representing the value to insert
        Return: none
    */
    void push_back(const Goat& g)
    {
        // Create a new node and pass the Goat object in
        Node *newNode = new Node(g);

        // If there's no tail, the list is empty
        if (!tail)
        {
            head = tail = newNode;
        }
        else        // If the list is not empty
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    /*
        push_front()
        Adds a value to the front (head) of the doubly linked list.
        Arguments:
            - value: an integer representing the value to insert
        Return: none
    */
    void push_front(const Goat& g)
    {
        // Create a new node and pass the Goat object in
        Node *newNode = new Node(g);

        // If there's no head, the list is empty
        if (!head)
        {
            head = tail = newNode;
        }
        else        // If the list is not empty
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    /*
        insert_after()
        Inserts a new value immediately after the specified position.
        Arguments:
            - value: an integer representing the value to insert
            - position: an integer (0-based index) where insertion occurs after
        Return: none
        Note: If position exceeds list size, insertion will fail with a message.
    */
    void insert_after(const Goat& g, int position)
    {
        if (position < 0)
        {
            cout << "Position must be >= 0." << endl;
            return;
        }
        Node *newNode = new Node(g);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;
        if (!temp)
        {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    /*
        delete_node()
        Deletes the first node found with the specified value.
        Arguments:
            - value: an integer representing the value to delete
        Return: none
        Note: If the value is not found, no deletion occurs.
    */
    void delete_node(const Goat& g)
    {
        if (!head)
            return; // Empty list
        Node *temp = head;
        while (temp && temp->goat != g)
            temp = temp->next;
        if (!temp)
            return; // Value not found
        if (temp->prev)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = temp->next; // Deleting the head
        }
        if (temp->next)
        {
            temp->next->prev = temp->prev;
        }
        else
        {
            tail = temp->prev; // Deleting the tail
        }
        delete temp;
    }

    /*
        print()
        Prints the linked list in forward order (head to tail).
        Arguments: none
        Return: none
    */
    void print()
    {
        Node *current = head;

        if (!current)
        {
            return;
        }

        while (current)
        {
            current->goat.print();
            current = current->next;
        }
        cout << endl;
    }

    /*
        print_reverse()
        Prints the linked list in reverse order (tail to head).
        Arguments: none
        Return: none
    */
    void print_reverse()
    {
        Node *current = tail;

        if (!current)
        {
            return;
        }

        while (current)
        {
            current->goat.print();
            current = current->prev;
        }
        cout << endl;
    }
};