/**
 * @mainpage
 * # Загальне завдання
 * **Виконати** розрахункове завдання;
 *
 * @author Makarenko V.
 * @date 26-may-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл запуску програми, та демонстрації меню
 *
 * @author Makarenko V.
 * @date 26-may-2021
 * @version 1.0
 */

#include "Menu.h"
//#include "Controller.h"
//#include "Container.h"
//#include "Backpack.h"


/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення класу-меню
 * - запуск програми
 * @return успішний код повернення з програми (0)
 */

int main() {

    Menu menu;
    menu.Run();

    return 0;
}