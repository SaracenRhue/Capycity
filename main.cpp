#include <iostream>
#include "buildings.cpp"
#include "menus.cpp"
using std::cin;
using std::cout;
using std::endl;

void mainMenu();
void buildingsMenu();
void mapLegend();

int main() {
    int aWidth, aHeight, width, height, option, x, y, buildOpt;
    cout << "Enter area width height" << endl;
    cin >> aWidth >> aHeight;

    Buildings area[aWidth][aHeight];

    for (int a = 0; a < aWidth; a++) {
        for (int b = 0; b < aHeight; b++) {
            area[a][b] = Empty;
        }
    }

    do {
        mainMenu();
        cout << "Option: ";
        cin >> option;

        switch (option) {
            ////////// reset map //////////
            case 1:  
                cout << "Enter area width / height" << endl;
                cin >> aWidth >> aHeight;

                for (int a = 0; a < aWidth; a++) {
                    for (int b = 0; b < aHeight; b++) {
                        area[a][b] = Empty;
                    }
                }
                break;
            ////////// add building / clear area //////////
            case 2:
                buildingsMenu();
                cout << "Option: ";
                cin >> buildOpt;
                cout << "Enter x / y position" << endl;
                cin >> x >> y;
                cout << "enter building width / height" << endl;
                cin >> width >> height;

                Buildings selected;
                switch (buildOpt) {
                    case 0:
                        selected = Empty;
                        break;
                    case 1:
                        selected = Waterpower;
                        break;
                    case 2:
                        selected = Windpower;
                        break;
                    case 3:
                        selected = Solarpower;
                        break;
                }

                for (int a = x; a < x + width; a++) {
                    for (int b = y; b < y + height; b++) {
                        area[a][b] = selected;
                    }
                }
                break;
            ////////// print map //////////
            case 3:
                for (int a = 0; a < aWidth; a++) {
                    for (int b = 0; b < aHeight; b++) {
                        cout << area[a][b] << " ";
                    }
                    cout << endl;
                }
                break;
            ////////// map legend //////////
            case 4:
                mapLegend();
        }
    } while (option != 0);
}