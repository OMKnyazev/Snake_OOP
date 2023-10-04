#pragma once
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <iostream>
#include "CursorSetting.h"

class Menu
{
private:
    struct menuItem
    {
        std::string name;
        int color = 7;
        bool active = false;
    };

    int counter = 0;
    char key = int(-1);
    std::vector<menuItem> menuItems;

public:
    Menu();
    ~Menu();

    void showMenu();
};

