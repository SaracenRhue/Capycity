#include <iostream>
using std::cout;
using std::endl;

void mainMenu() {
    cout << "**************MENU**************" << endl;
    cout << "1) add building / clear area" << endl;
    cout << "2) show map" << endl;
    cout << "3) map legend" << endl;
    cout << "0) quit" << endl;
    cout << "********************************" << endl;
}

void buildingsMenu() {
    cout << "**********BUILDINGS**********" << endl;
    cout << "0) empty" << endl;
    cout << "1) water power" << endl;
    cout << "2) wind power" << endl;
    cout << "3) solar power" << endl;
    cout << "*****************************" << endl;
}

void mapLegend() {
    cout << "**********MAP LEGEND**********" << endl;
    cout << "0) empty" << endl;
    cout << "1) water power" << endl;
    cout << "2) wind power" << endl;
    cout << "3) solar power" << endl;
    cout << "*****************************" << endl;
}