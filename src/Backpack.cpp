//
// Created by Vlad on 26.05.2021.
//

/**
 * @file Backpack.h
 * @brief Файл з реалізацією методів базового класу
 *
 * @author Makarenko V.
 * @date 26-may-2021
 * @version 1.0
 */
#include "Backpack.h"

//|------------------------FIRM------------------------|\\

Firm::Firm() : Name(), Country() {
    //cout << "\ndefault constructor <Firm> " << endl;
}

Firm::Firm(string Name, string Country) : Name(Name), Country(Country) {
    //cout << "\nConstructor with arguments <Firm> " << endl;
}

Firm::Firm(const Firm& copy) : Name(copy.Name), Country(copy.Country) {
    //cout << "\nCopy constructor <Firm> " << endl;
}

Firm::~Firm() = default; // {
//    cout << "\nDestructor <Firm>" << endl;
//}

string Firm::getName() const {
    return this->Name;
}

string  Firm::getCountry() const {
    return this->Country;
}

void Firm::setName(const string & name) {
    this->Name = name;
}

void Firm::setCountry(const string & country) {
    this->Country = country;
}

void Firm::Print() {
    cout << Name;
    cout.width(18);
    cout << Country;
}

//|--------------------Наследник 1--------------------|\\

LeatherBackpack::LeatherBackpack() {}

LeatherBackpack::LeatherBackpack(bool laptop_department, string color, int volume, const Firm & firm, enum Purpose purpose, bool  lining, Type leather) :
        laptop_department(laptop_department), color(color), volume(volume), firm(firm), enumPurpose(purpose), lining(lining), Leather(leather) {}


LeatherBackpack:: ~LeatherBackpack() {}

int LeatherBackpack::getlaptop_department() const {
    return this->laptop_department;
}

string LeatherBackpack::getcolor() const {
    return this->color;
}

int LeatherBackpack::getvolume() const {
    return this->volume;
}

Firm LeatherBackpack::getfirm() const {
    return this->firm;
}

Purpose LeatherBackpack::getpurpose() const {
    return this->enumPurpose;
}

void LeatherBackpack::setlaptop_department(const int laptop_department) {
    this->laptop_department = laptop_department;
}

void LeatherBackpack::setcolor(const string color) {
    this->color = color;
}

void LeatherBackpack::setvolume(const int volume) {
    this->volume = volume;
}

void LeatherBackpack::setfirm(Firm * firm1) {
    firm.setName(firm1->getName());
    firm.setCountry(firm1->getCountry());
}

void LeatherBackpack::setpurpose(const Purpose purpose) {
    this->enumPurpose = purpose;
}

bool LeatherBackpack::getlining() const {
    return this->lining;
}

Type LeatherBackpack::getLeather() const {
    return this->Leather;
}

void LeatherBackpack::setlining(const bool lining) {
    this->lining = lining;
}

void LeatherBackpack::setLeather(const Type Leather) {
    this->Leather = Leather;
}

void LeatherBackpack::Print() {

    cout.width(17);
    cout << laptop_department;
    cout.width(15);
    cout << color;
    cout.width(17);
    cout << volume;
    cout.width(18);
    cout << enumPurpose;
    cout.width(15);
    firm.Print();
    cout.width(16);
    cout << lining;
    cout.width(16);
    cout << Leather;
}

char LeatherBackpack::GetType() {
    return 'L';
}

Backpack* LeatherBackpack::clone() {
    return (Backpack*) new LeatherBackpack(*this);
}


ostream& operator<<(ostream& out, const LeatherBackpack& backpack) {
    out.width(17);
    out << backpack.getlaptop_department();
    out.width(15);
    out << backpack.getcolor();
    out.width(17);
    out << backpack.getvolume();
    out.width(18);
    out << backpack.getpurpose();
    out.width(15);
    out << backpack.getfirm().getName();
    out.width(18);
    out << backpack.getfirm().getCountry();
    out.width(16);
    out << backpack.getlining();
    out.width(16);
    out << backpack.getLeather();
    return out;
}

istream& operator>>(istream& in, LeatherBackpack& backpack) {
    bool LD;
    int volume;
    string color;
    int aim;
    string name;
    string country;
    bool lining;
    int Type;
    cout << "|| > Enter the data in this order: PlaceFofLaptop Color Volume Aim Name Country Lining Type\n|| ";
    in >> LD;
    in >> color;
    in >> volume;
    in >> aim;
    in >> name;
    in >> country;
    in >> lining;
    in >> Type;

    stringstream buffer;
    buffer << LD << " " << color << " " << volume << " " << aim << " " << name << " " << country << " " << lining << " " << Type;
    regex reg("^[0-1] [A-Z][a-z]* [0-9]{1,3} [0-2] [a-zA-Z.&]* [A-Z][a-zA-Z]* [0-1] [0-2]$");

    if (regex_match(buffer.str(), reg)) {
        backpack.setlaptop_department(LD);
        backpack.setcolor(color);
        backpack.setvolume(volume);
        switch (aim) {
            case 0:
                backpack.setpurpose(URBAN);
                break;
            case 1:
                backpack.setpurpose(TACTICAL);
                break;
            case 2:
                backpack.setpurpose(TOURIST);
                break;
            default:
                break;
        }
        Firm firm(name, country);
        backpack.setfirm(&firm);
        backpack.setlining(lining);
        switch (Type) {
            case 0:
                backpack.setLeather(ANILINE);
                break;
            case 1:
                backpack.setLeather(VELOUR);
                break;
            case 2:
                backpack.setLeather(SUEDE);
                break;
            default:
                break;
        }
        return in;
    }
    else {
        in.clear();
        cout << "ERROR: Invalid data entered, item not added.\n";
        return in;
    }
}

//|------------------------Наследний 2---------------------|\\

FabricBackpack::FabricBackpack() {}

FabricBackpack::FabricBackpack(int laptop_department, string color, int volume, const Firm & firm, enum Purpose purpose, bool  waterproof, Fabric fabric) :
        laptop_department(laptop_department), color(color), volume(volume), firm(firm), enumPurpose(purpose), waterproof(waterproof), fabric(fabric) {}


FabricBackpack:: ~FabricBackpack() {}

int FabricBackpack::getlaptop_department() const {
    return this->laptop_department;
}

string FabricBackpack::getcolor() const {
    return this->color;
}

int FabricBackpack::getvolume() const {
    return this->volume;
}

Firm FabricBackpack::getfirm() const {
    return this->firm;
}

Purpose FabricBackpack::getpurpose() const {
    return this->enumPurpose;
}

void FabricBackpack::setlaptop_department(const int laptop_department) {
    this->laptop_department = laptop_department;
}

void FabricBackpack::setcolor(const string color) {
    this->color = color;
}

void FabricBackpack::setvolume(const int volume) {
    this->volume = volume;
}

void FabricBackpack::setfirm(Firm * firm1) {
    firm.setName(firm1->getName());
    firm.setCountry(firm1->getCountry());
}

void FabricBackpack::setpurpose(const Purpose purpose) {
    this->enumPurpose = purpose;
}

bool FabricBackpack::getwaterproof() const {
    return this->waterproof;
}

Fabric FabricBackpack::getFabric() const {
    return this->fabric;
}

void FabricBackpack::setwaterproof(const bool waterproof) {
    this->waterproof = waterproof;
}

void FabricBackpack::setfabric(const Fabric fabric) {
    this->fabric = fabric;
}

void FabricBackpack::Print() {
    cout.width(17);
    cout << laptop_department;
    cout.width(15);
    cout << color;
    cout.width(17);
    cout << volume;
    cout.width(18);
    cout << enumPurpose;
    cout.width(15);
    firm.Print();
    cout.width(16);
    cout << waterproof;
    cout.width(16);
    cout << fabric;
}

Backpack* FabricBackpack::clone() {
    return (Backpack*)new FabricBackpack(*this);
}

char FabricBackpack::GetType() {
    return 'F';
}

void PrintForm() {
    cout.width(10);
    cout << "Place for laptop:";
    cout.width(15);
    cout << "Color:";
    cout.width(18);
    cout << " Volume: ";
    cout.width(18);
    cout << "Purpose: ";
    cout.width(15);
    cout << "Firm: ";
    cout.width(17);
    cout << " Country:";
}

ostream& operator<<(ostream& out, const FabricBackpack& backpack) {
    out.width(17);
    out << backpack.getlaptop_department();
    out.width(15);
    out << backpack.getcolor();
    out.width(17);
    out << backpack.getvolume();
    out.width(18);
    out << backpack.getpurpose();
    out.width(15);
    out << backpack.getfirm().getName();
    out.width(18);
    out << backpack.getfirm().getCountry();
    out.width(16);
    out << backpack.getwaterproof();
    out.width(16);
    out << backpack.getFabric();
    return out;
}

istream& operator>>(istream& in, FabricBackpack& backpack) {
    bool LD;
    int volume;
    string color;
    int aim;
    string name;
    string country;
    bool waterproof;
    int Type;
    cout << "|| > Enter the data in this order: PlaceFofLaptop Color Volume Aim Name Country Lining Type\n|| ";
    in >> LD;
    in >> color;
    in >> volume;
    in >> aim;
    in >> name;
    in >> country;
    in >> waterproof;
    in >> Type;

    stringstream buffer;
    buffer << LD << " " << color << " " << volume << " " << aim << " " << name << " " << country << " " << waterproof << " " << Type;
    regex reg("^[0-1] [A-Z][a-z]* [0-9]{1,3} [0-2] [a-zA-Z.&]* [A-Z][a-zA-Z]* [0-1] [0-2]$");

    if (regex_match(buffer.str(), reg)) {
        backpack.setlaptop_department(LD);
        backpack.setcolor(color);
        backpack.setvolume(volume);
        switch (aim) {
            case 0:
                backpack.setpurpose(URBAN);
                break;
            case 1:
                backpack.setpurpose(TACTICAL);
                break;
            case 2:
                backpack.setpurpose(TOURIST);
                break;
            default:
                break;
        }
        Firm firm(name, country);
        backpack.setfirm(&firm);
        backpack.setwaterproof(waterproof);
        switch (Type) {
            case 0:
                backpack.setfabric(SYNTHETICS);
                break;
            case 1:
                backpack.setfabric(COTTON);
                break;
            case 2:
                backpack.setfabric(TARP);
                break;
            default:
                break;
        }
        return in;
    }
    else {
        in.clear();
        cout << "ERROR: Invalid data entered, item not added.\n";
        return in;
    }
}

void PrintForm1() {
    PrintForm();
    cout.width(16);
    cout << "Lining:";
    cout.width(16);
    cout << "Leather:";
}

void PrintForm2() {
    PrintForm();
    cout.width(16);
    cout << "Waterproof:";
    cout.width(16);
    cout << "Fabric:";
}

void PrintForm3() {
    PrintForm();
    cout.width(16);
    cout << "WP/Lining:";
    cout.width(16);
    cout << "Fabric/Leather:";
}

bool operator==(const LeatherBackpack & A, const LeatherBackpack & B) {
    bool  result = true;
    if (A.getlaptop_department() == B.getlaptop_department()
        && A.getcolor() == B.getcolor()
        && A.getvolume() == B.getvolume()
        && A.getpurpose() == B.getpurpose()
        && A.getfirm().getName() == B.getfirm().getName()
        && A.getfirm().getCountry() == B.getfirm().getCountry()
        && A.getlining() == B.getlining()
        && A.getLeather() == B.getLeather()) {
        result &= true;
    }
    else {
        result &= false;
    }
    return result;
}

bool operator==(const FabricBackpack & A, const FabricBackpack & B) {
    bool  result = true;
    if (A.getlaptop_department() == B.getlaptop_department()
        && A.getcolor() == B.getcolor()
        && A.getvolume() == B.getvolume()
        && A.getpurpose() == B.getpurpose()
        && A.getfirm().getName() == B.getfirm().getName()
        && A.getfirm().getCountry() == B.getfirm().getCountry()
        && A.getwaterproof() == B.getwaterproof()
        && A.getFabric() == B.getFabric()) {
        result &= true;
    }
    else {
        result &= false;
    }
    return result;
}