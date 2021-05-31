//
// Created by Vlad on 26.05.2021.
//

/**
 * @file Controller.cpp
 * @brief Файл з реалізацією методів класу-контролеру
 *
 * @author Makarenko V.
 * @date 26-may-2021
 * @version 1.0
 */

#include "Controller.h"

Controller::Controller() {}

Controller::~Controller() {}

List* Controller::getList() {
    return &list;
}

bool Controller::ReadFromFile(const string &path) {
    bool checker = false;
    cout << endl;
    ifstream fin;
    fin.open(path);
    if (!fin.is_open()) {
        cout << "ERROR: The file did not open!" << endl;
        cout << "Try again.." << endl << endl;
        checker = true;
    }
    else {
        char type;
        bool field1;
        string field2;
        int field3;
        int field4;
        string field5;
        string field6;
        bool field7;
        int field8;
        Purpose purpose;
        Type type1;
        Fabric fabric;
        stringstream buffer;

        while (!fin.eof()) {
            fin >> type;
            fin >> field1;
            fin >> field2;
            fin >> field3;
            fin >> field4;
            fin >> field5;
            fin >> field6;
            fin >> field7;
            fin >> field8;

            regex reg("^[0-1] [A-Z][a-z]* [0-9]{1,3} [0-2] [a-zA-Z.&]* [A-Z][a-zA-Z]* [0-1] [0-2]$");
            buffer << field1 << " " << field2 << " " << field3 << " " << field4 << " " << field5 << " " << field6 << " " << field7 << " " << field8;
            switch (field4) {
                case 0:
                    purpose = URBAN;
                    break;
                case 1:
                    purpose = TACTICAL;
                    break;
                case 2:
                    purpose = TOURIST;
                    break;
                default:
                    break;
            }
            if (regex_match(buffer.str(), reg)) {
                if (type == 'L') {
                    switch (field8) {
                        case 0:
                            type1 = ANILINE;
                            break;
                        case 1:
                            type1 = VELOUR;
                            break;
                        case 2:
                            type1 = SUEDE;
                            break;
                        default:
                            break;
                    }
                    LeatherBackpack leatherBackpack(field1, field2, field3, Firm(field5, field6), purpose, field7,
                                                    type1);
                    list.addBackpack(&leatherBackpack);
                }

                if (type == 'F') {
                    switch (field8) {
                        case 0:
                            fabric = SYNTHETICS;
                            break;
                        case 1:
                            fabric = COTTON;
                            break;
                        case 2:
                            fabric = TARP;
                            break;
                        default:
                            break;
                    }
                    FabricBackpack fabricBackpack(field1, field2, field3, Firm(field5, field6), purpose, field7,
                                                  fabric);
                    list.addBackpack(&fabricBackpack);
                }
            }
            buffer.str("");
        }
    }
    fin.close();
    return checker;
}

string ToString(Backpack* a) {
    stringstream buffer;
    if (a->GetType() == 'L') {
        auto* Le = (LeatherBackpack*)a->clone();
        buffer << Le->getlaptop_department() << " " << Le->getcolor() << " " << Le->getvolume() << " " << Le->getpurpose()
               << " " << Le->getfirm().getName() << " " << Le->getfirm().getCountry() << " " << Le->getlining() << " " << Le->getLeather() << endl;
        delete Le;
    }
    else {
        auto* F = (FabricBackpack*)a->clone();
        buffer << F->getlaptop_department() << " " << F->getcolor() << " " << F->getvolume() << " " << F->getpurpose()
               << " " << F->getfirm().getName() << " " << F->getfirm().getCountry() << " " << F->getwaterproof() << " " << F->getFabric() << endl;
    }
    return buffer.str();
}

void Controller::WriteToFile() {
    string path;
    cout << "|| > Enter file name: ";
    cin >> path;
    ofstream fout;
    fout.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    fout.open(path, std::ios_base::out);
    if (!fout.is_open()) {
        cout << "ERROR: The file did not open!" << endl;
    }
    else {
        for (int i = 0; i < list.getBackpack().size(); ++i) {
            fout << ToString(list.getBackpackByIndex(i));
        }

    }
    fout.close();
}

bool predGermanUrbanVelour(Backpack* a)
{
    if (a->GetType() == 'L') {
        auto* Le = (LeatherBackpack*)a->clone();
        if (Le->getfirm().getCountry() == "Germany"
            && Le->getLeather() == VELOUR
            && Le->getpurpose() == URBAN) {
            delete Le;
            return true;
        }
        else {
            delete Le;
            return false;
        }
    }
    else {
        return false;
    }
}


vector<LeatherBackpack*> Controller::FindGermanVelourBackpack() {
    vector<LeatherBackpack*> res;
    vector<Backpack*> tmp = this->list.getBackpack();
    bool flag = true;
    auto iter = tmp.begin();
    while (true) {
        iter = std::find_if(iter, tmp.end(), predGermanUrbanVelour);
        if (iter == tmp.end()) {
            break;
        }
        flag = false;
        res.push_back((LeatherBackpack*)*iter);
        ((LeatherBackpack*)*iter)->Print();
        cout << endl;
        iter++;
    }
    if (flag) {
        cout << "ERROR: Nothing found" << endl;
    }
    while (!tmp.empty()) {
        tmp.pop_back();
    }
    tmp.clear();
    tmp.shrink_to_fit();
    return res;
}
//
//
//
bool predSuedeNoLining(Backpack* a)
{
    if (a->GetType() == 'L') {
        auto* Le = (LeatherBackpack*)a->clone();
        if (Le->getLeather() == SUEDE && Le->getlining() == false) {
            delete Le;
            return true;
        }
        else {
            delete Le;
            return false;
        }
    }
    else {
        return false;
    }
}

vector<LeatherBackpack*>  Controller::FindSuedeNoLiningBackpack() {
    vector<LeatherBackpack*> res;
    vector<Backpack*> temp = this->list.getBackpack();
    bool flag = true;
    auto iter = temp.begin();
    while (*iter) {
        iter = std::find_if(iter, temp.end(), predSuedeNoLining);
        if (iter == temp.end()) {
            break;
        }
        flag = false;
        ((LeatherBackpack*)*iter)->Print();
        cout << endl;
        res.push_back((LeatherBackpack*)*iter);
        iter++;
    }
    if (flag) {
        cout << "ERROR: Nothing found" << endl;
    }
    while (!temp.empty()) {
        temp.pop_back();
    }
    temp.clear();
    temp.shrink_to_fit();
    return res;
}

bool functorSortByLD(Backpack* A, Backpack* B) {
    bool result = false;

    if (A->GetType() == 'L' && B->GetType() == 'L') {
        auto* temp1 = (LeatherBackpack*)A->clone();
        auto* temp2 = (LeatherBackpack*)B->clone();
        if (temp1->getlaptop_department() < temp2->getlaptop_department()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto* temp3 = (FabricBackpack*)A->clone();
        auto* temp4 = (FabricBackpack*)B->clone();
        if (temp3->getlaptop_department() < temp4->getlaptop_department()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'L') {
        auto* temp3 = (FabricBackpack*)A->clone();
        auto* temp1 = (LeatherBackpack*)B->clone();
        if (temp3->getlaptop_department() < temp1->getlaptop_department()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'L' && B->GetType() == 'F') {
        auto* temp1 = (LeatherBackpack*)A->clone();
        auto* temp3 = (FabricBackpack*)B->clone();
        if (temp1->getlaptop_department() < temp3->getlaptop_department()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

bool functorSortByColor(Backpack* A, Backpack* B) {
    bool result = false;

    if (A->GetType() == 'L' && B->GetType() == 'L') {
        auto* temp1 = (LeatherBackpack*)A->clone();
        auto* temp2 = (LeatherBackpack*)B->clone();
        if (temp1->getcolor() < temp2->getcolor()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto* temp3 = (FabricBackpack*)A->clone();
        auto* temp4 = (FabricBackpack*)B->clone();
        if (temp3->getcolor() < temp4->getcolor()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'L') {
        auto* temp3 = (FabricBackpack*)A->clone();
        auto* temp1 = (LeatherBackpack*)B->clone();
        if (temp3->getcolor() < temp1->getcolor()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'L' && B->GetType() == 'F') {
        auto* temp1 = (LeatherBackpack*)A->clone();
        auto* temp3 = (FabricBackpack*)B->clone();
        if (temp1->getcolor() < temp3->getcolor()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

bool functorSortByVolume(Backpack* A, Backpack* B) {
    bool result = false;

    if (A->GetType() == 'L' && B->GetType() == 'L') {
        auto* temp1 = (LeatherBackpack*)A->clone();
        auto* temp2 = (LeatherBackpack*)B->clone();
        if (temp1->getvolume() < temp2->getvolume()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto* temp3 = (FabricBackpack*)A->clone();
        auto* temp4 = (FabricBackpack*)B->clone();
        if (temp3->getvolume() < temp4->getvolume()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'L') {
        auto* temp3 = (FabricBackpack*)A->clone();
        auto* temp1 = (LeatherBackpack*)B->clone();
        if (temp3->getvolume() < temp1->getvolume()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'L' && B->GetType() == 'F') {
        auto* temp1 = (LeatherBackpack*)A->clone();
        auto* temp3 = (FabricBackpack*)B->clone();
        if (temp1->getvolume() < temp3->getvolume()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

bool functorSortByPurpose(Backpack* A, Backpack* B) {
    bool result = false;

    if (A->GetType() == 'L' && B->GetType() == 'L') {
        auto* temp1 = (LeatherBackpack*)A->clone();
        auto* temp2 = (LeatherBackpack*)B->clone();
        if (temp1->getpurpose() < temp2->getpurpose()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto* temp3 = (FabricBackpack*)A->clone();
        auto* temp4 = (FabricBackpack*)B->clone();
        if (temp3->getpurpose() < temp4->getpurpose()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'L') {
        auto* temp3 = (FabricBackpack*)A->clone();
        auto* temp1 = (LeatherBackpack*)B->clone();
        if (temp3->getpurpose() < temp1->getpurpose()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'L' && B->GetType() == 'F') {
        auto* temp1 = (LeatherBackpack*)A->clone();
        auto* temp3 = (FabricBackpack*)B->clone();
        if (temp1->getpurpose() < temp3->getpurpose()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

bool functorSortByName(Backpack* A, Backpack* B) {
    bool result = false;

    if (A->GetType() == 'L' && B->GetType() == 'L') {
        auto* temp1 = (LeatherBackpack*)A->clone();
        auto* temp2 = (LeatherBackpack*)B->clone();
        if (temp1->getfirm().getName() < temp2->getfirm().getName()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto* temp3 = (FabricBackpack*)A->clone();
        auto* temp4 = (FabricBackpack*)B->clone();
        if (temp3->getfirm().getName() < temp4->getfirm().getName()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'L') {
        auto* temp3 = (FabricBackpack*)A->clone();
        auto* temp1 = (LeatherBackpack*)B->clone();
        if (temp3->getfirm().getName() < temp1->getfirm().getName()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'L' && B->GetType() == 'F') {
        auto* temp1 = (LeatherBackpack*)A->clone();
        auto* temp3 = (FabricBackpack*)B->clone();
        if (temp1->getfirm().getName() < temp3->getfirm().getName()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

bool functorSortByCountry(Backpack* A, Backpack* B) {
    bool result = false;

    if (A->GetType() == 'L' && B->GetType() == 'L') {
        auto* temp1 = (LeatherBackpack*)A->clone();
        auto* temp2 = (LeatherBackpack*)B->clone();
        if (temp1->getfirm().getCountry() < temp2->getfirm().getCountry()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'F' && B->GetType() == 'F') {
        auto* temp3 = (FabricBackpack*)A->clone();
        auto* temp4 = (FabricBackpack*)B->clone();
        if (temp3->getfirm().getCountry() < temp4->getfirm().getCountry()) {
            result = true;
        }
        delete temp4;
        delete temp3;
    }
    if (A->GetType() == 'F' && B->GetType() == 'L') {
        auto* temp3 = (FabricBackpack*)A->clone();
        auto* temp1 = (LeatherBackpack*)B->clone();
        if (temp3->getfirm().getCountry() < temp1->getfirm().getCountry()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'L' && B->GetType() == 'F') {
        auto* temp1 = (LeatherBackpack*)A->clone();
        auto* temp3 = (FabricBackpack*)B->clone();
        if (temp1->getfirm().getCountry() < temp3->getfirm().getCountry()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }
    return result;
}

void  Controller::SortByCriterion(int criterion, bool direction) {
    auto temp = list.getBackpack();
    switch (criterion) {
        case 1:
            std::sort(temp.begin(), temp.end(), functorSortByLD);
            break;
        case 2:
            std::sort(temp.begin(), temp.end(), functorSortByColor);
            break;
        case 3:
            std::sort(temp.begin(), temp.end(), functorSortByVolume);
            break;
        case 4:
            std::sort(temp.begin(), temp.end(), functorSortByPurpose);
            break;
        case 5:
            std::sort(temp.begin(), temp.end(), functorSortByName);
            break;
        case 6:
            std::sort(temp.begin(), temp.end(), functorSortByCountry);
            break;
        default:
            throw std::out_of_range("Out of range exception");
            break;
    }
    if (!direction) {
        std::reverse(temp.begin(), temp.end());
    }
    this->list.setBackpacks(temp);
}


bool predBlueMax(Backpack* a)
{
    auto* Le = (LeatherBackpack*)a->clone();
    if (Le->getcolor() == "Blue") {
        delete Le;
        return true;
    }
    else {
        delete Le;
        return false;
    }
}

vector<Backpack*> Controller::FindBlueMaxVolumeBackpack() {
    vector<Backpack*> res;
    auto temp = this->list.getBackpack();
    std::sort(temp.begin(), temp.end(), functorSortByVolume);
    std::reverse(temp.begin(), temp.end());

    auto iter = temp.begin();
    iter = std::find_if(iter, temp.end(), predBlueMax);
    if (iter == temp.end()) {
        cout << "ERROR: Nothing found" << endl;
    }
    if (((Backpack*)*iter)->GetType() == 'L') {
        PrintForm1();
        cout << endl;
        ((LeatherBackpack*)*iter)->Print();
        cout << endl;
        res.push_back((LeatherBackpack*)(*iter));
    }
    else {
        PrintForm2();
        cout << endl;
        ((FabricBackpack*)*iter)->Print();
        cout << endl;
        res.push_back((FabricBackpack*)(*iter));
    }

    while (!temp.empty()) {
        temp.pop_back();
    }
    temp.clear();
    temp.shrink_to_fit();
    return res;
}

