#include <iostream>

#include "menu/main_menu.h"
using namespace std;

int main()
{
    try {
        main_menu* mm1 = new main_menu();
        mm1->menu_loop();

        delete mm1;
        return 0;
    } catch (exception& e) {
        return 1;
    }
}
