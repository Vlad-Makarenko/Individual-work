//
// Created by Vlad on 28.05.2021.
//

/**
 * @file Menu.cpp
 * @brief Файл з реалізацією методів класу-меню
 *
 * @author Makarenko V.
 * @date 26-may-2021
 * @version 1.0
 */

#include "Menu.h"

int  Menu::ShowMenu()  {
    int action;
    cout << "//==============================================================[ Menu ]==============================================================\\\\" << endl;
    cout << "|| 1. Display the list on the screen.\n"
            "|| 2. Add a new item.\n"
            "|| 3. Display the element by index.\n"
            "|| 4. Modify the element by index.\n"
            "|| 5. Remove an item from the list.\n"
            "|| 6. Sort the list.\n"
            "|| 7. Find a German velor urban backpack.\n"
            "|| 8. Find an unlined suede backpack.\n"
            "|| 9. Find the blue backpack with the largest volume.\n"
            "|| 10. Write the list to the file.\n"
            "|| 11. Clear the list.\n"
            "|| 12. Exit.\n";
    cout << "||------------------------------------------------------------------------------------------------------------------------------------||" << endl;
    cout << "|| Choose an action: ";
    cin >> action;
    cout << "\\\\====================================================================================================================================//" << endl << endl;
    if(action < 1 || action > 12) {
        throw std::out_of_range("Out of range exception");
    }
    return action;
}

void Menu::Run() {
    int action;
    int pos;
    bool runner = true;
    bool checker = true;
    string path;
    while (checker){
        cout << "> Enter file name: ";
        cin >> path;
        checker = controller.ReadFromFile(path);
    }
    while (runner) {
        try {
            action = ShowMenu();
            switch (action) {
                case 1:
                    cout << "//=========================================================[ ORIGINAL LIST ]==========================================================\\\\" << endl;
                    PrintForm3();
                    cout << endl;
                    controller.getList()->ShowAll();
                    cout << "\\\\====================================================================================================================================//" << endl;
                    cout << endl;
                    break;
                case 2:
                    cout << "//=======================================================[ ADDING A NEW ITEM ]========================================================\\\\" << endl;
                    controller.getList()->NewBackpack();
                    cout << "\\\\====================================================================================================================================//" << endl;
                    cout << endl;
                    break;
                case 3:
                    cout << "//==========================================================[ ITEM BY INDEX ]=========================================================\\\\" << endl;
                    cout << "|| > Enter the position to display the element from: ";
                    cin >> pos;
                    {
                        if (controller.getList()->getBackpackByIndex(pos)->clone()->GetType() == 'L') {
                            PrintForm1();
                            auto item = (LeatherBackpack *) controller.getList()->getBackpackByIndex(pos);
                            LeatherBackpack Le(item->getlaptop_department(), item->getcolor(), item->getvolume(),
                                               Firm(item->getfirm().getName(), item->getfirm().getCountry()),
                                               item->getpurpose(), item->getlining(), item->getLeather());
                            cout << endl << Le << endl;
                            delete item;
                        } else {
                            PrintForm2();
                            auto item = (FabricBackpack *) controller.getList()->getBackpackByIndex(pos);
                            FabricBackpack F(item->getlaptop_department(), item->getcolor(), item->getvolume(),
                                             Firm(item->getfirm().getName(), item->getfirm().getCountry()),
                                             item->getpurpose(), item->getwaterproof(), item->getFabric());
                            cout << endl << F << endl;
                            delete item;
                        }
                    }
                    cout << "\\\\====================================================================================================================================//" << endl;
                    cout << endl;
                    break;
                case 4:
                    cout << "//======================================================[ CHANGE ITEM BY INDEX ]======================================================\\\\" << endl;
                    cout << "|| > Enter the index of the element you want to change: ";
                    cin >> pos;
                    controller.getList()->DeleteElement(pos);
                    if (controller.getList()->getBackpackByIndex(pos)->GetType() == 'L') {
                        LeatherBackpack L;
                        cin >> L;
                        if(L.getcolor() == "") throw std::invalid_argument("Bad Argument");
                        controller.getList()->addBackpackByIndex(&L, pos);
                    }else{
                        FabricBackpack F;
                        cin >> F;
                        if(F.getcolor() == "") throw std::invalid_argument("Bad Argument");
                        controller.getList()->addBackpackByIndex(&F, pos);
                    }
                    cout << "\\\\====================================================================================================================================//" << endl;
                    cout << endl;
                    break;
                case 5:
                    cout << "//==========================================================[ DELETE ITEM ]===========================================================\\\\" << endl;
                    cout << "|| > Enter the position from which to remove the element: ";
                    cin >> pos;
                    controller.getList()->DeleteElement(pos);
                    cout << "\\\\====================================================================================================================================//" << endl;
                    cout << endl;
                    break;
                case 6:
                    cout << "//===========================================================[ SORT LIST ]============================================================\\\\" << endl;
                    cout << "|| > Select a sorting criterion: \n";
                    cout << "|| 1. Space for a laptop.\n"
                            "|| 2. Color.\n"
                            "|| 3. Volume.\n"
                            "|| 4. Purpose.\n"
                            "|| 5. The name of the company.\n"
                            "|| 6. Country of origin.\n";
                    cout << "||------------------------------------------------------------------------------------------------------------------------------------||" << endl;
                    cout << "|| > Your choice: ";
                    cin >> pos;
                    cout << "||------------------------------------------------------------------------------------------------------------------------------------||" << endl;
                    int dir;
                    cout << "|| > Select sorting direction:\n"
                            "|| 1. From smallest to largest.\n"
                            "|| 0. From the largest to the smallest.\n";
                    cout << "||------------------------------------------------------------------------------------------------------------------------------------||" << endl;
                    cout << "|| > Your choice: ";
                    cin >> dir;
                    if( dir < 0 || dir > 2) throw std::out_of_range("Out of range exception");
                    controller.SortByCriterion(pos, dir);
                    cout << "\\\\====================================================================================================================================//" << endl;
                    cout << endl;
                    break;
                case 7:
                    cout << "//==============================================[ GERMAN URBAN BACKPACK WITH VELOUR ]=================================================\\\\" << endl;
                    PrintForm1();
                    cout << endl;
                    controller.FindGermanVelourBackpack();
                    cout << "\\\\====================================================================================================================================//" << endl;
                    cout << endl;
                    break;
                case 8:
                    cout << "//================================================[ SUEDE BACKPACK WITHOUT LINING ]===================================================\\\\" << endl;
                    PrintForm1();
                    cout << endl;
                    controller.FindSuedeNoLiningBackpack();
                    cout << "\\\\====================================================================================================================================//" << endl;
                    cout << endl;
                    break;
                case 9:
                    cout << "//==================================================[ BLUE MAX VOLUME BACKPACK ]======================================================\\\\" << endl;
                    cout << endl;
                    controller.FindBlueMaxVolumeBackpack();
                    cout << "\\\\====================================================================================================================================//" << endl;
                    cout << endl;
                    break;
                case 10:
                    cout << "//=========================================================[ WRITE TO FILE ]==========================================================\\\\" << endl;
                    controller.WriteToFile();
                    cout << "\\\\====================================================================================================================================//" << endl;
                    cout << endl;
                    break;
                case 11:
                    cout << "//=========================================================[ CLEAR THE LIST ]=========================================================\\\\" << endl;
                    controller.getList()->DeleteAll();
                    cout << "|| > List cleared" << endl;
                    cout << "|| > Enter the file name from where to read the new list" << endl;
                    {bool check = true;
                    while (check){
                        cout << "|| ";
                        cout << "> Enter file name: ";
                        cin >> path;
                        check = controller.ReadFromFile(path);
                    }}
                    cout << "\\\\====================================================================================================================================//" << endl;
                    cout << endl;
                    break;
                case 12:
                    runner = false;
                    break;
                default:
                    break;
            }
        }
        catch (std::out_of_range & e){
            cout << endl << "ERROR: " << e.what() << endl << endl;
        }
        catch (std::ios_base::failure & e){
            cout << endl << "ERROR: " << e.what() << endl << endl;
        }
        catch (std::invalid_argument & e){
            cout << endl << "ERROR: The program terminated abnormally. " << e.what() << endl << endl;
            runner = false;
        }
    }
}
