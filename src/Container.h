#pragma once
//
// Created by Vlad on 26.05.2021.
//

/**
 * @file Container.h
 * @brief Файл з класом-контейнером
 *
 * @author Makarenko V.
 * @date 26-may-2021
 * @version 1.0
 */

#ifndef LAB23_CONTAINER_H
#define LAB23_CONTAINER_H

#include "Backpack.h"

/**
 * Клас-контейнер
 */
class List {
    vector<Backpack*> backpacks;
    int index = 0;
public:
    /**
     * Конструктор за замовчуванням
     */
    List();
    /**
     * Конструктор копіювання
     */
    List(List& copy);
    /**
     * Деструктор
     */
    virtual ~List();
    /**
     * "Сетер"
     *
     * Встановлює новий вектор
     */
    void setBackpacks(const vector<Backpack*> NewBackpacks);

    /**
     * Метод додання елементу
     *
     * Метод додає новий елемент в кінець вектора
     * @param backpack - об'єкт, що буде додано
     */
    void addBackpack(Backpack* backpack);

    /**
     * Метод додання елементу по індексу
     *
     * Метод додає новий елемент в індекс вектора
     * @param backpack - об'єкт, що буде додано
     * @param index - позиція в яку буде додано об'єкт
     */
    void addBackpackByIndex(Backpack* backpack, int index);

    /**
     * "Гетер"
     *
     * Повертає вектор об'єктів
     */
    vector<Backpack*> getBackpack();

    /**
     * "Гетер"
     *
     * Повертає об'єкт із вектора за індексом
     * @param index - позиція, елемент якої будет отримано
     */
    Backpack* getBackpackByIndex(int index);

    /**
     * Метод виводу на екран
     *
     * Метод виводить колекцію на екран
     */
    void ShowAll();

    /**
    * Метод видалення елементу по індексу
    *
    * Метод видаляє елемент в індексі вектора
    * @param index - позиція з якої будевидалено об'єкт
    */
    void DeleteElement(int index);

    /**
    * Метод очищення вектора
    *
    * Метод видаляє всі елементи в векторі
    */
    void DeleteAll();

    /**
    * Метод додання нового об'єкту
    *
    * Метод отримує від користувача новий об'єкт та викликає
    * метод додання нового єлементу по індексу
    */
    void NewBackpack();
};


#endif //LAB23_CONTAINER_H
