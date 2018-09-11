//This is the header file for the assignment Manager
#include <iostream>
#include <windows.h>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <String>

using namespace std;

const int ASIZE = 20;
const char filename[] ="assignments.txt";


class AssMgmt
{
public:
    /**DEFAULT CONSTRUCTOR**/
AssMgmt();//initializes member variables

    /**MUTATOR FUNCTIONS**/
void setDetails(string,string,string,string);
void deleteDetails();//this will be used to delete finished assignments
void updateDetails();//this will be used to update assignment data

    /**ACCESSOR FUNCTIONS**/
void writeDetails();//this will be used to write data to the file
void printCourse();//this will print all assigments from a specific course
void printDetails();//this will print all assignments
void readDetails();//this will be used to read data from the file
void reWriteDetails();//this will be used to re-write data to the file

private:
int counter;

struct AssData
    {
        string assName;
        string duedate;
        string details;
        string courseCode;
    }data[ASIZE];

};


