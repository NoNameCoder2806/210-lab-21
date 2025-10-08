// COMSC-210 | Lab 21 | Dat Hoang Vien
// IDE used: Visual Studio Code

#pragma once

// Libraries
#include <iostream>
#include <string>
using namespace std;

// Constants
const int MAX_AGE = 20;        // The maximum age of a Goat
const int NAMES = 15;          // The number of names
const int COLORS = 15;         // The number of colors

// Goat class
class Goat
{
private:
    int age;             // The age of the Goat object
    string name;         // The name of the Goat object
    string color;        // The color of the Goat object

    // Constant arrays
    // Names list
    inline static const string nameList[NAMES] = {
        "Tiny", "Old", "Mature", "Senior", "Junior", "Baby", "Teen", "Elder",
        "Boss", "Legend", "Godlike", "Goober", "Speedy", "Chunky", "Smarty"
    };
    // Colors list
    inline static const string colorList[COLORS] = {
        "White", "Black", "Brown", "Gray", "Gold", "Red", "Yellow", "Orange",
        "Cream", "Mauve", "Silver", "Tan", "Beige", "Copper", "Ivory"
    };

public:
    // Constructors
    Goat()                                 // Default constructor
    {
        age = rand() % MAX_AGE + 1;                // Randomly picked an age for the Goat
        name = nameList[rand() % NAMES];           // Randomly picked a name for the Goat
        color = colorList[rand() % COLORS];        // Randomly picked a color for the Goat
    }

    Goat(int a, string n, string c)        // Parameter constructor
    {
        age = a;
        name = n;
        color = c;
    }

    // Accessors / Getters
    int getAge() const
    {
        return age;
    }

    string getName() const
    {
        return name;
    }

    string getColor() const
    {
        return color;
    }

    // Mutators / Setters
    void setAge(int a)
    {
        age = a;
    }

    void setName(string n)
    {
        name = n;
    }

    void setColor(string c)
    {
        color = c;
    }

    // Operators
    /*
        operator==()
        Compares this Goat object with another Goat object to check for equality.
        Arguments:
            - g: a reference to another Goat object
        Return:
            - true if both Goats have the same age, name, and color
            - false otherwise
    */
    bool operator==(const Goat& g) const
    {
        return age == g.getAge() && name == g.getName() && color == g.getColor();
    }

    /*
    operator!=()
    Compares this Goat object with another Goat object for inequality.
    Arguments:
        - g: a reference to another Goat object
    Return:
        - true if any of the data members (age, name, color) differ
        - false if all data members are the same
    */
    bool operator!=(const Goat& g) const
    {
        return !(*this == g);
    }

    // Member functions
    /*
        print()
        Prints the information of the Goat object
        Arguments: none
        Return: none
    */
    void print() const
    {
        // Print in the format of name(color, age)
        cout << name << " (" << color << ", " << age << ")";
    }
};