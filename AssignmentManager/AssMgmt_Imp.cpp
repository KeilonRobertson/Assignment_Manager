//This is the implementation file for the assignment Manager

#include <iostream>
#include <windows.h>
#include <cctype>
#include <fstream>
#include <iomanip>
#include "AssMgmt.h"

using namespace std;

/** ALL FUNCTIONS **/

// DEFAULT CONSTRUCTOR
AssMgmt::AssMgmt()
{

    int counter = 0;
    for(int i=0; i<ASIZE; i++)
    {
        data[i].courseCode = "";
        data[i].duedate = "";
        data[i].details = "";
        data[i].assName="";
    }
}

//MUTATOR FUNCTIONS
void AssMgmt::setDetails(string course,string name,string det,string date)
{
    for(int i=0; i<ASIZE; i++)
    {
        data[i].courseCode = course;
        data[i].duedate = date;
        data[i].details = det;
        data[i].assName= name;
    }

}

/** FUNCTION TO WRITE ASSIGNMENTS TO FILE **/
void AssMgmt::writeDetails()//function to write new assignments to a file
{
    ofstream writeFile;

    writeFile.open(filename,ios::app);

    if(!writeFile)
    {
        cout <<" ** ERROR! ** " <<endl;

        cout <<"\a";
        cout << "CANNOT OPEN FILE!!!!" << endl;
        exit(1);
    }
    else
        for (int i = 0; i==0; i++)
        {
            writeFile<<data[i].courseCode << "\n" <<data[i].assName<< "\n" << data[i].details << "\n" << data[i].duedate <<endl ;
        }

    writeFile.close();
    system("pause");
    system("cls");
}//end write Details
//ACCESSOR FUNCTIONS


/** FUNCTION TO READ ASSIGNMENTS FROM FILES **/
void AssMgmt::readDetails()//function to read data from the file
{
    ifstream readFile;
    counter=0;
    readFile.open(filename,ios::in);

    if(!readFile)
    {
        cout <<"** ERROR! ** " <<endl;

        cout <<"\a";
        cout << "CANNOT OPEN FILE!!!!" << endl;
        exit(1);
    }
    else

        for (int i =0; i < ASIZE; i++)
        {
            counter++;
            getline(readFile,data[i].courseCode);
            getline(readFile,data[i].assName);
            getline(readFile,data[i].details);
            getline(readFile,data[i].duedate);

            Sleep(250);

            if(readFile.eof()) break;
        }
    readFile.close();
}//end read Details


/** FUNCTION TO REWRITE ASSIGNMENTS **/
void AssMgmt::reWriteDetails()
{
    ofstream reWriteFile;

    reWriteFile.open(filename);
    for(int i = 0; i <counter; i++)
    {
        if(data[i].courseCode!="")
        {
            reWriteFile <<data[i].courseCode << "\n" <<data[i].assName<< "\n" << data[i].details << "\n" << data[i].duedate<<endl;
        }
    }
    reWriteFile.close();
}


/** FUNCTION TO  PRINT ALL ASSIGNMENTS **/
void AssMgmt::printDetails()
{
    system("COLOR 0D");

    cout << "\nNo."<< "Course Code"<<"\t"<< "Assignments Name"<< "\t\t" << "Due Date"<< endl;

    for (int i = 0; i<counter; i++)
    {
        if(data[i].courseCode!="")
        {
            cout  << (i+1)<<"   "<< data[i].courseCode<<"\t"<<data[i].assName<<setw(40-data[i].assName.length())<<data[i].duedate <<endl<<endl;
            Sleep(500);
        }
    }
    system("pause");
    system("cls");
}//END PRINT DETAILS


/** FUNCTION TO PRINT SPECIFIC ASSIGNMENTS **/
void AssMgmt::printCourse()//function to print all data in a specific course
{
    system("COLOR 0C");

    for (int i = 0; i<counter; i++)
    {
        if(data[i].courseCode!="")
        {
            cout << "\n Course Code: " << data[i].courseCode
                 <<"\n Assignment Name: " << data[i].assName
                 << "\n Details: " << data[i].details
                 << "\n Due Date:"  << data[i].duedate << endl << endl;
            Sleep(500);
        }
    }

    int c=0;
    string code = "";

    cout <<"\nPlease enter the course Code from which you want your assignments to be displayed: "<<endl;
    getline(cin,code);

    for(int i = 0; i <counter; i++)
    {
        if (data[i].courseCode==code)
        {
            cout << "\n Course Code: " << data[c].courseCode
                 << "\nAssignment name: " << data[c].assName
                 << "\n Details: " << data[c].details
                 << "\n Due Date: " << data[c].duedate << endl << endl;
            Sleep(300);
        }
        c++;
    }//end for loop
    system("pause");
    system("cls");
}//end print Course assigments


/** FUNCTION TO DELETE ASSIGNMENTS **/
void AssMgmt::deleteDetails()
{
    system("COLOR 0A");
    int c = 0,num = 0,option=0;

    for (int i = 0; i<counter; i++)
    {
        if(data[i].courseCode!="")
        {
            c++;
            cout << "#"<<(i+1);
            cout << "\n Course Code: " << data[i].courseCode
                 <<"\n Assignment Name: " << data[i].assName
                 << "\n Details: " << data[i].details
                 << "\n Due Date:"  << data[i].duedate << endl << endl;
            Sleep(500);
        }
    }

    cout <<"\nPlease enter the NUMBER of the assignment that you have completed, and want to remove: ";
    cin >> num;


       cout <<"\n Are you sure you want to continue?(1 or 2) "
         << "\n 1.Yes"
         <<"\n 2.No"<<endl;
    cin>>option;

    switch(option)
    {
    case 1:
        data[num-1].courseCode = "";
        data[num-1].assName= "";
        data[num-1].details= "";
        data[num-1].duedate= "";
        cout << "Your assignment has been succesfully deleted!!!"<< endl;
        break;

    case 2:
        cout << "\n You have chosen to exit"<<endl;
        break;

    default:
        cout << "\n Invalid option!!!! \n You will now be transported back to the main menu !!! "<<endl;
        break;
    }


    reWriteDetails();
    system("pause");
    system("cls");
}//end delete details


/** FUNCTION TO UPDATE ASSIGNMENTS **/
void AssMgmt::updateDetails()//function for updating assignments
{
    system("COLOR 0E");
    int c = 0,option =0;
    string code = "",name="",details="",date="";
    int num = 0;
    bool exitLoop=false;

    for (int i = 0; i<counter; i++)
    {
        if(data[i].courseCode!="")
        {
            cout << "#"<<(i+1);
            cout << "\n Course Code: " << data[i].courseCode
                 <<"\n Assignment Name: " << data[i].assName
                 << "\n Details: " << data[i].details
                 << "\n Due Date:"  << data[i].duedate << endl << endl;
            Sleep(500);
        }
    }

    cout <<"\nFrom the list above, please enter the number of the assignment that you want to update: "<<endl;
    cin>> num;

    while(!exitLoop)
    {
        cout << "\n1.Change Course Code"<<endl;
        cout << "\n2.Change Assignment name"<< endl;
        cout << "\n3.Change Assignment Details"<< endl;
        cout << "\n4.Change Due Date"<< endl;
        cout << "\n5.Exit to Main Menu"<<endl;

        cin>>option;

        system("pause");
        cin.get();
        switch(option)
        {
        case 1:
            cout << "\nEnter the updated course code: "<< endl;
            getline(cin,code);
            data[num-1].courseCode=code;
            break;

        case 2:
            cout << "\nEnter the updated Assignment name: "<< endl;
            getline(cin,name);
            data[num-1].assName=name;
            break;
        case 3:
            cout << "\nEnter the updated assignment details: "<< endl;
            getline(cin,details);
            data[num-1].details=details;
            break;
        case 4 :
            cout << "\nEnter the updated due date: "<< endl;
            getline(cin,date);
            data[num-1].duedate=date;
            break;

        case 5:
            cout <<"\n You have decided to exit.....Goodbye...."<<endl;
            exitLoop=true;
            break;

        default:
            cout << "\n\nINVALID OPTION!!"<< endl;
            break;
        }//end switch structure

    }//end while loop
    c++;
    //}//end for loop
    reWriteDetails();//REWRITES BACK TO THE FILE WITH THE UPDATED DATA
    system("pause");
    system("cls");
}//end update assignment
