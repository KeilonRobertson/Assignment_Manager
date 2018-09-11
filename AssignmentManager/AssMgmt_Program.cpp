/*
    Program Name: Assignment Management
    Purpose: To assist with managing assignments
    Programmer Name: Keilon Robertson
    Date Created: 17/04/18
*/

#include <iostream>
#include <windows.h>
#include <cctype>
#include <fstream>
#include <iomanip>
#include "AssMgmt.h"

using namespace std;

int main()

{
    system("title Final Project - ASSIGNMENT MANAGER") ;
    system("COLOR 0B");
    //Declaring The Variables

    cout<< "\n\n\n\n\n\n\n\n\t\t\t\t********************************************";
    cout<< "\n\t\t\t\tWELCOME TO YOUR PERSONAL ASSIGNMENT MANAGER";
    cout<< "\n\t\t\t\t********************************************";
    cout << "\n\t\t\t\t\t";
    system("pause");
    system("cls");

    AssMgmt assignments;//class variable

    int option = 0;
    bool exitProg = false;
    string name,course,det,date;

    while (!exitProg)
    {

        assignments.readDetails();
        cout << "\n\t\t\t\t ********************";
        cout << "\n\t\t\t\t |ASSIGNMENT MANAGER|"<<endl;
        cout << "\t\t\t\t ********************"<<endl;
        cout << "\n\t\t\t\t 1. Add new Assignment" << endl ;
        cout << "\n\t\t\t\t 2. Update an Existing Assignment " << endl ;
        cout << "\n\t\t\t\t 3. Remove a completed Assignment " << endl ;
        cout << "\n\t\t\t\t 4. Display all Assignments in table format " << endl ;
        cout << "\n\t\t\t\t 5. Display all Assignments for a specific course " << endl ;
        cout << "\n\t\t\t\t 6. Help (How to use application) " << endl ;
        cout << "\n\t\t\t\t 7. Exit "  << endl ;

        cout << "\t\t\t\t Please enter an option(1-7) : " ;
        cin >> option ;
         system("pause");
         system("cls");

//MENU START
        switch(option)
        {
            /** ADD NEW ASSIGNMENT **/
        case 1 :
            cout << "\nPlease take a look at your current assignments:";
            assignments.printDetails();

            system("COLOR 02");

             cin.get();

            cout << "\nPlease enter the course code for this assignment: "<< endl;
            getline(cin,course);

            cout << "\n Please enter a name for this assignment to distinguish it from the others: "<<endl;
            getline(cin,name);

            cout << "\n Please enter any relevant details for this assignment: "<< endl;
            getline(cin,det);

            cout<< "\n Please enter the due date for this assignment: "<<endl;
            getline(cin,date);

            assignments.setDetails(course,name,det,date);
            assignments.writeDetails();
            break ;

        /** UPDATE ASSIGNMENT **/
        case 2 :
             cin.get();
            assignments.updateDetails();
            break;

        /** REMOVE ASSIGNMENT **/
        case 3:
            cin.get();
            assignments.deleteDetails();
            break;

       /** DISPLAY ALL ASIGNMENTS **/
        case 4:
            cin.get();
            assignments.printDetails();
            break;

        /** DISPLAY ASSIGNMENTS FOR A SPECIFC COURSE **/
        case 5:
             cin.get();
            assignments.printCourse();
            break;

        /** HELP(HOW TO USE APPLICATION **/
        case 6:
            system("COLOR 07");
            cout << "\n Hello There...This is the help page for this application...."<< endl;
            Sleep(2000);
            cout <<"\n Depending on what you want to do with the program, press the number on the start-up menu..."<< endl;
            Sleep(2000);
            cout << "\n Follow the step by step instructions given on each page and enter the details properly..." << endl;
            Sleep(2000);
            cout <<"\n Please get your assignments done on time!!"<<endl;
            Sleep(2000);
            cout << "\n If you need to add a new assignments,press 1"<<endl;
            Sleep(2000);
            cout << "\n If you need to update an assignment,press 2"<<endl;
            Sleep(2000);
            cout << "\n If you have completed an assignment and want to delete it ,press 3"<<endl;
            Sleep(2000);
            cout << "\n If you want to display all assignments, press 4"<<endl;
            Sleep(2000);
            cout << "\n If you want to display all assignments for a specific course, press 5"<<endl;
            Sleep(2000);
            cout << "\n If you want to exit, press 7"<<endl;
            system("pause");
            system("cls");
            break;

        /** EXIT PROGRAM **/
        case 7 :
            cout << " Good-bye " << endl ;
            exitProg = true ;
            break ;

        default :
            cout << "Invalid option !!!" << endl ;
            break;

        }//end switch structure
        //END OF MENU
    }
    return 0 ;
}

