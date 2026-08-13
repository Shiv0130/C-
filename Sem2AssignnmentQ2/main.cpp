/*#include "bits/stdc++.h"

using namespace std;

class Course {
public:
    string courseCode;
    string courseName;
    string roomType;
    int maxCapacity;
    vector<string> enrolledLearners;
    vector<TimeSlot> timeSlots;
    bool isCoreCourse;

    Course(string code, string name, string rType, int capacity, bool isCore)
        : courseCode(code), courseName(name), roomType(rType),
          maxCapacity(capacity), isCoreCourse(isCore) {}

    // Getters
    //string getCode() { return courseCode; }
    //string getName() { return courseName; }
    //string getLectVenType() { return roomType; }
    //int getCapacity() { return maxCapacity; }
    //int getCurrentEnrollment() { return enrolledLearners.size(); }
    //bool isCoreClass() { return isCoreCourse; }
    //vector<TimeSlot>& getTimeSlots() { return timeSlots; }

    //bool addLearner(string learnerId) {
      //  if (enrolledLearners.size() < maxCapacity) {
          //  enrolledLearners.push_back(learnerId);
           // return true;
        //}
        //return false;
    //}

    //void display() {
      //  cout << "\n Course: " << courseName << " (" << courseCode << ")\n";
       // cout << "LectVen Type: " << roomType << "\n";
       // cout << "Capacity: " << enrolledLearners.size() << "/" << maxCapacity << "\n";
       // cout << "Type: " << (isCoreCourse ? "Core Course" : "Elective") << "\n";
        //cout << "Time Slots:\n";
        //for (const auto& slot : timeSlots) {
          //  cout << "  " << slot.day << " at " << slot.time << "\n";
        //}
    //}
};

class Learner {
public:
    string learnerId;
    string major;
    int academicYear;
    vector<string> enrolledCourses;
    chrono::system_clock::time_point registrationTime;


    Learner(string id, string maj, int year)
        : learnerId(id), major(maj), academicYear(year) {
        registrationTime = chrono::system_clock::now();
    }

    // Getters
  //  string getId() { return learnerId; }
    //string getMajor() { return major; }
    //int getYear() { return academicYear; }
    //auto getRegistrationTime() { return registrationTime; }
    //vector<string>& getCourses() { return enrolledCourses; }

//    void addCourse(string courseCode) {
  //      enrolledCourses.push_back(courseCode);
    //}

    //void display() {
      //  cout << "\n Learner ID: " << learnerId << "\n";
        //cout << "Major: " << major << "\n";
        //cout << "Year: " << academicYear << "\n";
        //cout << "Enrolled Courses:\n";
        //for (const auto& course : enrolledCourses) {
          //  cout << " course: " << course << "\n";
        //}
    //}
};

class LectVen {
public:
    string roomNumber;
    string roomType;
    int capacity;
    vector<TimeSlot> availableSlots;
    map<string, string> equipment;

    LectVen(string number, string type, int cap)
        : roomNumber(number), roomType(type), capacity(cap) {}

    // Getters
    //string getNumber() { return roomNumber; }
    //string getType() { return roomType; }
    //int getCapacity() { return capacity; }

    //void addEquipment(string name, string description) {
      //  equipment[name] = description;
    //}

    //bool isAvailable(const TimeSlot& slot) {
      //  return find(availableSlots.begin(), availableSlots.end(), slot) != availableSlots.end();
    //}

    //void display() {
      //  cout << "\n LectVen " << roomNumber << "\n";
       // cout << "Type: " << roomType << "\n";
        //cout << "Capacity: " << capacity << "\n";
        //cout << "Equipment:\n";
        //for (const auto& [item, desc] : equipment) {
          //  cout << " item: " << item << ": " << desc << "\n";
        //}
    //}
};

// Custom comparator for registration priority
struct RegistrationPriority {
    bool operator()(pair<Learner*, Course*> a, pair<Learner*, Course*> b) {
        // Priority based on academic year (higher year = higher priority)
        if (a.first->getYear() != b.first->getYear())
            return a.first->getYear() < b.first->getYear();

        // Core courses get priority
        if (a.second->isCoreClass() != b.second->isCoreClass())
            return !a.second->isCoreClass();

        // Earlier registration time gets priority
        return a.first->getRegistrationTime() > b.first->getRegistrationTime();
    }
};

class SchedulingSystem {
private:
    vector<unique_ptr<Course>> courses;
    vector<unique_ptr<Learner>> learners;
    vector<unique_ptr<LectVen>> rooms;
    priority_queue<pair<Learner*, Course*>,
                  vector<pair<Learner*, Course*>>,
                  RegistrationPriority> registrationQueue;

    bool checkTimeSlotConflict(const vector<TimeSlot>& slots1, const vector<TimeSlot>& slots2) {
        for (const auto& slot1 : slots1) {
            for (const auto& slot2 : slots2) {
                if (slot1 == slot2) return true;
            }
        }
        return false;
    }

public:
    void addCourse(unique_ptr<Course> course) {
        courses.push_back(move(course));
        cout << "\n Course added successfully!\n";
    }

    void addLearner(unique_ptr<Learner> learner) {
        learners.push_back(move(learner));
        cout << "\n Learner added successfully!\n";
    }

    void addLectVen(unique_ptr<LectVen> room) {
        rooms.push_back(move(room));
        cout << "\n LectVen added successfully!\n";
    }

    void requestRegistration(string learnerId, string courseCode) {
        Learner* learner = nullptr;
        Course* course = nullptr;

        // Find learner and course
        for (auto& s : learners) {
            if (s->getId() == learnerId) learner = s.get();
        }
        for (auto& c : courses) {
            if (c->getCode() == courseCode) course = c.get();
        }

        if (!learner || !course) {
            cout << "\n Invalid learner ID or course code!\n";
            return;
        }

        registrationQueue.push({learner, course});
        cout << "\n Registration request added to queue!\n";
    }

    void processRegistrations() {
        cout << "\n Processing registration requests...\n";

        while (!registrationQueue.empty()) {
            auto [learner, course] = registrationQueue.top();
            registrationQueue.pop();

            // Check course capacity
            if (course->getCurrentEnrollment() >= course->getCapacity()) {
                cout << "Course " << course->getCode() << " is full!\n";
                continue;
            }

            // Check for time conflicts
            bool hasConflict = false;
            for (const auto& enrolledCode : learner->getCourses()) {
                for (const auto& c : courses) {
                    if (c->getCode() == enrolledCode) {
                        if (checkTimeSlotConflict(c->getTimeSlots(), course->getTimeSlots())) {
                            hasConflict = true;
                            break;
                        }
                    }
                }
            }

            if (hasConflict) {
                cout << "Time conflict detected for learner " << learner->getId() << "\n";
                continue;
            }

            // Register learner
            course->addLearner(learner->getId());
            learner->addCourse(course->getCode());
            cout << "Successfully registered " << learner->getId()
                 << " for " << course->getCode() << "\n";
        }
    }

    void displayLearnerSchedule(string learnerId) {
        for (const auto& learner : learners) {
            if (learner->getId() == learnerId) {
                cout << "\n Schedule for Learner " << learnerId << "\n";
                cout << "----------------------------------------\n";
                for (const auto& courseCode : learner->getCourses()) {
                    for (const auto& course : courses) {
                        if (course->getCode() == courseCode) {
                            course->display();
                        }
                    }
                }
                return;
            }
        }
        cout << "\n Learner not found!\n";
    }

    void balanceClassSizes() {
        cout << "\n Balancing class sizes...\n";
        // Implementation of class size balancing algorithm
        for (auto& course : courses) {
            if (course->getCurrentEnrollment() < course->getCapacity() * 0.5) {
                cout << "Low enrollment in " << course->getCode()
                     << " (" << course->getCurrentEnrollment() << " learners)\n";
            }
        }
    }
};

void showMenu() {
    cout << "\n RICHFIELD COURSE SCHEDULING SYSTEM\n";
    cout << "----------------------------------------\n";
    cout << "1. Add new course\n";
    cout << "2. Add new learner\n";
    cout << "3. Add new room\n";
    cout << "4. Request course registration\n";
    cout << "5. Process all registrations\n";
    cout << "6. View learner schedule\n";
    cout << "7. Balance class sizes\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    SchedulingSystem scheduler;
    int choice;

    cout << "\n Welcome to Richfield Course Scheduling System!\n";

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string code, name, type;
                int capacity;
                bool isCore;

                cout << "Enter course code: ";
               //getline(cin, code);
               cin>> code;
                cout << "Enter course name: ";
                //getline(cin, name);
                cin>>name;
                cout << "Enter room type needed: ";
                //getline(cin, type);
                cin>>type;
                cout << "Enter maximum capacity: ";
                cin >> capacity;
                cout << "Is this a core course? (1/0): ";
                cin >> isCore;

                scheduler.addCourse(make_unique<Course>(code, name, type, capacity, isCore));
                break;
            }
            case 2: {
                string id, major;
                int year;

                cout << "Enter learner ID: ";
                //getline(cin, id);
                cin >> id;
                cout << "Enter major: ";
                //getline(cin, major);
                cout << "Enter academic year (1-4): ";
                cin >> year;

                scheduler.addLearner(make_unique<Learner>(id, major, year));
                break;
            }
            case 3: {
                string number, type;
                int capacity;

                cout << "Enter room number: ";
                //getline(cin, number);
                cin>> number;
                cout << "Enter room type: ";
                //getline(cin, type);
                cin >> type;
                cout << "Enter capacity: ";
                cin >> capacity;

                scheduler.addLectVen(make_unique<LectVen>(number, type, capacity));
                break;
            }
            case 4: {
                string learnerId, courseCode;

                cout << "Enter learner ID: ";
                //getline(cin, learnerId);
                cin>>learnerId;
                cout << "Enter course code: ";
                //getline(cin, courseCode);
                cin>>courseCode;

                scheduler.requestRegistration(learnerId, courseCode);
                break;
            }
            case 5:
                scheduler.processRegistrations();
                break;
            case 6: {
                string learnerId;
                cout << "Enter learner ID: ";
                //getline(cin, learnerId);
                cin>>learnerId;
                scheduler.displayLearnerSchedule(learnerId);
                break;
            }
            case 7:
                scheduler.balanceClassSizes();
                break;
            case 0:
                cout << "\nThank you for using Richfield Course Scheduling System! Goodbye!\n";
                break;
            default:
                cout << "\n Invalid option. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}*/


/*#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>
#include "Header.h"
using namespace std;

struct Class {
string day;
string subject;
string instructor;
string time;
string roomNo;
string blockNo;

};

void displayClassDetails(const Class classInfo) {
cout << "Subject:" <<classInfo.subject<<endl;
cout << "Instructor:" <<classInfo.instructor<<endl;
cout << "Time:" <<classInfo.time<<endl;
cout << "LectVen No:" <<classInfo.roomNo<<endl;
cout << "Block No:" <<classInfo.blockNo<<endl;
cout << "Day" <<classInfo.day<<endl;
}

void displayScheduleForDay() {
bool condition1 = false;
do { string day;
     while(cin.get()!='\n'){
        continue;
     }
     getline(cin,day);
     if(day == "Monday" || day == "Mon", day == "MON" || day == "MONDAY"){
        condition1 = true;
        cout << "Here is the class schedule for " << day << ":" << endl;
        cout <<"***************************************"<<endl;
        cout << "Your first Class details are as follows:" <<endl;
        displayClassDetails({"Electronic Devices and Circuits", "Umair Ayaz Kamangar,"})<<endl;
        cout << "Namaz break : 01:30 To 02:00"<<endl;
        bool condition2 = false;
        do {
            cout << "Enter the group (e.g.,x,y):" <<endl;
            char group;
            cin>> group;
            switch(group) {
        case :'X':
            condition2 = true;
            cout<< "Your second Class details are as follows:"<<endl;
            displayClassDetails({day, "Computer Programming Lab", "Muhammed Irfan Younis"})
            break;

        case :'x':
            condition2 = true;
            cout<< "Your second Class details are as follows:"<<endl;
            displayClassDetails({day, "Computer Programming Lab", "Muhammed Irfan Younis"})
            break;

        case :'Y':
            condition2 = true;
            cout<< "Your second Class details are as follows:"<<endl;
            displayClassDetails({day, "Circuit Analysis Lab", "Engr. Irfan Ali Babar"})
            break;

 case :'y':
            condition2 = true;
            cout<< "Your second Class details are as follows:"<<endl;
            displayClassDetails({day, "Circuit Analysis Lab", "Engr. Irfan Ali Babar"})
            break;
 default:
    cout << "Invalid group choice! Try Again" <<endl;
    condition2 = false;
    break;
            }
        }while(!condition2);
     }else if (day == "Tuesday" || day == "Tue" || day == "TUESDAY"){
     condition1 = true;
     cout << "Here is the class schedule for" <<day<<":"<<endl;
     cout << "************************************" <<endl;
     cout<< "Your first Class details are as follows:" << endl;
     displayClassDetails({day, "Electronic Devices and Circuits","Umair Ayaz Kaman"})<<endl;
     cout << "Namaz break :01:30 To 02:00" <<endl;
     cout << "Your Second Class details are as follows:" <<endl;
     displayClassDetails({day,"Circuit analysis" , "Engr. Irfan Ali Babar","04:10"})<<endl;



     else if(day == "Wednsday" || day = "Wed" || day == "WED" || day == "WEDNESDAY") {
    condition1 = true;
     cout << "Here is the class schedule for" <<day<<":"<<endl;
     cout << "************************************" <<endl;
     cout<< "Your first Class details are as follows:" << endl;
     displayClassDetails({day, "Linear Algebra","Irfan Younis", "09:00 To 11:00"})<<endl;
     cout << "Refreshment break :11:00 To 11:30" <<endl;
     cout << "Your Second Class details are as follows:" <<endl;
     displayClassDetails({day,"Computer Programming" , "Irfan Younis","02:00:02:30"})<<endl;


     }

     else if(day == "Thursday" || day = "Thu" || day == "THU" || day == "THURSDAY") {
    condition1 = true;
     cout << "Here is the class schedule for" <<day<<":"<<endl;
     cout << "************************************" <<endl;
     cout<< "Your first Class details are as follows:" << endl;
     displayClassDetails({day, "Communication Skills","Asifa Abbas", "11:30 To 01:30"})<<endl;
     cout << "Namaz break :01:30 To 02:00" <<endl;
     bool condition = false;

     do {
        cout<< "Enter the group (e.g.,X, Y): "<<endl;
        char group:
            cin>>group;
            switch(group) {
        case :'X':
            condition = true;
            cout<< "Your second Class details are as follows:"<<endl;
            displayClassDetails({day, "Electronic Devices and Circuits", "Umair Ayaz Kamang"})
            break;

        case :'x':
            condition = true;
            cout<< "Your second Class details are as follows:"<<endl;
            displayClassDetails({day, "Electronic Devices and Circuits", "Umair Ayaz Kamang"})
            break;

        case :'Y':
            condition = true;
            cout<< "Your second Class details are as follows:"<<endl;
            displayClassDetails({day, "Computer Programming Lab", "Muhammad Irfan Younis"});
            break;

 case :'y':
            condition = true;
            cout<< "Your second Class details are as follows:"<<endl;
            displayClassDetails({day, "Computer Programming Lab", "Muhammad Irfan Younis"})
            break;
 default:
    cout << "Invalid group choice! Try Again" <<endl;
    condition = false;
    break;
            }
        }while(!condition);


     }


     }

}
}

else if(day == "Friday" || day = "Fri" || day == "FRI" || day == "FRIDAY") {
    condition1 = true;
     cout << "Here is the class schedule for" <<day<<":"<<endl;
     cout << "************************************" <<endl;
     cout<< "Your first Class details are as follows:" << endl;
     displayClassDetails({day, "Linar Algebra","Muhammad Irfan Younis Mughal", "09:00 To 12:00"})<<endl;
     cout << "Refreshment break :11:00 To 11:30" <<endl;
     displayClassDetails({day, "Communication Skills","Asifa Abbas","11:30 To 01:30"})<<endl;
     cout<< "Namaz break  :01:30 To 02:00"<<endl;
     bool condition = false;

     do {
        cout<< "Enter the group (e.g.,X, Y): "<<endl;
        char group:
            cin>>group;
            switch(group) {
        case :'X':
            condition = true;
            cout<< "Your second Class details are as follows:"<<endl;
            displayClassDetails({day, "Electronic Devices and Circuits", "Umair Ayaz Kamang"})
            break;

        case :'x':
            condition = true;
            cout<< "Your second Class details are as follows:"<<endl;
            displayClassDetails({day, "Electronic Devices and Circuits", "Umair Ayaz Kamang"})
            break;

        case :'Y':
            condition = true;
            cout<< "Your second Class details are as follows:"<<endl;
            displayClassDetails({day, "Computer Programming Lab", "Muhammad Irfan Younis"});
            break;

 case :'y':
            condition = true;
            cout<< "Your second Class details are as follows:"<<endl;
            displayClassDetails({day, "Computer Programming Lab", "Muhammad Irfan Younis"})
            break;
 default:
    cout << "Invalid group choice! Try Again" <<endl;
    condition = false;
    break;
            }
        }while(!condition);


     }


     }
void displayScheduleForInstructor() {
string instructor;
cin.ignore();
cout<< "Enter the instructor's name: ";
getline(cin,instructor);
char name[256];
for(size_t i = 0; i<instructor.length();i++){
    name[i] = instructor[i];
}
name[instructor.length()] = '\0';
strupr(name);
bool wrongname = false;

while(!wrongname){
    cout<< "Here is the class schedule for Instructor:"<<name<<endl;
    cout << "******************************************************"<<endl;

    if( strcmp(name , "UMAIR AYAZ")==0 || strcmp(name, "SIR UMAIR")==0 || strcmp(nam,"UA")){
        wrongname=true;
        displayClassDetails({"Monday","Electronic Devices and Circuits","Umair Ayaz"})
        displayClassDetails({"Tuesday","Electronic Devices and Circuits","Umair Ayaz"})
        cout<< "Lab for X Group"<<endl;
        displayClassDetails({"Thursday","Electronic Devices and Circuits Lab","Umair Ayaz"})
        cout<< "Lab for Y Group"<<endl;
        displayClassDetails({"Friday","Electronic Devices and Circuits Lab","Umair Ayaz"})
    }else if(strcmp(name,"SIR IRFAN YOUNIZ")==0 || strcmp(name,"SIR IRFAN")==0){
    wrongname = true;
    cout<< "Lab for X Group"<<endl;
    displayClassDetails("Monday" , "Computer Programming Lab","Muhammad Irfan Younis");
    displayClassDetails("Wednesday" , "Linear Algebra","Muhammad Irfan Younis Mughal");
    displayClassDetails("Wednesday" , "Computer Programming Lab","Muhammad Irfan Younis");
    cout<< "Lab for Y Group"<<endl;
    displayClassDetails("Monday" , "Circuit Analysis Lab","Engr. Irfan Ali Babar");
    displayClassDetails("Tuesday" , "Circuit Analysis Lab","Engr. Ali Babar");
    displayClassDetails("Wednesday" , "Circuit Analysis Lab","Engr. Ali Babar");
    cout<< "Lab for X Group"<<endl;
    displayClassDetails("Friday" , "Communication Skills","Asifa Abbas");
    } else if(strcmp(name, "SIR PEERL KHAN")==0|| strcmp("SIR PEERAL")==0) {
    wrongname = true;
    displayClassDetails("Thursday" , "Communication Skills","Asifa Abbas");
    displayClassDetails("Friday" , "Communication Skills","Asifa Abbas");
    } else {
    cout << "No class schedule for Instructor:"<<name<<endl;
    cout << "Try Again" <<endl;
                  displayScheduleForInstructor();

    }
}
}
void displayScheduleForSubject() {
cout << "Enter the subject:";
string subject;
while(cin.get()!='\n'){
    continue;
}
getline(cin,subject);
cout << "Here is the class schedule for Subject:"<<subject<<endl;
cout<< "*************************************************";
bool check = false;
while(!check){
    if(subject == "Electronic Devices and Circuits" || subject "EDC" || subject == "edc") {
        check = true;
        displayClassDetails("Monday" , "Computer Programming Lab","Muhammad Irfan Younis");
        displayClassDetails("Tuesday" , "Circuit Analysis Lab","Engr. Ali Babar");
        cout << "Lab for X Group" <<endl;
        displayClassDetails("Thursday" , "Electronic Devices and Circuits Lab","Umai");
        cout << "Lab for Y Group"<<endl;
        displayClassDetails("Friday" , "Electronic Devices and Circuits Lab","Umair");
        break;
    } else if(subject == "Computer Programming" || subject == "CP" || subject = "cp"){
    check =  true;
    cout<< "Lab for X Group";
    displayClassDetails("Monday" , "Computer Programming Lab","Muhammad Irfan Younis");
    displayClassDetails("Wednesday" , "Computer Programming Lab","Muhammad Irfan Younis");
    cout << "Lab for Y Group";
    displayClassDetails("Thursday" , "Computer Programming Lab","Muhammad Irfan Younis");
    else if (subject == "Circuit Analysis" || subject = "CA" || subject = "ca") {
        cout << "Lab for Y Group";
        check = true;
        displayClassDetails("Monday" , "Circuit  Analysis Lab","Engr.Irfan Ali Babar");
        displayClassDetails("Tuesday" , "Circuit Analysis Lab","Engr.Irfan Ali Babar");
        displayClassDetails("Wednesday" , "Circuit Analysis Lab","Engr.Irfan Ali Babar");
        cout << "Lab for Grou X" <<endl;
        displayClassDetails("Friday" , "Circuit Analysis Lab","Engr.Irfan Ali Babar");

    } else if( subject == "Islmaic Studies" || subject = "IS" subject = "is") {
    check = true;
    displayClassDetails("Tuesday" , "Islmaic Studies ","Peeral Khan");
    check true;
    displayClassDetails("Thursday" , "Communication Skills","Asifa Abbas");
    displayClassDetails("Friday" , "Communication Skills","Asifa Abbas");

    }else if(subject == "Linear Algebra" || subject == "LA", subject == "la" ) {
    check = true;
    displayClassDetails("Wednesday" , "Linear Algebra","Muhammed Irfan Younis Mughal");
    displayClassDetails("Friday" , "Linear Algebra","Muhammed Irfan Younis Mughal");
    } else {
    check = false;
    cout<< "Invalid Subject name Try Again"<<endl;
    displayScheduleForSubject()
    }


    }
}
}


int main()
{
    project_info();
    cout << "Do you want To get guidelines about how to use the project" <<endl;
    cout << "\n";
    cout << "Enter Y for Yes" <<endl;
    cout << "Entr N for No"<<endl;

    char option;
    bool test = false;

    do{
        if(cin>>option){
            switch(option) {
        case 'Y' :
            test = true;
            cout << "  "<<endl;
            project_Tutorial();
            break;

        case 'y' :
            test = true;
            cout << "***__Guidelines to use Project___***  "<<endl;
            project_Tutorial();
            break;

        case 'N' :
            test = true;
            cout << "Start at your own risk"<<endl;
            break;

            case 'n' :
            test = true;
            cout << "Start at your own risk "<<endl;
            break;

            default:
                test = false;
                cout<< "Invalid choice! Try Again" <<endl;
                break;

            }
        }
        else{
            cout<< "Invalid input! Try Again"<<endl;
        }
    }
    while(!test)

        cout <<"Please select and option:"<<endl;
        cout << "1. Display class schedule for a specific day";
        cout << "2. Display class schedule for a specific instructor";
        cout << "3. Display class schedule for a specific subject";

    int choice;
    bool condtion = false;

    do{
        if(cin>>choice){
            switch (choice) {
            case 1: {
            condition = true;
            cout << "Enter the day (e.g.,Monday,Tuesday):";
            displayScheduleForDay();
            break;
            }

             case 2: {
            condition = true;
            displayScheduleForInstructor();
            break;
            }

             case 3: {
            condition = true;
            displayScheduleForSubject();
            break;
            }
             default:
                cout<<"Invalid choice! Try Again" <<endl;
                condition = false;
                break;
            }
        }
        else{
         cout<< "Invalid input! Try Again"<<endl;

        }
    } while(!condition);


return  0;
}*/

/*#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>
using namespace std;

struct Class {
    string day;
    string subject;
    string instructor;
    string time;
    string roomNo;
    string blockNo;
};

void displayClassDetails(const Class& classInfo) {
    cout << "Subject: " << classInfo.subject << endl;
    cout << "Instructor: " << classInfo.instructor << endl;
    cout << "Time: " << classInfo.time << endl;
    cout << "LectVen No: " << classInfo.roomNo << endl;
    cout << "Block No: " << classInfo.blockNo << endl;
    cout << "Day: " << classInfo.day << endl;
}

void displayScheduleForDay() {
    bool condition1 = false;
    do {
        string day;
        cout << "Enter the day (e.g., Monday, Tuesday): ";
        getline(cin, day);

        if (day == "Monday" || day == "Mon" || day == "MON" || day == "MONDAY") {
            condition1 = true;
            cout << "Here is the class schedule for " << day << ":" << endl;
            cout << "***************************************" << endl;
            cout << "Your first Class details are as follows:" << endl;
            displayClassDetails({"Monday", "Electronic Devices and Circuits", "Umair Ayaz Kamangar", "09:00 to 11:00", "LectVen 1", "Block A"});
            cout << "Namaz break: 01:30 To 02:00" << endl;

            bool condition2 = false;
            do {
                cout << "Enter the group (e.g., X, Y): ";
                char group;
                cin >> group;
                group = toupper(group);  // To handle case insensitivity

                switch (group) {
                    case 'X':
                        condition2 = true;
                        cout << "Your second Class details are as follows:" << endl;
                        displayClassDetails({"Monday", "Computer Programming Lab", "Muhammad Irfan Younis", "02:00 to 04:00", "LectVen 2", "Block B"});
                        break;
                    case 'Y':
                        condition2 = true;
                        cout << "Your second Class details are as follows:" << endl;
                        displayClassDetails({"Monday", "Circuit Analysis Lab", "Engr. Irfan Ali Babar", "02:00 to 04:00", "LectVen 3", "Block C"});
                        break;
                    default:
                        cout << "Invalid group choice! Try Again" << endl;
                        condition2 = false;
                        break;
                }
            } while (!condition2);
        } else if (day == "Tuesday" || day == "Tue" || day == "TUESDAY") {
            condition1 = true;
            cout << "Here is the class schedule for " << day << ":" << endl;
            cout << "***************************************" << endl;
            cout << "Your first Class details are as follows:" << endl;
            displayClassDetails({"Tuesday", "Electronic Devices and Circuits", "Umair Ayaz Kaman", "09:00 to 11:00", "LectVen 1", "Block A"});
            cout << "Namaz break: 01:30 To 02:00" << endl;
            cout << "Your Second Class details are as follows:" << endl;
            displayClassDetails({"Tuesday", "Circuit Analysis", "Engr. Irfan Ali Babar", "04:10 to 06:00", "LectVen 4", "Block D"});
        }
        // Additional days can be handled similarly
        else {
            cout << "Invalid day! Try Again" << endl;
        }
    } while (!condition1);
}

void displayScheduleForInstructor() {
    string instructor;
    cout << "Enter the instructor's name: ";
    getline(cin, instructor);

    for (auto& c : instructor) c = toupper(c);  // Convert input to uppercase

    if (instructor == "UMAIR AYAZ" || instructor == "SIR UMAIR") {
        cout << "Here is the class schedule for Instructor: " << instructor << endl;
        cout << "******************************************************" << endl;
        displayClassDetails({"Monday", "Electronic Devices and Circuits", "Umair Ayaz", "09:00 to 11:00", "LectVen 1", "Block A"});
        displayClassDetails({"Tuesday", "Electronic Devices and Circuits", "Umair Ayaz", "09:00 to 11:00", "LectVen 1", "Block A"});
        displayClassDetails({"Thursday", "Electronic Devices and Circuits Lab (Group X)", "Umair Ayaz", "02:00 to 04:00", "LectVen 2", "Block B"});
        displayClassDetails({"Friday", "Electronic Devices and Circuits Lab (Group Y)", "Umair Ayaz", "02:00 to 04:00", "LectVen 2", "Block B"});
    } else {
        cout << "No class schedule for Instructor: " << instructor << endl;
    }
}

void displayScheduleForSubject() {
    string subject;
    cout << "Enter the subject: ";
    getline(cin, subject);

    for (auto& c : subject) c = toupper(c);  // Convert input to uppercase

    if (subject == "ELECTRONIC DEVICES AND CIRCUITS" || subject == "EDC") {
        cout << "Here is the class schedule for Subject: " << subject << endl;
        cout << "******************************************************" << endl;
        displayClassDetails({"Monday", "Electronic Devices and Circuits", "Umair Ayaz", "09:00 to 11:00", "LectVen 1", "Block A"});
        displayClassDetails({"Tuesday", "Circuit Analysis", "Engr. Ali Babar", "04:10 to 06:00", "LectVen 4", "Block D"});
        displayClassDetails({"Thursday", "Electronic Devices and Circuits Lab (Group X)", "Umair Ayaz", "02:00 to 04:00", "LectVen 2", "Block B"});
        displayClassDetails({"Friday", "Electronic Devices and Circuits Lab (Group Y)", "Umair Ayaz", "02:00 to 04:00", "LectVen 2", "Block B"});
    } else {
        cout << "Invalid Subject! Try Again" << endl;
    }
}

void project_info() {
    cout << "Welcome to the Class Scheduling System" << endl;
}

void project_Tutorial() {
    cout << "This project helps you view class schedules by day, instructor, or subject." << endl;
}

int main() {
    project_info();
    cout << "Do you want To get guidelines about how to use the project? (Y/N): ";

    char option;
    bool test = false;

    do {
        cin >> option;
        option = toupper(option);  // Convert to uppercase for consistent handling

        switch (option) {
            case 'Y':
                test = true;
                project_Tutorial();
                break;
            case 'N':
                test = true;
                cout << "Start at your own risk." << endl;
                break;
            default:
                cout << "Invalid choice! Try Again" << endl;
                break;
        }
    } while (!test);

    cout << "Please select an option:" << endl;
    cout << "1. Display class schedule for a specific day" << endl;
    cout << "2. Display class schedule for a specific instructor" << endl;
    cout << "3. Display class schedule for a specific subject" << endl;

    int choice;
    bool condition = false;

    do {
        cin >> choice;
        cin.ignore();  // To clear newline character from input buffer

        switch (choice) {
            case 1:
                condition = true;
                displayScheduleForDay();
                break;
            case 2:
                condition = true;
                displayScheduleForInstructor();
                break;
            case 3:
                condition = true;
                displayScheduleForSubject();
                break;
            default:
                cout << "Invalid choice! Try Again" << endl;
                break;
        }
    } while (!condition);

    return 0;
}*/

/*#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;

class Course;
class Learner;
class LectVen;

struct RegistrationRequest {
    Learner* learner;
    Course* course;
    time_t timestamp;

    bool operator<(const RegistrationRequest& other) const;
};

class Course {
private:
    string courseCode;
    string name;
    string requiredLectVenType;
    int maxCapacity;
    vector<Learner*> enrolledLearners;
    vector<pair<string, string>> timeSlots;

public:
    Course(string code, string courseName, string roomType, int capacity)
        : courseCode(code), name(courseName), requiredLectVenType(roomType), maxCapacity(capacity) {}

    string getCode() const { return courseCode; }
    string getName() const { return name; }
    string getLectVenType() const { return requiredLectVenType; }
    int getMaxCapacity() const { return maxCapacity; }
    int getCurrentEnrollment() const { return enrolledLearners.size(); }

    bool addLearner(Learner* learner) {
        if (enrolledLearners.size() < maxCapacity) {
            enrolledLearners.push_back(learner);
            return true;
        }
        return false;
    }

    void addTimeSlot(string day, string time) {
        timeSlots.push_back({day, time});
    }

    bool hasTimeConflict(const Course* other) const {
        for (const auto& slot1 : timeSlots) {
            for (const auto& slot2 : other->timeSlots) {
                if (slot1 == slot2) return true;
            }
        }
        return false;
    }
};

class Learner {
private:
    string learnerID;
    string major;
    int academicYear;
    vector<Course*> enrolledCourses;

public:
    Learner(string id, string learnerMajor, int year)
        : learnerID(id), major(learnerMajor), academicYear(year) {}

    string getID() const { return learnerID; }
    string getMajor() const { return major; }
    int getAcademicYear() const { return academicYear; }

    bool enrollInCourse(Course* course) {
        for (const auto& enrolled : enrolledCourses) {
            if (enrolled->hasTimeConflict(course)) return false;
        }

        if (course->addLearner(this)) {
            enrolledCourses.push_back(course);
            return true;
        }
        return false;
    }

    const vector<Course*>& getSchedule() const {
        return enrolledCourses;
    }
};

class LectVen {
private:
    string roomNumber;
    string type;
    int capacity;
    vector<pair<string, string>> bookedTimeSlots;
    map<string, bool> equipment;

public:
    LectVen(string number, string roomType, int roomCapacity)
        : roomNumber(number), type(roomType), capacity(roomCapacity) {}

    bool isAvailable(string day, string time) const {
        return find(bookedTimeSlots.begin(), bookedTimeSlots.end(),
                   make_pair(day, time)) == bookedTimeSlots.end();
    }

    bool bookTimeSlot(string day, string time) {
        if (isAvailable(day, time)) {
            bookedTimeSlots.push_back({day, time});
            return true;
        }
        return false;
    }

    string getType() const { return type; }
    int getCapacity() const { return capacity; }
    string getNumber() const { return roomNumber; }
};

bool RegistrationRequest::operator<(const RegistrationRequest& other) const {

    if (learner->getAcademicYear() != other.learner->getAcademicYear())
        return learner->getAcademicYear() < other.learner->getAcademicYear();

    bool thisIsCore = (course->getCode().substr(0, 4) == learner->getMajor());
    bool otherIsCore = (other.course->getCode().substr(0, 4) == other.learner->getMajor());
    if (thisIsCore != otherIsCore)
        return !thisIsCore;

    return timestamp > other.timestamp;
}

class SchedulingSystem {
private:
    vector<Course*> courses;
    vector<Learner*> learners;
    vector<LectVen*> rooms;
    priority_queue<RegistrationRequest> registrationQueue;

public:
    void addCourse(Course* course) { courses.push_back(course); }
    void addLearner(Learner* learner) { learners.push_back(learner); }
    void addLectVen(LectVen* room) { rooms.push_back(room); }

    void addRegistrationRequest(Learner* learner, Course* course) {
        RegistrationRequest request{learner, course, time(nullptr)};
        registrationQueue.push(request);
    }

    void processRegistrations() {
        while (!registrationQueue.empty()) {
            auto request = registrationQueue.top();
            registrationQueue.pop();

            LectVen* selectedLectVen = nullptr;
            for (auto room : rooms) {
                if (room->getType() == request.course->getLectVenType() &&
                    room->getCapacity() >= request.course->getMaxCapacity()) {
                    selectedLectVen = room;
                    break;
                }
            }

            if (selectedLectVen && request.learner->enrollInCourse(request.course)) {
                cout << "Successfully enrolled " << request.learner->getID()
                     << " in " << request.course->getCode() << endl;
            } else {
                cout << "Failed to enroll " << request.learner->getID()
                     << " in " << request.course->getCode() << endl;
            }
        }
    }

    void generateLearnerSchedule(Learner* learner) {
        cout << "\nSchedule for learner " << learner->getID() << ":\n";
        for (const auto& course : learner->getSchedule()) {
            cout << course->getCode() << " - " << course->getName() << endl;
        }
    }

    ~SchedulingSystem() {
        for (auto course : courses) delete course;
        for (auto learner : learners) delete learner;
        for (auto room : rooms) delete room;
    }
};

int main() {

    SchedulingSystem system;

    Course* pro = new Course("PRO622", "C++ Programming", "Computer Lab ", 30);
    Learner* learner = new Learner("402308001", "COMP", 3);
    LectVen* room = new LectVen("Lab1", "Computer Lab", 30);

    pro->addTimeSlot("Monday", "09:00");
    system.addCourse(pro);
    system.addLearner(learner);
    system.addLectVen(room);

    system.addRegistrationRequest(learner, pro);
    system.processRegistrations();
    system.generateLearnerSchedule(learner);

    return 0;
}*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;

class Course;
class Learner;
class LectVen;

struct RegistrationRequest {
    Learner* learner;
    Course* course;
    time_t timestamp;

    bool operator<(const RegistrationRequest& other) const;
};

class Course {
private:
    string courseCode;
    string name;
    string requiredLectVenType;
    int maxCapacity;
    vector<Learner*> enrolledLearners;
    vector<pair<string, string>> timeSlots;

public:
    Course(string code, string courseName, string roomType, int capacity)
        : courseCode(code), name(courseName), requiredLectVenType(roomType), maxCapacity(capacity) {}

    string getCode() const { return courseCode; }
    string getName() const { return name; }
    string getLectVenType() const { return requiredLectVenType; }
    int getMaxCapacity() const { return maxCapacity; }
    int getCurrentEnrollment() const { return enrolledLearners.size(); }

    bool addLearner(Learner* learner) {
        if (enrolledLearners.size() < maxCapacity) {
            enrolledLearners.push_back(learner);
            return true;
        }
        return false;
    }

    void addTimeSlot(string day, string time) {
        timeSlots.push_back({day, time});
    }

    bool hasTimeConflict(const Course* other) const {
        for (const auto& slot1 : timeSlots) {
            for (const auto& slot2 : other->timeSlots) {
                if (slot1 == slot2) return true;
            }
        }
        return false;
    }
};

class Learner {
private:
    string learnerID;
    string major;
    int academicYear;
    vector<Course*> enrolledCourses;

public:
    Learner(string id, string learnerMajor, int year)
        : learnerID(id), major(learnerMajor), academicYear(year) {}

    string getID() const { return learnerID; }
    string getMajor() const { return major; }
    int getAcademicYear() const { return academicYear; }

    bool enrollInCourse(Course* course) {
        for (const auto& enrolled : enrolledCourses) {
            if (enrolled->hasTimeConflict(course)) return false;
        }

        if (course->addLearner(this)) {
            enrolledCourses.push_back(course);
            return true;
        }
        return false;
    }

    const vector<Course*>& getSchedule() const {
        return enrolledCourses;
    }
};

class LectVen {
private:
    string roomNumber;
    string type;
    int capacity;
    vector<pair<string, string>> bookedTimeSlots;
    map<string, bool> equipment;

public:
    LectVen(string number, string roomType, int roomCapacity)
        : roomNumber(number), type(roomType), capacity(roomCapacity) {}

    bool isAvailable(string day, string time) const {
        return find(bookedTimeSlots.begin(), bookedTimeSlots.end(),
                   make_pair(day, time)) == bookedTimeSlots.end();
    }

    bool bookTimeSlot(string day, string time) {
        if (isAvailable(day, time)) {
            bookedTimeSlots.push_back({day, time});
            return true;
        }
        return false;
    }

    string getType() const { return type; }
    int getCapacity() const { return capacity; }
    string getNumber() const { return roomNumber; }
};

bool RegistrationRequest::operator<(const RegistrationRequest& other) const {
    if (learner->getAcademicYear() != other.learner->getAcademicYear())
        return learner->getAcademicYear() < other.learner->getAcademicYear();

    bool thisIsCore = (course->getCode().substr(0, 4) == learner->getMajor());
    bool otherIsCore = (other.course->getCode().substr(0, 4) == other.learner->getMajor());
    if (thisIsCore != otherIsCore)
        return !thisIsCore;

    return timestamp > other.timestamp;
}

class SchedulingSystem {
private:
    vector<Course*> courses;
    vector<Learner*> learners;
    vector<LectVen*> rooms;
    priority_queue<RegistrationRequest> registrationQueue;

public:
    void addCourse(Course* course) { courses.push_back(course); }
    void addLearner(Learner* learner) { learners.push_back(learner); }
    void addLectVen(LectVen* room) { rooms.push_back(room); }

    void addRegistrationRequest(Learner* learner, Course* course) {
        RegistrationRequest request{learner, course, time(nullptr)};
        registrationQueue.push(request);
    }

    void processRegistrations() {
        cout << "--- Processing Registration Requests ---\n";
        while (!registrationQueue.empty()) {
            auto request = registrationQueue.top();
            registrationQueue.pop();
            cout << "Registered " << request.learner->getID() << " for " << request.course->getName() << endl;
        }
        cout << "--- Registration Requests Processed ---\n";
    }

    void assignLectVens() {
        cout << "\n--- Assigning LectVens to Courses ---\n";
        for (auto course : courses) {
            LectVen* selectedLectVen = nullptr;
            for (auto room : rooms) {
                if (room->getType() == course->getLectVenType() &&
                    room->getCapacity() >= course->getMaxCapacity()) {
                    selectedLectVen = room;
                    break;
                }
            }
            if (selectedLectVen) {
                cout << "Assigned " << course->getName() << " to room " << selectedLectVen->getNumber()
                     << " at 10:15 AM - 11:15 AM\n";
            }
        }
        cout << "--- LectVen Assignments Completed ---\n";
    }

    void generateLectVenSchedules() {
        cout << "\n--- Generating Schedules ---\n";
        for (auto room : rooms) {
            cout << "Schedule for room " << room->getNumber() << " includes:\n";
            bool roomOccupied = false;
            for (auto course : courses) {
                if (room->getType() == course->getLectVenType() &&
                    room->getCapacity() >= course->getMaxCapacity()) {
                    cout << "- " << course->getName() << " at 10:15 AM - 11:15 AM with "
                         << course->getCurrentEnrollment() << " learners\n";
                    roomOccupied = true;
                    break;
                }
            }
            if (!roomOccupied) {
                cout << "No courses scheduled.\n";
            }
        }
        cout << "--- Schedules Generated ---\n";
    }

    ~SchedulingSystem() {
        for (auto course : courses) delete course;
        for (auto learner : learners) delete learner;
        for (auto room : rooms) delete room;
    }
};

int main() {
    SchedulingSystem system;


    Course* Programming = new Course("402308001", "Programming", "Computer Lab", 1);
    Course* MCOM = new Course("402308003", "MCOM", "Lab", 30);
    Course* INS = new Course("402308002", "Information Systems", "Computer Lab", 20);

    Learner* learner1 = new Learner("402308001", "COMP", 3);
    Learner* learner2 = new Learner("402308002", "Business", 2);
    Learner* learner3 = new Learner("402308003", "COMP", 1);

    LectVen* lectven1 = new LectVen("LV 1", "LectVen", 50);
    LectVen* lectven2 = new LectVen("LV 2", "LectVen", 1);
    LectVen* lab1 = new LectVen("Lab 1", "Lab", 30);
    LectVen* lab2 = new LectVen("Lab 2", "Lab", 30);


    system.addCourse(Programming);
    system.addCourse(MCOM);
    system.addCourse(INS);

    system.addLearner(learner1);
    system.addLearner(learner2);
    system.addLearner(learner3);

    system.addLectVen(lectven1);
    system.addLectVen(lectven2);
    system.addLectVen(lab1);
    system.addLectVen(lab2);


    system.addRegistrationRequest(learner1, Programming);
    system.addRegistrationRequest(learner2, INS);
    system.addRegistrationRequest(learner3, MCOM);


    system.processRegistrations();
    system.assignLectVens();
    system.generateLectVenSchedules();

    return 0;
}



