// COMSC-210 | Lab 21 | Dat Hoang Vien
// IDE used: Visual Studio Code

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
    // Names
    const string nameList[NAMES] = {"Tiny", "Old", "Mature", "Senior", "Junior", "Baby", "Teen", "Elder",
                                    "Boss", "Legend", "Godlike", "Goober", "Speedy", "Chunky", "Smarty"};
    // Colors
    const string colorList[COLORS] = {"White", "Black", "Brown", "Gray", "Gold", "Red", "Yellow", "Orange",
                                    "Cream", "Mauve", "Silver", "Tan", "Beige", "Copper", "Ivory"};

public:
};