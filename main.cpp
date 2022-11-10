#include <iostream>
#include "buildings.cpp"
using std::cin;
using std::cout;
using std::endl;

void mainMenu();
void buildingsMenu();
void mapLegend();

int main()
{
    int width, height, option, x, y, buildOpt;
    cout << "Enter area width" << endl;
    cin >> width;
    cout << "Enter area height" << endl;
    cin >> height;

    Buildings area[width][height];

    for (int a = 0; a < width; a++)
    {
        for (int b = 0; b < height; b++)
        {
            area[a][b] = Empty;
        }
    }

    do
    {
        mainMenu();
        cout << "Option: ";
        cin >> option;

        switch (option)
        {
        case 1: //reset map
            cout << "Enter area width" << endl;
            cin >> width;
            cout << "Enter area height" << endl;
            cin >> height;

            for (int a = 0; a < width; a++)
            {
                for (int b = 0; b < height; b++)
                {
                    area[a][b] = Empty;
                }
            }
            break;
        case 2: //add building
            buildingsMenu();
            cout << "Option: ";
            cin >> buildOpt;
            cout << "Enter x position" << endl;
            cin >> x;
            cout << "Enter y position" << endl;
            cin >> y;
            switch (buildOpt)
            {
                case 1:
                area[x][y] = Waterpower;
                break;
                case 2:
                area[x][y] = Windpower;
                break;
                case 3:
                area[x][y] = Solarpower;
                break;
            }
            break;
        case 3: //remove building
            cout << "Enter x position" << endl;
            cin >> x;
            cout << "Enter y position" << endl;
            cin >> y;
            area[x][y] = Empty;
            break;
        case 4: //print area map
            for (int a = 0; a < width; a++)
            {
                for (int b = 0; b < height; b++)
                {
                    cout << area[a][b] << " ";
                }
                cout << endl;
            }
            break;
        case 5: //print map legend
            mapLegend();
        }
    } while (option != 0);
}

void mainMenu()
{
    cout << "**********MENU**********" << endl;
    cout << "1) reset map" << endl;
    cout << "2) add building" << endl;
    cout << "3) remove building" << endl;
    cout << "4) show map" << endl;
    cout << "5) map legend" << endl;
    cout << "0) quit" << endl;
    cout << "************************" << endl;
}

void buildingsMenu()
{
    cout << "**********BUILDINGS**********" << endl;
    cout << "1) water power" << endl;
    cout << "2) wind power" << endl;
    cout << "3) solar power" << endl;
    cout << "*****************************" << endl;
}

void mapLegend()
{
    cout << "**********MAP LEGEND**********" << endl;
    cout << "0) empty" << endl;
    cout << "1) water power" << endl;
    cout << "2) wind power" << endl;
    cout << "3) solar power" << endl;
    cout << "*****************************" << endl;
}