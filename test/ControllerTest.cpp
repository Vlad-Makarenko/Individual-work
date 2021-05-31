//
// Created by Vlad on 28.05.2021.
//

#include "Controller.h"


class ControllerTest {
    Controller controller;
public:
    bool Test_FindGermanVelourBackpack() {
        bool result = true;

        LeatherBackpack leatherBackpack2(true, "Green", 51, Firm("Deuter", "Germany"), URBAN, false, VELOUR);
        controller.ReadFromFile("TestIn.txt");

        cout << "Ожидаемый результат:" << endl;
        PrintForm1();
        cout << endl;
        leatherBackpack2.Print();
        cout << endl;

        cout << endl << "Актуальный результат:" << endl;
        PrintForm1();
        cout << endl;
        vector<LeatherBackpack *> actual = controller.FindGermanVelourBackpack();
        cout << endl;

        if (actual[0]->getlaptop_department() == leatherBackpack2.getlaptop_department()
            && actual[0]->getcolor() == leatherBackpack2.getcolor()
            && actual[0]->getvolume() == leatherBackpack2.getvolume()
            && actual[0]->getpurpose() == leatherBackpack2.getpurpose()
            && actual[0]->getfirm().getCountry() == leatherBackpack2.getfirm().getCountry()
            && actual[0]->getfirm().getName() == leatherBackpack2.getfirm().getName()
            && actual[0]->getlining() == leatherBackpack2.getlining()
            && actual[0]->getLeather() == leatherBackpack2.getLeather()) {

            result &= true;
        } else {
            result &= false;
        }
        for (auto &i: actual) {
            actual.pop_back();
        }
        return result;
    }

    bool Test_FindSuedeNoLiningBackpack() {
        bool result = true;

        LeatherBackpack leatherBackpack1(true, "Orange", 38, Firm("Adidas", "Germany"), TACTICAL, false, SUEDE);
        LeatherBackpack leatherBackpack2(true, "Red", 44, Firm("Puma", "America"), TACTICAL, false, SUEDE);


        cout << "Ожидаемый результат:" << endl;
        PrintForm1();
        cout << endl;
        leatherBackpack1.Print();
        cout << endl;
        leatherBackpack2.Print();
        cout << endl;

        cout << endl << "Актуальный результат:" << endl;
        PrintForm1();
        cout << endl;
        vector<LeatherBackpack *> actual = controller.FindSuedeNoLiningBackpack();
        cout << endl;

        if (actual[0]->getlaptop_department() == leatherBackpack1.getlaptop_department()
            && actual[0]->getcolor() == leatherBackpack1.getcolor()
            && actual[0]->getvolume() == leatherBackpack1.getvolume()
            && actual[0]->getpurpose() == leatherBackpack1.getpurpose()
            && actual[0]->getfirm().getCountry() == leatherBackpack1.getfirm().getCountry()
            && actual[0]->getfirm().getName() == leatherBackpack1.getfirm().getName()
            && actual[0]->getlining() == leatherBackpack1.getlining()
            && actual[0]->getLeather() == leatherBackpack1.getLeather()) {

            result &= true;
        } else {
            result &= false;
        }
        for (auto &i: actual) {
            actual.pop_back();
        }
        return result;
    }


    bool Test_FindBlueMaxVolumeBackpack() {
        bool result = true;

        FabricBackpack fabricBackpack(false, "Blue", 39, Firm("Nike", "America"), TOURIST, true, SYNTHETICS);


        cout << "Ожидаемый результат:" << endl;
        PrintForm2();
        cout << endl;
        fabricBackpack.Print();
        cout << endl;

        cout << endl << "Актуальный результат:" << endl;
        vector<Backpack *> actual = controller.FindBlueMaxVolumeBackpack();
        cout << endl;

        auto F = (FabricBackpack*)actual[0]->clone();

        if(*F == fabricBackpack){
            result &= true;
        } else {
            result &= false;
        }
        for (auto &i: actual) {
            actual.pop_back();
        }

        delete F;
        return result;
    }
};

int main(){
    bool result;
    ControllerTest controllerTest;
    cout << "\n|-----------------------------------------------------------ТЕСТ МЕТОДА 1------------------------------------------------------------|\n\n";
    result = controllerTest.Test_FindGermanVelourBackpack();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|-----------------------------------------------------------ТЕСТ МЕТОДА 2------------------------------------------------------------|\n\n";
    result = controllerTest.Test_FindSuedeNoLiningBackpack();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|----------------------------------------------------------ТЕСТ МЕТОДА 3------------------------------------------------------------|\n\n";
    result = controllerTest.Test_FindBlueMaxVolumeBackpack();
    if (result){
        cout << endl << "РЕЗУЛЬТАТ ТЕСТА: Good job so far\n";
    }else{
        cout << "D'oh";
    }

    cout << "\n|------------------------------------------------------------------------------------------------------------------------------------|";
    return 0;
}