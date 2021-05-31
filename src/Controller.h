#pragma once
//
// Created by Vlad on 26.05.2021.
//

/**
 * @file Controller.h
 * @brief Файл з класом-контролером
 *
 * @author Makarenko V.
 * @date 26-may-2021
 * @version 1.0
 */
#ifndef RGZ_CONTROLLER_H
#define RGZ_CONTROLLER_H

#include "Backpack.h"
#include "Container.h"

/**
 * Клас-контролер
 */
class Controller {
    List list;
public:
    /**
     * Конструктор за замовчуванням
     */
    Controller();
    /**
     * Деструктор
     */
    ~Controller();

    /**
     * "Гетер"
     *
     * Повертає колекцію list
     */
    List* getList();

    /**
     * Метод читання з файлу
     *
     * Метод читає данні з заданого файлу та записує їх в контейнер
     */
    bool ReadFromFile(const string &path);

    /**
     * Метод виводу в файл
     *
     * Метод виводить колекцію в файл
     */
    void WriteToFile();

    /**
     * Метод сортування
     *
     * Метод сортує масив структур за заданим критерієм та напрямом
     * @param criterion критерії за яким буде відбуватись сортування
     * @param direction напрям сортування
     */
    void SortByCriterion(int criterion, bool direction);

    /**
     * Метод пошуку об'єкту
     *
     * Метод знаходить серед колекції німецький міський рюкзак
     * @return контейнер зі знайденими об'єктами
     */
    vector<LeatherBackpack*> FindGermanVelourBackpack() const;

    /**
     * Метод пошуку об'єкту
     *
     * Метод знаходить серед колекції замшевий рюкзак без підкладки
     * @return контейнер зі знайденими об'єктами
     */
    vector<LeatherBackpack*> FindSuedeNoLiningBackpack() const;

    /**
     * Метод пошуку об'єкту
     *
     * Метод знаходить серед колекції рюкзак синього кольору з найбільшим об'ємом
     * @return контейнер зі знайденими об'єктами
     */
    vector<Backpack*>  FindBlueMaxVolumeBackpack() const;
};


#endif //RGZ_CONTROLLER_H

