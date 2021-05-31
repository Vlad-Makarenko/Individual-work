//
// Created by Vlad on 26.05.2021.
//

/**
 * @file Container.cpp
 * @brief Файл з реалызацією методів класу-контейнеру
 *
 * @author Makarenko V.
 * @date 26-may-2021
 * @version 1.0
 */

#include "Container.h"


List::List() : index(0) {
    while (!backpacks.empty()) {
        backpacks.pop_back();
    }
    backpacks.clear();
    backpacks.shrink_to_fit();
}

List::List(List& copy) :index(copy.index), backpacks(copy.backpacks) {}

List::~List() {
    while (!backpacks.empty()) {
        backpacks.pop_back();
    }
    backpacks.clear();
    backpacks.shrink_to_fit();
}


void List::DeleteAll() {
    while (!backpacks.empty()) {
        backpacks.pop_back();
    }
    backpacks.clear();
    backpacks.shrink_to_fit();
    index = 0;
}


void List::addBackpack(Backpack* backpack) {
    index += 1;
    if (index >= 255) {
        return;
    }
    this->backpacks.push_back(backpack->clone());
}


vector<Backpack*> List::getBackpack() {
    return this->backpacks;
}

void List::setBackpacks(const vector<Backpack*> NewBackpacks) {
    while (!backpacks.empty()) {
        backpacks.pop_back();
    }
    backpacks.clear();
    backpacks.shrink_to_fit();
    index = NewBackpacks.size();
    this->backpacks = NewBackpacks;
}

Backpack* List::getBackpackByIndex(int index) {
    if (index < 0 || index > backpacks.size()) {
        throw std::out_of_range("Out of range exception");
    }
    return this->backpacks[index]->clone();
}

void List::ShowAll() {
    for (int i = 0; i < backpacks.size(); ++i) {
        backpacks[i]->Print();
        cout << endl;
    }
}

void List::DeleteElement(int index) {
    if (index < 0 || index > backpacks.size()) {
        throw std::out_of_range("Out of range exception");
    }
    vector<Backpack*>::iterator pos = backpacks.begin() + index;
    backpacks.erase(pos);
    this->index--;
}

void List::addBackpackByIndex(Backpack* backpack, int index) {
    if (index < 0 || index > backpacks.size()) {
        throw std::out_of_range("Out of range exception");
    }
    auto iter = backpacks.begin();
    this->backpacks.insert(iter + index, backpack->clone());
}


void List::NewBackpack(){
    int choice;
    int pos;
    cout << "|| > Choose what type of backpack you want to add: " << endl;
    cout << "|| 1. Leather backpack" << endl;
    cout << "|| 2. Fabric backpack" << endl;
    cout << "|| > Your choice: ";
    cin >> choice;
    if (choice == 1) {
        LeatherBackpack L;
        cin >> L;
        if(L.getcolor() == "") throw std::invalid_argument("Bad Argument");
        cout << "|| > Choose where to insert the element: ";
        cin >> pos;
        addBackpackByIndex(&L, pos);
    } else if(choice == 2) {
        FabricBackpack F;
        cin >> F;
        if(F.getcolor() == "") throw std::invalid_argument("Bad Argument");
        cout << "|| > Choose where to insert the element: ";
        cin >> pos;
        addBackpackByIndex(&F, pos);
    } else {
        throw std::out_of_range("Out of range exception");
    }
}


