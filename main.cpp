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
    int mapHeight, mapWidth, width, height, option, x, y, buildOpt;
    bool overlap, outOfBounds;

    cout << "Enter area height width" << endl;
    cin >> mapHeight >> mapWidth;

    Buildings area[mapHeight][mapWidth];

    for (int a = 0; a < mapHeight; a++) {
        for (int b = 0; b < mapWidth; b++) {
            area[a][b] = Empty;
        }
    }

    do {
        mainMenu();
        cout << "Option: ";
        cin >> option;

        switch (option) {
            ////////// add building / clear area //////////
            case 1:
                buildingsMenu();
                cout << "Option: ";
                cin >> buildOpt;
                cout << "Enter y / x position" << endl;
                cin >> y >> x;
                cout << "enter building height / width" << endl;
                cin >> height >> width;

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
                // check vor corss section with outher buildings
                for (int a = y; a < y + height; a++) {
                    for (int b = x; b < x + width; b++) {
                        if (area[a][b] != Empty){
                            overlap = true;
                        }
                    }
                }
                // check for out of bounds
                if (x + width > mapWidth || y + height > mapHeight) {
                    outOfBounds = true;
                }

                if (overlap) {
                    cout << "Overlap detected" << endl;
                }

                if (outOfBounds) {
                    cout << "Out of bounds" << endl;
                } else {
                    for (int a = y; a < y + height; a++) {
                        for (int b = x; b < x + width; b++) {
                            area[a][b] = selected;
                        }
                    }
                }
                break;
            ////////// print map //////////
            case 2:
                for (int a = 0; a < mapHeight; a++) {
                    for (int b = 0; b < mapWidth; b++) {
                        cout << area[a][b] << " ";
                    }
                    cout << endl;
                }
                break;
            ////////// map legend //////////
            case 3:
                mapLegend();
        }
    } while (option != 0);
}