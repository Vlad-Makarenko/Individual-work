//
// Created by Acer on 28.05.2021.
//

/**
 * @file Menu.h
 * @brief Файл класом-меню
 *
 * @author Makarenko V.
 * @date 26-may-2021
 * @version 1.0
 */

#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include "Controller.h"

/**
 * Клас-меню
 */
class Menu {
    Controller controller;
public:
    /**
    * Конструктор за замовчуванням
    */
    Menu() = default;
    /**
     * Деструктор
     */
    ~Menu() = default;

    /**
     * Метод запуску програми
     *
     * Метод викликає метод ShowMenu та взалежності від вибраною користувачем
     * дії викликає відвповідний метод роботи з колекцією
     */
    void Run();

    /**
     * Метод відображення меню дій
     *
     * Метод виводить на екран варіанти роботи з колекцєю, та приймає від користувача
     * вибраний вибрану дію
     */
    int ShowMenu() const;
};


#endif //MAIN_CPP_MENU_H
