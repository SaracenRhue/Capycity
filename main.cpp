#include <iostream>
#include "buildings.cpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

void showMenu();
void resetArea();
void addBuilding();
void removeBuilding();
void showMap();

int main()
{
    int width, height;
    cout << "Enter area width" << endl;
    cin >> width;
    cout << "Enter area height" << endl;
    cin >> height;
    
    Buildings area [width][height];


    int option;
    do
    {
        showMenu();
        cout << "Option: ";
        cin >> option;

        switch (option)
        {
        case 0:
            resetArea();
            break;
        case 1: 
            addBuilding();
            break;
        case 2:
            removeBuilding();
            break;
        case 3:
            showMap();
            break;
        }
    } while (option != 4);
}

void showMenu()
{
    cout << "**********MENU**********" << endl;
    cout << "0) reset map" << endl;
    cout << "1) add building" << endl;
    cout << "2) remove building" << endl;
    cout << "3) show map" << endl;
    cout << "4) quit" << endl;
    cout << "************************" << endl;
}

