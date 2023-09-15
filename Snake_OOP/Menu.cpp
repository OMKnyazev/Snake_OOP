#include "Menu.h"

Menu::Menu()
{
    menuItems.push_back({ " START GAME ", 7, true });
    menuItems.push_back({ " EXIT ", 7, false });
}


Menu::~Menu()
{

}

//void Menu::color(int color)
//{
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}

//void Menu::gotoxy(int x, int y)
//{
//    COORD c;
//    c.X = x;
//    c.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
//}

//void ConsoleCursorVisible(bool show)
//{
//    CONSOLE_CURSOR_INFO structCursorInfo;
//    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
//    structCursorInfo.bVisible = show; // change cursor visibility
//    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
//}


void Menu::showMenu()
{
    std::cout << "Welcome to SNAKE" << std::endl;
    std::cout << "===============O~";
    CursorSetting::consoleCursorVisible(false);
    while (true)
    {
        for (int i = 0; i < static_cast<int>(menuItems.size()); i++)
        {
            bool bIsMenuItemActive = (counter == i);

            menuItems[i].active = bIsMenuItemActive;
        }

        CursorSetting::gotoxy(2, 2);
        CursorSetting::color(menuItems[0].active ? 10 : 7);
        std::cout << " START GAME ";

        CursorSetting::gotoxy(4, 3);
        CursorSetting::color(menuItems[1].active ? 10 : 7);
        std::cout << " EXIT ";

        key = _getch();

        if ((key == 80 || key == 115 || key == 83)) // 80 = down arrow key
        {
            counter++;
            if (counter > static_cast<int>(menuItems.size()) - 1)
            {
                counter = static_cast<int>(menuItems.size()) - 1;
            }
        }
        else if ((key == 72 || key == 119 || key == 87) && (counter >= 1 && counter <= 2)) //72 = down arrow key
        {
            counter--;
            if (counter < 0)
            {
                counter = 0;
            }
        }

        if (key == '\r') // carriage return = enter key
        {
            if (menuItems[0].active == true)
            {
                break;
            }
            else {
                exit(0);
            }
        }
    }
}