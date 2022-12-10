#include <iostream>
#include "buildings.cpp"
#include "menus.cpp"
using std::cin;
using std::cout;
using std::endl;

void mainMenu();
void buildingsMenu();
void mapLegend();
void cleanMap(Buildings** area, int mapHeight, int mapWidth);
void printMap(Buildings** area, int mapHeight, int mapWidth);
void build(Buildings** area, int mapHeight, int mapWidth);

int main() {
int mapHeight, mapWidth, option;
cout << "Enter area height width" << endl;
cin >> mapHeight >> mapWidth;
// create pointer to array
Buildings** area = new Buildings*[mapHeight];
for (int i = 0; i < mapHeight; i++) {
    area[i] = new Buildings[mapWidth];
}
cleanMap(area, mapHeight, mapWidth);
do {
    mainMenu();
    cout << "Option: ";
    cin >> option;
    switch (option) {
        case 1:
            build(area, mapHeight, mapWidth);
            break;
        case 2:
            printMap(area, mapHeight, mapWidth);
            break;
        case 3:
            mapLegend();
    }
} while (option != 0);
}



void cleanMap(Buildings** area, int mapHeight, int mapWidth) {
    for (int a = 0; a < mapHeight; a++) {
        for (int b = 0; b < mapWidth; b++) {
            area[a][b] = Empty;
        }
    }
}
void printMap(Buildings** area, int mapHeight, int mapWidth) {
    for (int a = 0; a < mapHeight; a++) {
        for (int b = 0; b < mapWidth; b++) {
            cout << area[a][b] << " ";
        }
        cout << endl;
    }
}
void build(Buildings** area, int mapHeight, int mapWidth){
    int width, height, x, y, buildOpt;
    bool overlap = false;
    bool outOfBounds = false;
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
            if (area[a][b] != 0) {
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
}