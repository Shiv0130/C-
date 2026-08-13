/*#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}*/

/*#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile || !outFile) {
        cerr << "Unable to open file";
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        outFile << "Processed: " << line << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}*/


/*#include <iostream>

using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Option 1\n";
        cout << "2. Option 2\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "You chose Option 1\n";
        } else if (choice == 2) {
            cout << "You chose Option 2\n";
        } else if (choice == 3) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    int age;
    string course;

public:
    Student(int r, string n, int a, string c) : rollNumber(r), name(n), age(a), course(c) {}

    int getRollNumber() {
        return rollNumber;
    }

    void display() {
        cout << "Roll Number: " << rollNumber << "\nName: " << name << "\nAge: " << age << "\nCourse: " << course << endl;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent(int rollNumber, string name, int age, string course) {
        Student newStudent(rollNumber, name, age, course);
        students.push_back(newStudent);
    }

    void displayAllStudents() {
        for (Student student : students) {
            student.display();
            cout << "------------------------" << endl;
        }
    }

    void searchStudentByRollNumber(int rollNumber) {
        for (Student student : students) {
            if (student.getRollNumber() == rollNumber) {
                student.display();
                return;
            }
        }
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }
};

int main() {
    StudentManagementSystem sms;

    sms.addStudent(1, "Alice", 20, "Computer Science");
    sms.addStudent(2, "Bob", 21, "Mechanical Engineering");

    cout << "Displaying all students:" << endl;
    sms.displayAllStudents();

    cout << "Searching for student with roll number 2:" << endl;
    sms.searchStudentByRollNumber(2);

    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    bool isAvailable;

public:
    Book(int id, string t, string a) : bookID(id), title(t), author(a), isAvailable(true) {}

    int getBookID() {
        return bookID;
    }

    bool getAvailability() {
        return isAvailable;
    }

    void issueBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book issued successfully." << endl;
        } else {
            cout << "Book is already issued." << endl;
        }
    }

    void returnBook() {
        isAvailable = true;
        cout << "Book returned successfully." << endl;
    }

    void display() {
        cout << "Book ID: " << bookID << "\nTitle: " << title << "\nAuthor: " << author << "\nAvailability: " << (isAvailable ? "Available" : "Issued") << endl;
    }
};*/

/*class Library {
private:
    vector<Book> books;

public:
    void addBook(int bookID, string title, string author) {
        Book newBook(bookID, title, author);
        books.push_back(newBook);
    }

    void issueBook(int bookID) {
        for (Book &book : books) {
            if (book.getBookID() == bookID) {
                book.issueBook();
                return;
            }
        }
        cout << "Book with ID " << bookID << " not found." << endl;
    }

    void returnBook(int bookID) {
        for (Book &book : books) {
            if (book.getBookID() == bookID) {
                book.returnBook();
                return;
            }
        }
        cout << "Book with ID " << bookID << " not found." << endl;
    }

    void displayAllBooks() {
        for (Book &book : books) {
            book.display();
            cout << "------------------------" << endl;
        }
    }
};

int main() {
    Library library;

    library.addBook(1, "1984", "George Orwell");
    library.addBook(2, "To Kill a Mockingbird", "Harper Lee");

    cout << "Displaying all books:" << endl;
    library.displayAllBooks();

    cout << "Issuing book with ID 1:" << endl;
    library.issueBook(1);
    library.displayAllBooks();

    cout << "Returning book with ID 1:" << endl;
    library.returnBook(1);
    library.displayAllBooks();

    return 0;
}*/




