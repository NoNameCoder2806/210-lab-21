// COMSC-210 | Lab 21 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "Goat.h"
#include "DoublyLinkedList.h"
using namespace std;

// Constants
const int SIZE = 3;
const int MIN_GOAT = 5;
const int MAX_GOAT = 20;

// Main function
int main()
{
    // Call srand()
    srand(time(0));

    // Create a DoublyLinkedList object
    DoublyLinkedList dll;

    // Declare an int to store the number of Goat objects
    int count = rand() % (MAX_GOAT - MIN_GOAT + 1) + MIN_GOAT;

    // Create the Goat objects
    for (int i = 0; i < count; i++)
    {
        Goat g;                // Create a temporary Goat object
        dll.push_back(g);      // Push the Goat object into the Linked list
    }

    // Print the Goat objects in the Linked list
    cout << "Forward: " << endl;         // Forward
    dll.print();
    cout << "Backward: " << endl;        // Backward
    dll.print_reverse();

    return 0;
}