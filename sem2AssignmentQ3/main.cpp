/*#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

// Data structure to represent a Club
class Club {
private:
    string name;
    //change unordered set and attributes names
    unordered_set<string> members;  // Stores student IDs who are part of this club

    Club(string clubName) : name(clubName) {}
};

struct Club {
// string name;
//string members;
// add unordered map
// put everything in the struct
};


// Data structure to represent a Student
class Student {
public:
    string studentID;
    string firstName;
    string lastName;
    unordered_set<string> clubs;  // Stores names of clubs the student belongs to

    Student(string id, string fName, string lName)
        : studentID(id), firstName(fName), lastName(lName) {}
};

// Graph using adjacency list to represent student-club relationships
class ClubHub {
private:
    unordered_map<string, Student> students;  // Student ID -> Student object
    unordered_map<string, Club> clubs;        // Club name -> Club object

public:
    // Function to add a new student
    void addStudent(const string& id, const string& firstName, const string& lastName) {
        if (students.find(id) == students.end()) {
            students[id] = Student(id, firstName, lastName);
            cout << "Student added: " << firstName << " " << lastName << endl;
        } else {
            cout << "Student with ID " << id << " already exists." << endl;
        }
    }

    // Function to create a new club
    void createClub(const string& clubName) {
        if (clubs.find(clubName) == clubs.end()) {
            clubs[clubName] = Club(clubName);
            cout << "Club created: " << clubName << endl;
        } else {
            cout << "Club " << clubName << " already exists." << endl;
        }
    }

    // Function to add a student to a club
    void addStudentToClub(const string& studentID, const string& clubName) {
        if (students.find(studentID) == students.end()) {
            cout << "Student ID " << studentID << " not found." << endl;
            return;
        }
        if (clubs.find(clubName) == clubs.end()) {
            cout << "Club " << clubName << " not found." << endl;
            return;
        }

        // Add student to the club's member list
        clubs[clubName].members.insert(studentID);
        // Add the club to the student's club list
        students[studentID].clubs.insert(clubName);
        cout << "Student " << studentID << " added to club " << clubName << endl;
    }

    // Function to remove a student from a club
    void removeStudentFromClub(const string& studentID, const string& clubName) {
        if (students.find(studentID) == students.end()) {
            cout << "Student ID " << studentID << " not found." << endl;
            return;
        }
        if (clubs.find(clubName) == clubs.end()) {
            cout << "Club " << clubName << " not found." << endl;
            return;
        }

        // Remove student from the club
        clubs[clubName].members.erase(studentID);
        // Remove the club from the student's list
        students[studentID].clubs.erase(clubName);
        cout << "Student " << studentID << " removed from club " << clubName << endl;
    }

    // Search for all clubs a student is a member of
    void findClubsOfStudent(const string& studentID) {
        if (students.find(studentID) != students.end()) {
            cout << "Clubs of student " << studentID << ": ";
            for (const string& club : students[studentID].clubs) {
                cout << club << " ";
            }
            cout << endl;
        } else {
            cout << "Student ID " << studentID << " not found." << endl;
        }
    }

    // Search for all students who are in a specific club
    void findStudentsInClub(const string& clubName) {
        if (clubs.find(clubName) != clubs.end()) {
            cout << "Students in club " << clubName << ": ";
            for (const string& studentID : clubs[clubName].members) {
                cout << students[studentID].firstName << " " << students[studentID].lastName << " ";
            }
            cout << endl;
        } else {
            cout << "Club " << clubName << " not found." << endl;
        }
    }

    // Sort students alphabetically by last name using Bubble Sort
    void sortStudents() {
        vector<Student> studentList;
        for (const auto& [id, student] : students) {
            studentList.push_back(student);
        }

        // Bubble sort based on last name
        bool swapped;
        do {
            swapped = false;
            for (size_t i = 0; i < studentList.size() - 1; ++i) {
                if (studentList[i].lastName > studentList[i + 1].lastName) {
                    swap(studentList[i], studentList[i + 1]);
                    swapped = true;
                }
            }
        } while (swapped);

        // Print sorted students
        cout << "Students sorted by last name:\n";
        for (const auto& student : studentList) {
            cout << student.firstName << " " << student.lastName << endl;
        }
    }

    // Save the current system state to a text file
    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing.\n";
            return;
        }

        // Save students
        file << students.size() << endl;
        for (const auto& [id, student] : students) {
            file << student.studentID << " " << student.firstName << " " << student.lastName << endl;
        }

        // Save clubs and memberships
        file << clubs.size() << endl;
        for (const auto& [name, club] : clubs) {
            file << club.name << endl;
            for (const string& member : club.members) {
                file << member << " ";
            }
            file << endl;
        }

        file.close();
        cout << "System state saved to " << filename << endl;
    }

    // Load the system state from a text file
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file for reading.\n";
            return;
        }

        // Clear current data
        students.clear();
        clubs.clear();

        // Load students
        int studentCount;
        file >> studentCount;
        for (int i = 0; i < studentCount; ++i) {
            string id, firstName, lastName;
            file >> id >> firstName >> lastName;
            students[id] = Student(id, firstName, lastName);
        }

        // Load clubs and memberships
        int clubCount;
        file >> clubCount;
        for (int i = 0; i < clubCount; ++i) {
            string clubName;
            file >> clubName;
            clubs[clubName] = Club(clubName);

            string memberID;
            while (file >> memberID && memberID != "-1") {
                clubs[clubName].members.insert(memberID);
                students[memberID].clubs.insert(clubName);
            }
        }

        file.close();
        cout << "System state loaded from " << filename << endl;
    }
};

int main() {
    ClubHub clubHub;
    int choice;
    string studentID, firstName, lastName, clubName;

    while (true) {
        cout << "\nClub Management System\n";
        cout << "1. Add a student\n";
        cout << "2. Create a club\n";
        cout << "3. Add student to a club\n";
        cout << "4. Remove student from a club\n";
        cout << "5. Find clubs of a student\n";
        cout << "6. Find students in a club\n";
        cout << "7. Sort and display students by last name\n";
        cout << "8. Save system state to file\n";
        cout << "9. Load system state from file\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student ID: ";
                cin >> studentID;
                cout << "Enter first name: ";
                cin >> firstName;
                cout << "Enter last name: ";
                cin >> lastName;
                clubHub.addStudent(studentID, firstName, lastName);
                break;

            case 2:
                cout << "Enter club name: ";
                cin >> clubName;
                clubHub.createClub(clubName);
                break;

            case 3:
                cout << "Enter student ID: ";
                cin >> studentID;
                cout << "Enter club name: ";
                cin >> clubName;
                clubHub.addStudentToClub(studentID, clubName);
                break;

            case 4:
                cout << "Enter student ID: ";
                cin >> studentID;
                cout << "Enter club name: ";
                cin >> clubName;
                clubHub.removeStudentFromClub(studentID, clubName);
                break;

            case 5:
                cout << "Enter student ID: ";
                cin >> studentID;
                clubHub.findClubsOfStudent(studentID);
                break;

            case 6:
                cout << "Enter club name: ";
                cin >> clubName;
                clubHub.findStudentsInClub(clubName);
                break;

            case 7:
                clubHub.sortStudents();
                break;

            case 8:
                clubHub.saveToFile("clubhub_data.txt");
                break;

            case 9:
                clubHub.loadFromFile("clubhub_data.txt");
                break;

            case 10:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}*/

/*#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dos.h>
#include <time.h>

void password();*/

/*#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>

void password();
void mainmenu(void);
void addmember(void);
void deletemember(void);
void searchmember(void);
void viewmember(void);
void editmember(void);
void closeapp(void);
void returnfunc(void);
void event(void);
int t(void);



void addevent(void);
void vieweevent(void);
void deleteevent(void);

///list of global files
FILE *fp,*ft,*fs;
COORD coord = {0, 0};

int fm;

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct member{
    int ID;
    char name[20];
    char add[20];
    char dept[20];
    int Phone_no;

    int no;
    char title[20];
    char z[100];
    char date[20];

};

struct member stu;




int main(){
password();
getch();
return 0;
}

void mainmenu(){
    int choice;
    system("cls");
    gotoxy(20,3);
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd MAIN MENU \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,5);printf("1. Add Members\n");
gotoxy(20,7);printf("2. Delete Members\n");
gotoxy(20,9);printf("3. Search Members\n");
gotoxy(20,11);printf("4. View Members\n");
gotoxy(20,13);printf("5. Event\n");
gotoxy(20,15);printf("6. Edit Members Information\n");
gotoxy(20,17);printf("7. Close application\n");
gotoxy(20,18);printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,19);t();
gotoxy(20,23);
printf("Enter Your Choice: ");
//scanf("%d",&choice);
switch(getch()){
case '1':
addmember();
break;
case '2':
deletemember();
break;
case '3':
searchmember();
break;
case '4':
viewmember();
break;
case '5':
event();
break;
case'6':
editmember();
case '7':{
system("cls");
gotoxy(16,3);
printf("\t IT CLUB Management System\n");
gotoxy(16,5);
printf("THANK YoU FoR USING OUR PROGRAM");
printf("\n\n*****************************************************************************");

exit(0);
}
default:{
gotoxy(20,22);printf("Wrong!!Correct Option");
if (getch())
mainmenu();

}
}

//return 0;
}
void addmember(void){
system("cls");

      gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Add MEMBER INFO \xcd\xcd\xcd");
    int print = 25;
    FILE *fp;
    fp = fopen("record_nxt.txt","ab+");
//    SetColor(45);
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }
    else

    {
        ///fflush(stdin);
        gotoxy(print,6);printf("Member ID: ");scanf("%d",&stu.ID);
        //here you can confirms the ID
        fflush(stdin);
        gotoxy(print,8);printf("Name: ");gets(stu.name);
        gotoxy(print,10);printf("Address: ");gets(stu.add);
        gotoxy(print,12);printf("dept. name: ");gets(stu.dept);
        gotoxy(print,14);printf("Phone Number: ");scanf("%d",&stu.Phone_no);
        ///gotoxy(print,20);printf("Phone Number: ");scanf("%d",&stu.phone_no);
        fwrite(&stu, sizeof(stu), 1, fp);

    }

    fclose(fp);
    gotoxy(40,17); printf("The record is sucessfully added");
     gotoxy(40,18);printf("Save any more Y/N");
    if(getch()=='n')
    mainmenu();
    else
    system("cls");
    addmember();
}




void deletemember( ){
system ("cls");
gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Delete MEMBER  \xcd\xcd\xcd");



    ///print_heading("Delete Record");
    ///SetColor(45);
    char m_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);printf("Enter ID to Delete: ");fflush(stdin);
    gets(m_id);
    FILE *fp, *temp;
    fp = fopen("record_nxt.txt","rb");
    temp = fopen("temp.txt", "wb");
    while(fread(&stu, sizeof(stu),1,fp) == 1)
    printf("record found");{
        if(strcmp(m_id, stu.ID) == 0){
            ///printf("record found");
            fwrite(&stu,sizeof(stu),1,temp);
        }

    }
    fclose(fp);
    fclose(temp);
    remove("record_nxt.txt");
    rename("temp.txt","record_nxt.txt");
    gotoxy(37,12);printf("The record is sucessfully deleted\n");
    returnfunc();

///    SetColor(28);
    return;





int d;
char another='y';
while(another=='y')  //infinite loop
{
    system("cls");
    gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Delete MEMBER  \xcd\xcd\xcd");
gotoxy(10,5);
printf("Enter the Member ID to  delete:");
scanf("%d",&d);
fp=fopen("record_nxt.txt","rb+");
rewind(fp); ///reposition file pointer to sream's beggining
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID==d)
{


gotoxy(10,8);
printf("Member name is %s",stu.name);
gotoxy(10,9);
//printf("phone No. is %d",stu.phone);
fm='Z';
}
}
if(fm!='Z')
{
gotoxy(10,10);
printf("No record is found in LIST");
if(getch())
mainmenu();
}
if(fm=='Z' )
{
gotoxy(10,7);
printf("The Member is available");
gotoxy(10,10);
printf("Do you want to delete it?(Y/N):");
if(getch()=='y')
{
ft=fopen("test.txt","wb+");  //temporary file for delete
rewind(fp);
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID!=d)
{
///fseek(ft,0,SEEK_CUR);
fwrite(&stu,sizeof(stu),1,ft); //write all in tempory file except that
}                              //we want to delete
}
fclose(ft);
fclose(fp);
remove("record_nxt.txt");
rename("test.txt","record_nxt.txt"); //copy all item from temporary file to fp except that
fp=fopen("record_nxt.txt","rb+");    //we want to delete
if(fm=='Z')
{
gotoxy(10,10);
printf("The record is sucessfully deleted");
gotoxy(10,11);
printf("Delete another record?(Y/N)");
}
}
else
mainmenu();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
mainmenu();
///returnfunc();

}


void searchmember(void){
system("cls");
int s;
gotoxy(10,3);
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd SEARCH MEMBER \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(10,5);
printf("Enter the Member ID to  search:");
scanf("%d",&s);
fp=fopen("record_nxt.txt","rb+");
rewind(fp); ///reposition file pointer to sream's beggining
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID==s)
{

gotoxy(10,7);
printf("The Member is available");

gotoxy(10,9);
printf("ID: %d",stu.ID);
gotoxy(10,10);
printf("Name: %s",stu.name);
gotoxy(10,11);
printf("ADress: %s",stu.add);
gotoxy(10,12);
printf("Dept. : %s",stu.dept);
gotoxy(10,13);
printf("Phone nO: %d",stu.Phone_no);

fm='Z';
}
}
if(fm!='Z')
{
gotoxy(10,10);
printf("No record is found in LIST");
if(getch())

mainmenu();
}

{
gotoxy(10,9);
printf("");
fclose(fp);
returnfunc();
getch();
}}

void viewmember(void){

system("cls");

FILE *fp;
int i=0,j;
system("cls");
gotoxy(15,1);
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Members List \xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(2,3);
printf(" MEM_ID    MEMBER NAME    ADDRESS     DEPT      PHONE_NO    ");
j=5;
fp=fopen("record_nxt.txt","rb");
while(fread(&stu,sizeof(stu),1,fp)==1)
{
gotoxy(3,j);
printf("%d",stu.ID);
gotoxy(14,j);
printf("%s",stu.name);
gotoxy(28,j);
printf("%s",stu.add);
gotoxy(40,j);
printf("%s",stu.dept);
gotoxy(50,j);
printf("%d",stu.Phone_no);
///gotoxy(57,j);
///printf("%d",stu.phone_no);
gotoxy(69,j);
///printf("%d",a.rackno);
printf("\n\n");
j++;
i=i+1;
}
gotoxy(3,25);
printf("Total Members =%d",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
getch();
}

void event(void){

system("cls");
int i;
gotoxy(20,3);
printf("\xcd\xcd\xcd\xcd\xcd\xcd EVENT MENU \xcd\xcd\xcd\xcd\xcd\xcd");
//    show_mouse();
gotoxy(20,5);
printf("1. Add Event   ");
gotoxy(20,7);
printf("2. View Event");
gotoxy(20,9);
printf("3. Delete Event");
gotoxy(20,11);
printf("4. Mainmenu");
gotoxy(20,12);printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,15);printf("Enter Your Choice");
switch(getch()){
case '1':
addevent();
break;
case '2':
vieweevent();
break;
case '3':
deleteevent();
case'4':
mainmenu();
default:{
gotoxy(20,22);printf("Wrong!!Correct Option\a");
if (getch())
mainmenu();

}
}
}

void addevent(){
    system("cls");
gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Add Event \xcd\xcd\xcd");
    int print = 25;
    fp = fopen("record.dat","ab+");
//    SetColor(45);
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }else{
        ///fflush(stdin);
        ///gotoxy(print,10);printf("event no: ");scanf("%d",&stu.no);
        //here you can confirms the ID
        fflush(stdin);
        gotoxy(print,5);printf("event date:");gets(stu.date);
        gotoxy(print,6);printf("Event name: ");gets(stu.title);
        gotoxy(print,7);printf("Details: ");gets(stu.z);
        fwrite(&stu, sizeof(stu), 1, fp);
        gotoxy(40,12); printf("The record is sucessfully added");
    }

    fclose(fp);
gotoxy(40,13);printf("Save any more Y/N");
    if (getch()=='n')
    mainmenu();
    else
    system("cls");
    addevent();

gotoxy(25,20);
returnfunc();
getch();
}

void deleteevent()
{
    system("cls");
    char date[20];
   fflush(stdin);

    printf("\n\n\t..::DELETE event\n\t==========================\n\t..::Enterthe date to delete:");

    gets(date);
    fp=fopen("record.dat","r");
    ft=fopen("temp.dat","w");
    while(fread(&stu,sizeof(stu),1,fp)!=0)
    if (stricmp(date,stu.date)!=0)
    fwrite(&stu,sizeof(stu),1,ft);
    fclose(fp);
    fclose(ft);
    remove("record.dat");
    rename("temp.dat","record.dat");
    printf("\n\t\tRecord is delete");
    ///printf("Invalid choice");
gotoxy(25,25);
returnfunc();
getch();
}



void vieweevent()
{
    system("cls");

int j=5;
gotoxy(1,1);
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd view events \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(1,3);printf("Event date         event name               Details");

fp=fopen("record.dat","rb");
while(fread(&stu,sizeof(stu),1,fp)==1)
{

gotoxy(1,j);
printf("%s",stu.date);
gotoxy(18,j);
printf("%s",stu.title);
gotoxy(46,j);
printf("%s",stu.z);
j++;
}
fclose(fp);

gotoxy(25,25);
returnfunc();
getch();
}


void editmember(void){
system("cls");

int s,print=37;
gotoxy(15,3);
printf("\xcd\xcd\xcd\xcd\xcd\xcd Edit MEMBER info \xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(10,5);
printf("Enter the Member ID to edit:");
scanf("%d",&s);
fp=fopen("record_nxt.txt","rb+");
///rewind(fp); ///reposition file pointer to sream's beggining
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID==s)
{

gotoxy(10,7);
printf("The Member is available");
//gotoxy(print,10);printf("ID: ");scanf("%d",&stu.ID);
        //here you can confirms the ID
        fflush(stdin);
        gotoxy(print,12);printf("Name: ");gets(stu.name);
        gotoxy(print,14);printf("Address: ");gets(stu.add);
        gotoxy(print,16);printf("dept. name: ");gets(stu.dept);
        gotoxy(print,18);printf("Phone Number: ");scanf("%d",&stu.Phone_no);
        gotoxy(print,22);printf("The record is modified");
        fseek(fp,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);

fm=1;
break;
}
}
if(fm!=1)
{
gotoxy(10,10);
printf("No record is found in LIST");
if(getch())
mainmenu();
}

fclose(fp);

gotoxy(37,22);
returnfunc();
getch();
}



void returnfunc(void){{
    gotoxy(25,25);
printf("Press ENTER to return the main menu");
}
if(getch()==13)
mainmenu();
}
int t(void){
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}


void password(void){
system("cls");
char pass[10],ch,password[10]="z";
int i=0;
gotoxy(25,2);
printf("==== IT CLUB MANAGEMENT SYSTEM ====");
gotoxy(20,5);
printf("Enter the password to Login:");
//scanf("%s",pass);
while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';


if(strcmp(pass,password)==0){
gotoxy(13,8);
    printf("Password Matched!!");
    gotoxy(14,9);
    printf("Loading ");
for(i=0;i<=6;i++)
        {
            fordelay(100000000);

            printf(".");
        }
                system("cls");
            mainmenu();
        }
        else
        gotoxy(15,13);
        printf("Password is invalid!!\a");
        printf("\tENTER correct password");
        getch();
        main();
}*/

/*#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;

// Student structure to store student information
struct Student {
    int id;
    string firstName;
    string lastName;
    vector<string> clubs;  // List of clubs the student belongs to
};

// Club structure to store club information
struct Club {
    string name;
    vector<int> memberIds;  // List of student IDs who are members
};

// Graph class to represent student connections
class StudentGraph {
private:
    map<int, list<int>> adjacencyList;  // Student ID -> List of connected student IDs

public:
    // Add edge between two students (represents shared club membership)
    void addEdge(int student1Id, int student2Id) {
        adjacencyList[student1Id].push_back(student2Id);
        adjacencyList[student2Id].push_back(student1Id);
    }

    // Remove edge between students (when leaving shared club)
    void removeEdge(int student1Id, int student2Id) {
        adjacencyList[student1Id].remove(student2Id);
        adjacencyList[student2Id].remove(student1Id);
    }

    // Get all connected students (those sharing clubs)
    vector<int> getConnections(int studentId) {
        vector<int> connections;
        for (int connectedId : adjacencyList[studentId]) {
            connections.push_back(connectedId);
        }
        return connections;
    }
};

class ClubHub {
private:
    vector<Student> students;
    vector<Club> clubs;
    StudentGraph studentConnections;

public:
    // Add a new student to the system
    void addStudent(int id, string firstName, string lastName) {
        Student newStudent = {id, firstName, lastName};
        students.push_back(newStudent);
    }

    // Create a new club
    void createClub(string name) {
        Club newClub = {name};
        clubs.push_back(newClub);
    }

    // Add a student to a club
    void addStudentToClub(int studentId, string clubName) {
        // Find the student and club
        auto student = find_if(students.begin(), students.end(),
            [studentId](const Student& s) { return s.id == studentId; });

        auto club = find_if(clubs.begin(), clubs.end(),
            [clubName](const Club& c) { return c.name == clubName; });

        if (student != students.end() && club != clubs.end()) {
            // Add club to student's list
            student->clubs.push_back(clubName);

            // Add student to club's member list
            club->memberIds.push_back(studentId);

            // Create edges with other club members
            for (int memberId : club->memberIds) {
                if (memberId != studentId) {
                    studentConnections.addEdge(studentId, memberId);
                }
            }
        }
    }

    // Remove a student from a club
    void removeStudentFromClub(int studentId, string clubName) {
        // Find the student and club
        auto student = find_if(students.begin(), students.end(),
            [studentId](const Student& s) { return s.id == studentId; });

        auto club = find_if(clubs.begin(), clubs.end(),
            [clubName](const Club& c) { return c.name == clubName; });

        if (student != students.end() && club != clubs.end()) {
            // Remove club from student's list
            student->clubs.erase(
                remove(student->clubs.begin(), student->clubs.end(), clubName),
                student->clubs.end()
            );

            // Remove student from club's member list
            club->memberIds.erase(
                remove(club->memberIds.begin(), club->memberIds.end(), studentId),
                club->memberIds.end()
            );

            // Remove edges with other club members
            for (int memberId : club->memberIds) {
                studentConnections.removeEdge(studentId, memberId);
            }
        }
    }

    // Find all clubs a student is member of
    vector<string> findStudentClubs(int studentId) {
        auto student = find_if(students.begin(), students.end(),
            [studentId](const Student& s) { return s.id == studentId; });

        if (student != students.end()) {
            return student->clubs;
        }
        return vector<string>();
    }

    // Find all students in a specific club
    vector<Student> findClubMembers(string clubName) {
        vector<Student> members;
        auto club = find_if(clubs.begin(), clubs.end(),
            [clubName](const Club& c) { return c.name == clubName; });

        if (club != clubs.end()) {
            for (int memberId : club->memberIds) {
                auto student = find_if(students.begin(), students.end(),
                    [memberId](const Student& s) { return s.id == memberId; });
                if (student != students.end()) {
                    members.push_back(*student);
                }
            }
        }
        return members;
    }

    // Sort students by last name (using bubble sort)
    void sortStudentsByLastName() {
        int n = students.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (students[j].lastName > students[j+1].lastName) {
                    swap(students[j], students[j+1]);
                }
            }
        }
    }

    // Save system state to file
    void saveToFile(string filename) {
        ofstream file(filename);

        // Save students
        file << "STUDENTS\n";
        for (const Student& student : students) {
            file << student.id << "," << student.firstName << ","
                 << student.lastName << "\n";
        }

        // Save clubs
        file << "CLUBS\n";
        for (const Club& club : clubs) {
            file << club.name << ":";
            for (int memberId : club.memberIds) {
                file << memberId << ",";
            }
            file << "\n";
        }

        file.close();
    }

    // Load system state from file
    void loadFromFile(string filename) {
        ifstream file(filename);
        string line;
        string section = "";

        while (getline(file, line)) {
            if (line == "STUDENTS") {
                section = "STUDENTS";
                continue;
            }
            else if (line == "CLUBS") {
                section = "CLUBS";
                continue;
            }

            if (section == "STUDENTS") {
                // Parse student data
                size_t pos1 = line.find(",");
                size_t pos2 = line.find(",", pos1 + 1);
                if (pos1 != string::npos && pos2 != string::npos) {
                    int id = stoi(line.substr(0, pos1));
                    string firstName = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    string lastName = line.substr(pos2 + 1);
                    addStudent(id, firstName, lastName);
                }
            }
            else if (section == "CLUBS") {
                // Parse club data
                size_t pos = line.find(":");
                if (pos != string::npos) {
                    string clubName = line.substr(0, pos);
                    createClub(clubName);

                    string members = line.substr(pos + 1);
                    size_t start = 0;
                    size_t end = members.find(",");
                    while (end != string::npos) {
                        int memberId = stoi(members.substr(start, end - start));
                        addStudentToClub(memberId, clubName);
                        start = end + 1;
                        end = members.find(",", start);
                    }
                }
            }
        }

        file.close();
    }
};

// Example usage
int main() {
    ClubHub clubHub;

    // Add students
    clubHub.addStudent(1, "Shivaar", "Smith");
    clubHub.addStudent(2, "Jane", "Doe");
    clubHub.addStudent(3, "Bob", "Shivaarson");

    // Create clubs
    clubHub.createClub("Programming Club");
    clubHub.createClub("Chess Club");

    // Add students to clubs
    clubHub.addStudentToClub(1, "Programming Club");
    clubHub.addStudentToClub(2, "Programming Club");
    clubHub.addStudentToClub(2, "Chess Club");
    clubHub.addStudentToClub(3, "Chess Club");

    // Save state
    clubHub.saveToFile("clubhub_data.txt");

    // Find student's clubs
    vector<string> shivsClubs = clubHub.findStudentClubs(1);
    cout << "Shivaar's clubs: ";
    for (const string& club : shivsClubs) {
        cout << club << " ";
    }
    cout << endl;

    // Find club members
    vector<Student> programmingClubMembers = clubHub.findClubMembers("Programming Club");
    cout << "Programming Club members: ";
    for (const Student& student : programmingClubMembers) {
        cout << student.firstName << " " << student.lastName << ", ";
    }
    cout << endl;

    return 0;
}*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

struct Student {
    int id;
    string firstName;
    string lastName;
    vector<string> clubs;
};

struct Club {
    string name;
    vector<int> memberIds;
};

class StudentGraph {
private:
    map<int, list<int>> adjacencyList;

public:
    void addEdge(int student1Id, int student2Id) {
        adjacencyList[student1Id].push_back(student2Id);
        adjacencyList[student2Id].push_back(student1Id);
    }

    void removeEdge(int student1Id, int student2Id) {
        adjacencyList[student1Id].remove(student2Id);
        adjacencyList[student2Id].remove(student1Id);
    }

    vector<int> getConnections(int studentId) {
        vector<int> connections(adjacencyList[studentId].begin(), adjacencyList[studentId].end());
        return connections;
    }
};

class ClubHub {
private:
    vector<Student> students;
    vector<Club> clubs;
    StudentGraph studentConnections;

public:
    void addStudent(int id, string firstName, string lastName) {
        students.push_back({id, firstName, lastName});
    }

    void createClub(string name) {
        clubs.push_back({name});
    }

    Student* findStudent(int studentId) {
        for (auto& student : students) {
            if (student.id == studentId) {
                return &student;
            }
        }
        return nullptr;
    }

    Club* findClub(string clubName) {
        for (auto& club : clubs) {
            if (club.name == clubName) {
                return &club;
            }
        }
        return nullptr;
    }

    void addStudentToClub(int studentId, string clubName) {
        Student* student = findStudent(studentId);
        Club* club = findClub(clubName);

        if (student != nullptr && club != nullptr) {
            student->clubs.push_back(clubName);
            club->memberIds.push_back(studentId);

            for (int memberId : club->memberIds) {
                if (memberId != studentId) {
                    studentConnections.addEdge(studentId, memberId);
                }
            }
        }
    }

    void removeStudentFromClub(int studentId, string clubName) {
        Student* student = findStudent(studentId);
        Club* club = findClub(clubName);

        if (student != nullptr && club != nullptr) {
            for (auto it = student->clubs.begin(); it != student->clubs.end(); ++it) {
                if (*it == clubName) {
                    student->clubs.erase(it);
                    break;
                }
            }

            for (auto it = club->memberIds.begin(); it != club->memberIds.end(); ++it) {
                if (*it == studentId) {
                    club->memberIds.erase(it);
                    break;
                }
            }

            for (int memberId : club->memberIds) {
                studentConnections.removeEdge(studentId, memberId);
            }
        }
    }

    vector<string> findStudentClubs(int studentId) {
        Student* student = findStudent(studentId);
        if (student != nullptr) {
            return student->clubs;
        } else {
            return vector<string>();
        }
    }

    vector<Student> findClubMembers(string clubName) {
        vector<Student> members;
        Club* club = findClub(clubName);

        if (club != nullptr) {
            for (int memberId : club->memberIds) {
                Student* student = findStudent(memberId);
                if (student != nullptr) {
                    members.push_back(*student);
                }
            }
        }
        return members;
    }

    void sortStudentsByLastName() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.lastName < b.lastName;
        });
    }

    void saveToFile(string filename) {
        ofstream file(filename);

        file << "STUDENTS\n";
        for (const Student& student : students) {
            file << student.id << "," << student.firstName << "," << student.lastName << "\n";
        }

        file << "CLUBS\n";
        for (const Club& club : clubs) {
            file << club.name << ":";
            for (int memberId : club.memberIds) {
                file << memberId << ",";
            }
            file << "\n";
        }
        file.close();
    }

    void loadFromFile(string filename) {
        ifstream file(filename);
        string line;
        string section;

        while (getline(file, line)) {
            if (line == "STUDENTS") {
                section = "STUDENTS";
            } else if (line == "CLUBS") {
                section = "CLUBS";
            } else if (section == "STUDENTS") {
                size_t pos1 = line.find(",");
                size_t pos2 = line.find(",", pos1 + 1);
                if (pos1 != string::npos && pos2 != string::npos) {
                    int id = stoi(line.substr(0, pos1));
                    string firstName = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    string lastName = line.substr(pos2 + 1);
                    addStudent(id, firstName, lastName);
                }
            } else if (section == "CLUBS") {
                size_t pos = line.find(":");
                if (pos != string::npos) {
                    string clubName = line.substr(0, pos);
                    createClub(clubName);

                    string members = line.substr(pos + 1);
                    size_t start = 0;
                    size_t end = members.find(",");
                    while (end != string::npos) {
                        int memberId = stoi(members.substr(start, end - start));
                        addStudentToClub(memberId, clubName);
                        start = end + 1;
                        end = members.find(",", start);
                    }
                }
            }
        }
        file.close();
    }
};

int main() {
    ClubHub clubHub;

    int studentCount;
    cout << "Enter the number of students: ";
    cin >> studentCount;

    for (int i = 0; i < studentCount; ++i) {
        int id;
        string firstName, lastName;
        cout << "Enter student ID, first name, and last name (separated by spaces): ";
        cin >> id >> firstName >> lastName;
        clubHub.addStudent(id, firstName, lastName);
    }

    int clubCount;
    cout << "Enter the number of clubs: ";
    cin >> clubCount;

    for (int i = 0; i < clubCount; ++i) {
        string clubName;
        cout << "Enter club name: ";
        cin >> clubName;
        clubHub.createClub(clubName);
    }

    int membershipCount;
    cout << "Enter the number of memberships to assign: ";
    cin >> membershipCount;

    for (int i = 0; i < membershipCount; ++i) {
        int studentId;
        string clubName;
        cout << "Enter student ID and club name to join (separated by space): ";
        cin >> studentId >> clubName;
        clubHub.addStudentToClub(studentId, clubName);
    }

    clubHub.saveToFile("clubhub_data.txt");

    vector<string> shivsClubs = clubHub.findStudentClubs(1);
    cout << "Clubs for student ID 1: ";
    for (const string& club : shivsClubs) {
        cout << club << " ";
    }
    cout << endl;

    for (const auto& club : clubHub.findClubMembers("Chess Club")) {
        cout << "Chess Club member: " << club.firstName << " " << club.lastName << endl;
    }
    for (const auto& club : clubHub.findClubMembers("Soccer Club")) {
        cout << "Soccer Club member: " << club.firstName << " " << club.lastName << endl;
    }
    for (const auto& club : clubHub.findClubMembers("Music Club")) {
        cout << "Music Club member: " << club.firstName << " " << club.lastName << endl;
    }

    return 0;
}
