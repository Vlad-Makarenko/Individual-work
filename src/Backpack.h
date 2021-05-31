#pragma once
//
// Created by Vlad on 26.05.2021.
//

/**
 * @file Backpack.h
 * @brief Файл з базовим класом
 *
 * @author Makarenko V.
 * @date 26-may-2021
 * @version 1.0
 */

#ifndef LAB23_BACKPACK_H
#define LAB23_BACKPACK_H

#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::regex_match;
using std::regex;
using std::stoi;
using std::vector;
using std::set;

/**
 * Перелік призначень
 */

enum Purpose {
    URBAN = 0,
    TACTICAL,
    TOURIST
};


/**
 * Клас «Фірма»
 */
class Firm {
    string Name;
    string Country;
public:
/**
 * Конструктор за замовчуванням
 */
    Firm();
/**
 * Конструктор з параметрами
 */
    Firm(string Name, string Country);
/**
 * Конструктор копіювання
 */
    Firm(const Firm& copy);
/**
 * Деструктор
 */
    virtual ~Firm();
/**
 * "Гетер"
 *
 * Повертає назву фірми-виробника
 */
    string getName() const;
/**
 * "Гетер"
 *
 * Повертає назву країни-виробника
 */
    string getCountry() const;
/**
 * "Сетер"
 *
 * Встановлює назву фірми-виробника
 */
    void setName(const string& name);
/**
 * "Сетер"
 *
 * Встановлює назву країни-виробника
 */
    void setCountry(const string& country);
/**
 * Метод виводу
 *
 * Виводить об'єкт на екран
 */
    void Print();
};

/**
 * Базовий клас-інтерфейс "Рюкзак"
 */
class Backpack {
public:
/**
 * Віртуальний метод виводу
 */
    virtual void Print() = 0;
/**
 * Віртуальний метод клонування
 */
    virtual Backpack* clone() = 0;
/**
 * Віртуальний деструктор
 */
    virtual ~Backpack() = default;
/**
 * Віртуальний метод виявлення типу об'єкта
 */
    virtual char GetType() = 0;
};


//|--------------------Наследник 1--------------------|\\


/**
 * Перелік шкіри
 */
enum Type {
    ANILINE = 0, VELOUR, SUEDE
};
/**
 * Клас-спадкоємець "шкіряний рюкзак" від базового клсау-інтерфейсу
 */
class LeatherBackpack : public Backpack {
    bool laptop_department; // 1 - yes; 0 - no.
    string color;
    int volume;
    Firm firm;
    Purpose enumPurpose;
    bool lining;
    Type Leather;
public:
/**
 * Конструктор за замовчуванням
 */
    LeatherBackpack();
/**
 * Конструктор з параметрами
 */
    LeatherBackpack(bool laptop_department, string color, int volume, const Firm& firm, enum Purpose purpose, bool  lining, Type leather);

    /**
     * "Гетер"
     *
     * Повертає наявність відділу для ноутбуку
     */
    int getlaptop_department() const;
    /**
     * "Гетер"
     *
     * Повертає колір
     */
    string getcolor() const;
    /**
     * "Гетер"
     *
     * Повертає об'єм
     */
    int getvolume() const;
    /**
     * "Гетер"
     *
     * Повертає фірму
     */
    Firm getfirm() const;
    /**
     * "Гетер"
     *
     * Повертає ціль
     */
    Purpose getpurpose() const;
    /**
    * "Сетер"
    *
    * Встановлює наявність відділу для ноутбука
    */
    void setlaptop_department(const int laptop_department);
    /**
     * "Сетер"
     *
     * Встановлює колір
     */
    void setcolor(const string color);
    /**
     * "Сетер"
     *
     * Встановлює об'єм
     */
    void setvolume(const int volume);
    /**
     * "Сетер"
     *
     * Встановлює фірму
     */
    void setfirm(Firm* firm1);
    /**
     * "Сетер"
     *
     * Встановлює ціль
     */
    void setpurpose(const Purpose purpose);
    /**
     * Деструктор
     */
    virtual ~LeatherBackpack();
    /**
     * "Гетер"
     *
     * Повертає наявність підкладки
     */
    bool getlining() const;
    /**
     * "Гетер"
     *
     * Повертає тип шкіри
     */
    Type getLeather() const;
    /**
     * "Сетер"
     *
     * Встановлює наявність підкладки
     */
    void setlining(const bool lining);
    /**
     * "Сетер"
     *
     * Встановлює тип шкіри
     */
    void setLeather(const Type Leather);
    /**
     * Метод виводу
     *
     * Виводить об'єкт на екран
     */
    void Print() override;
    /**
    * Метод виявлення типу об'єкта
    *
    * Повертає вказівник на даний об'єкт
    */
    Backpack* clone() override;
    /**
     * Метод виявлення типу об'єкта
     *
     * Повертає тип об'єкта
     */
    char GetType() override;

};
/**
 * Перегрузка оператора порівняння == для об'єкту LeatherBackpack
 */
bool operator==(const LeatherBackpack& A, const LeatherBackpack& B);

/**
 * Перегрузка оператора виводу << для об'єкту LeatherBackpack
 */
ostream& operator<<(ostream& out, const LeatherBackpack& backpack);

/**
 * Перегрузка оператора вводу >> для об'єкту LeatherBackpack
 */
istream& operator>>(istream& in, LeatherBackpack& backpack);

//|--------------------Наследник 2--------------------|\\

/**
 *Перелік тканини
 */
enum Fabric {
    SYNTHETICS = 0, COTTON, TARP
};
/**
 * Клас-спадкоємець "тканевий рюкзак" від базового клсау-інтерфейсу
 */
class FabricBackpack : public Backpack {
    bool laptop_department; // 1 - yes; 0 - no.
    string color;
    int volume;
    Firm firm;
    Purpose enumPurpose;
    bool waterproof;
    Fabric fabric;
public:
    /**
     * Конструктор за замовчуванням
     */
    FabricBackpack();
    /**
     * Конструктор з параметрами
     */
    FabricBackpack(int laptop_department, string color, int volume, const Firm& firm, enum Purpose purpose, bool waterproof, Fabric fabric);
    /**
     * Деструктор
     */
    virtual ~FabricBackpack();
    /**
     * "Гетер"
     *
     * Повертає наявність відділу для ноутбуку
     */
    int getlaptop_department() const;
    /**
     * "Гетер"
     *
     * Повертає колір
     */
    string getcolor() const;
    /**
     * "Гетер"
     *
     * Повертає об'єм
     */
    int getvolume() const;
    /**
     * "Гетер"
     *
     * Повертає фірму
     */
    Firm getfirm() const;
    /**
     * "Гетер"
     *
     * Повертає ціль
     */
    Purpose getpurpose() const;
    /**
     * "Сетер"
     *
     * Встановлює наявність відділу для ноутбука
     */
    void setlaptop_department(const int laptop_department);
    /**
     * "Сетер"
     *
     * Встановлює колір
     */
    void setcolor(const string color);
    /**
     * "Сетер"
     *
     * Встановлює об'єм
     */
    void setvolume(const int volume);
    /**
     * "Сетер"
     *
     * Встановлює фірму
     */
    void setfirm(Firm* firm1);
    /**
     * "Сетер"
     *
     * Встановлює ціль
     */
    void setpurpose(const Purpose purpose);
    /**
     * "Гетер"
     *
     * Повертає чи є водонепронекним
     */
    bool getwaterproof() const;
    /**
     * "Гетер"
     *
     * Повертає тип тканини
     */
    Fabric getFabric() const;
    /**
     * "Сетер"
     *
     * Встановлює водонепроникність
     */
    void setwaterproof(const bool waterproof);
    /**
     * "Сетер"
     *
     * Встановлює тип тканини
     */
    void setfabric(const Fabric fabric);
    /**
    * Метод виявлення типу об'єкта
    *
    * Повертає вказівник на даний об'єкт
    */
    void Print() override;
    /**
     * Метод виявлення типу об'єкта
     *
     * Повертає вказівник на даний об'єкт
     */
    Backpack* clone() override;
    /**
     * Метод виявлення типу об'єкта
     *
     * Повертає тип об'єкта
     */
    char GetType() override;

};
/**
 * Перегрузка оператора порівняння == для об'єкту FabricBackpack
 */
bool operator==(const FabricBackpack& A, const FabricBackpack& B);

/**
 * Перегрузка оператора виводу << для об'єкту FabricBackpack
 */
ostream& operator<<(ostream& out, const FabricBackpack& backpack);

/**
 * Перегрузка оператора вводу >> для об'єкту FabricBackpack
 */
istream& operator>>(istream& in, FabricBackpack& backpack);

void PrintForm();

void PrintForm1();

void PrintForm2();

void PrintForm3();

#endif //LAB23_BACKPACK_H
