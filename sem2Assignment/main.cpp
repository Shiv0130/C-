/*#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;
// Base Resource class (abstract)
class Resource {
protected:
    string Title;
    string Author;
    string ISBN;
public:
    Resource(const string& t, const string& a, const string& i)
        : Title(t), Author(a), ISBN(i) {}

    virtual ~Resource() = default;

    virtual string getType() const = 0;

    // Getters
    string getTitle() const { return Title; }
    string getAuthor() const { return Author; }
    string getISBN() const { return ISBN; }

    virtual void display() const = 0;
};

// Derived classes for specific resource types
class Book : public Resource {
public:
    Book(const string& t, const string& a, const string& i)
        : Resource(t, a, i) {}

    string getType() const override {
        return "Book";
    }

    void display() const override {
        cout << "Book - Title: " << Title << ", Author: " << Author << ", ISBN: " << ISBN << endl;
    }
};

class Journal : public Resource {
public:
    Journal(const string& t, const string& a, const string& i)
        : Resource(t, a, i) {}

    string getType() const override {
        return "Journal";
    }

    void display() const override {
        cout << "Journal - Title: " << Title << ", Author: " << Author << ", ISBN: " << ISBN <<  endl;
    }
};

class DigitalResource : public Resource {
public:
    DigitalResource(const string& t, const string& a, const string& i)
        : Resource(t, a, i) {}

    string getType() const override {
        return "Digital Resource";
    }

    void display() const override {
        cout << "Digital Resource - Title: " << Title << ", Author: " << Author << ", ISBN: " << ISBN <<  endl;
    }
};

// Catalog class using STL container
class Catalog {
private:
    vector<shared_ptr<Resource>> resources;

public:
    // Method to add resources to the catalog
    void addResource(shared_ptr<Resource> resource) {
        resources.push_back(resource);
    }

    // Method to remove resources from the catalog by ISBN
    void removeResourceByISBN(const string& ISBN) {
        resources.erase(remove_if(resources.begin(), resources.end(),
            [&](const shared_ptr<Resource>& res) {
                return res->getISBN() == ISBN;
            }), resources.end());
    }

    // Method to search for resources by Title
    vector<shared_ptr<Resource>> searchByTitle(const string& Title) const {
        vector<shared_ptr<Resource>> result;
        for (const auto& resource : resources) {
            if (resource->getTitle() == Title) {
                result.push_back(resource);
            }
        }
        return result;
    }

    // Method to search for resources by Author
    vector<shared_ptr<Resource>> searchByAuthor(const string& Author) const {
        vector<shared_ptr<Resource>> result;
        for (const auto& resource : resources) {
            if (resource->getAuthor() == Author) {
                result.push_back(resource);
            }
        }
        return result;
    }

    // Method to generate a report of all resources grouped by type
    void generateReport() const {
        cout << "Catalog Report by Type:\n";
        for (const auto& resource : resources) {
            resource->display();
        }
    }
};

// Command-line interface for interacting with the catalog
void commandLineInterface(Catalog& catalog) {
    int choice;
    do {
        cout << "\nLibrary Catalog Menu:\n";
        cout << "1. Add a resource\n";
        cout << "2. Remove a resource by ISBN\n";
        cout << "3. Search by Title\n";
        cout << "4. Search by Author\n";
        cout << "5. Generate report\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string Title, Author, ISBN, type;
                cout << "Enter Title: ";
                cin>>Title;
                cout << "Enter Author: ";
                cin>>Author;
                cout << "Enter ISBN: ";
                cin>>ISBN;
                cout << "Enter type (Book, Journal, DigitalResource): ";
                cin>>type;

                if (type == "Book") {
                    catalog.addResource(make_shared<Book>(Title, Author, ISBN));
                } else if (type == "Journal") {
                    catalog.addResource(make_shared<Journal>(Title, Author, ISBN));
                } else if (type == "DigitalResource") {
                    catalog.addResource(make_shared<DigitalResource>(Title, Author, ISBN));
                } else {
                    cout << "Unknown type! Resource not added.\n";
                }
                break;
            }
            case 2: {
                string ISBN;
                cout << "Enter ISBN of resource to remove: ";
                cin>>ISBN;
                catalog.removeResourceByISBN(ISBN);
                break;
            }
            case 3: {
                string Title;
                cout << "Enter Title: ";
                cin>>Title;
                auto results = catalog.searchByTitle(Title);
                if (results.empty()) {
                    cout << "No resources found with the Title: " << Title << "\n";
                } else {
                    for (const auto& res : results) {
                        res->display();
                    }
                }
                break;
            }
            case 4: {
                string Author;
                cout << "Enter Author: ";
                cin>>Author;
                auto results = catalog.searchByAuthor(Author);
                if (results.empty()) {
                     cout << "No resources found by the Author: " << Author << "\n";
                } else {
                    for (const auto& res : results) {
                        res->display();
                    }
                }
                break;
            }
            case 5:
                catalog.generateReport();
                break;
        }
    } while (choice != 0);
}

// Main program
int main() {
    Catalog catalog;
    commandLineInterface(catalog);
    return 0;
}*/

/*#include "bits/stdc++.h"
using namespace std;

// Base Resource class
class Resource {
protected:
    string Title;
    string Author;
    string ISBN;
public:
    Resource(string t, string a, string i)
        : Title(t), Author(a), ISBN(i) {}

    virtual ~Resource() = default;
    virtual string getType() { return "Resource"; }

    string getTitle() { return Title; }
    string getAuthor() { return Author; }
    string getISBN() { return ISBN; }

    virtual void display() {
        cout << "Resource - Title: " << Title << ", Author: " << Author << ", ISBN: " << ISBN << endl;
    }
};

// Derived classes
class Book : public Resource {
public:
    Book(string t, string a, string i) : Resource(t, a, i) {}

    string getType() { return "Book"; }

    void display() {
        cout << "Book - Title: " << Title << ", Author: " << Author << ", ISBN: " << ISBN << endl;
    }
};

class Journal : public Resource {
public:
    Journal(string t, string a, string i) : Resource(t, a, i) {}

    string getType() { return "Journal"; }

    void display() {
        cout << "Journal - Title: " << Title << ", Author: " << Author << ", ISBN: " << ISBN << endl;
    }
};

class DigitalResource : public Resource {
public:
    DigitalResource(string t, string a, string i) : Resource(t, a, i) {}

    string getType() { return "Digital Resource"; }

    void display() {
        cout << "Digital Resource - Title: " << Title << ", Author: " << Author << ", ISBN: " << ISBN << endl;
    }
};

// Simplified Catalog class
class Catalog {
private:
    vector<shared_ptr<Resource>> resources;

public:
    void addResource(shared_ptr<Resource> resource) {
        resources.push_back(resource);
    }

    void removeResourceByISBN(string ISBN) {
        resources.erase(remove_if(resources.begin(), resources.end(),
            [&](shared_ptr<Resource> res) {
                return res->getISBN() == ISBN;
            }), resources.end());
    }

    vector<shared_ptr<Resource>> searchByTitle(string Title) {
        vector<shared_ptr<Resource>> result;
        for (auto resource : resources) {
            if (resource->getTitle() == Title) {
                result.push_back(resource);
            }
        }
        return result;
    }

    vector<shared_ptr<Resource>> searchByAuthor(string Author) {
        vector<shared_ptr<Resource>> result;
        for (auto resource : resources) {
            if (resource->getAuthor() == Author) {
                result.push_back(resource);
            }
        }
        return result;
    }

    void generateReport() {
        cout << "Catalog Report:\n";
        for (auto resource : resources) {
            resource->display();
        }
    }
};

// Simplified menu interface
void showMenu(Catalog& catalog) {
    int choice;
    do {
        cout << "\nLibrary Catalog Menu:\n";
        cout << "1. Add resource\n";
        cout << "2. Remove resource\n";
        cout << "3. Search by Title\n";
        cout << "4. Search by Author\n";
        cout << "5. Show all resources\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string Title, Author, ISBN, type;
                cout << "Title: ";
                cin >> Title;
                cout << "Author: ";
                cin >> Author;
                cout << "ISBN: ";
                cin >> ISBN;
                cout << "Type (Book/Journal/Digital): ";
                cin >> type;

                if (type == "Book") {
                    catalog.addResource(make_shared<Book>(Title, Author, ISBN));
                } else if (type == "Journal") {
                    catalog.addResource(make_shared<Journal>(Title, Author, ISBN));
                } else if (type == "Digital") {
                    catalog.addResource(make_shared<DigitalResource>(Title, Author, ISBN));
                }
                break;
            }
            case 2: {
                string ISBN;
                cout << "ISBN to remove: ";
                cin >> ISBN;
                catalog.removeResourceByISBN(ISBN);
                break;
            }
            case 3: {
                string Title;
                cout << "Title to search: ";
                cin >> Title;
                auto results = catalog.searchByTitle(Title);
                for (auto res : results) {
                    res->display();
                }
                break;
            }
            case 4: {
                string Author;
                cout << "Author to search: ";
                cin >> Author;
                auto results = catalog.searchByAuthor(Author);
                for (auto res : results) {
                    res->display();
                }
                break;
            }
            case 5:
                catalog.generateReport();
                break;
        }
    } while (choice != 0);
}

int main() {
    Catalog catalog;
    showMenu(catalog);
    return 0;
}*/

/*#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Resource {
protected:
    string Title;
    string Author;
    string ISBN;
public:
    Resource(string t, string a, string i)
        : Title(t), Author(a), ISBN(i) {}

    virtual ~Resource() = default;
    virtual string getType() { return "Resource"; }

    string getTitle() { return Title; }
    string getAuthor() { return Author; }
    string getISBN() { return ISBN; }



    virtual void display() {
        cout << "\n----------------------------------------\n";
        cout << "Type: " << getType() << "\n";
        cout << "Title: " << Title << "\n";
        cout << "Author: " << Author << "\n";
        cout << "ISBN: " << ISBN << "\n";
        cout << "----------------------------------------\n";
    }
};

class Book : public Resource {
public:
    Book(string t, string a, string i)
        : Resource(t, a, i){
    }
};

class Journal : public Resource {
public:
    Journal(string t, string a, string i)
        : Resource(t, a, i) {}
};

class DigitalResource : public Resource {
public:
    DigitalResource(string t, string a, string i)
        : Resource(t, a, i) {}
};

class Catalog {
private:
    vector<Resource*> resources;

public:
    void addResource(<Resource*> resource) {
        bool exists = false;
        for(auto& res : resources) {
            if(res->getISBN() == resource->getISBN()) {
                exists = true;
                break;
            }
        }

        if(!exists) {
            resources.push_back(resource);
            cout << "\n Resource successfully added to catalog!\n";
        } else {
            cout << "\n A resource with this ISBN already exists!\n";
        }
    }

    void removeResourceByISBN(string ISBN) {
        bool found = false;
        for(int i = 0; i < resources.size(); i++) {
            if(resources[i]->getISBN() == ISBN) {
                resources.erase(resources.begin() + i);
                found = true;
                break;
            }
        }

        if(found) {
            cout << "\n Resource successfully removed from catalog!\n";
        } else {
            cout << "\n No resource found with ISBN: " << ISBN << "\n";
        }
    }

    void searchByTitle(string searchTitle) {
        bool found = false;
        cout << "\n Search Results for Title: " << searchTitle << "\n";

        for(auto& resource : resources) {
            if(resource->getTitle().find(searchTitle) != string::npos) {
                resource->display();
                found = true;
            }
        }

        if(!found) {
            cout << "No resources found matching the Title: " << searchTitle << "\n";
        }
    }

    void searchByAuthor(string searchAuthor) {
        bool found = false;
        cout << "\n Search Results for Author: " << searchAuthor << "\n";

        for(auto& resource : resources) {
            if(resource->getAuthor().find(searchAuthor) != string::npos) {
                resource->display();
                found = true;
            }
        }

        if(!found) {
            cout << "No resources found by Author: " << searchAuthor << "\n";
        }
    }

    void generateReport() {
        if(resources.empty()) {
            cout << "\n Catalog Report: No resources in catalog\n";
            return;
        }

        cout << "\n RICHFIELD LIBRARY CATALOG REPORT\n";
        cout << "Total Resources: " << resources.size() << "\n\n";

        cout << "=== Books ===\n";
        for(auto& resource : resources) {
            if(resource->getType() == "Book")
                resource->display();
        }

        cout << "\n=== Journals ===\n";
        for(auto& resource : resources) {
            if(resource->getType() == "Journal")
                resource->display();
        }

        cout << "\n=== Digital Resources ===\n";
        for(auto& resource : resources) {
            if(resource->getType() == "Digital Resource")
                resource->display();
        }
    }
};

void showWelcomeMessage() {
    cout << "\n************************************************\n";
    cout << "  Welcome to Richfield Library Catalog System \n";
    cout << "************************************************\n";
}

void showMenu() {
    cout << "\n MAIN MENU\n";
    cout << "1. Add new resource\n";
    cout << "2. Remove resource\n";
    cout << "3. Search by Title\n";
    cout << "4. Search by Author\n";
    cout << "5. View catalog report\n";
    cout << "0. Exit system\n";
    cout << "\nPlease select an option: ";
}

void runLibraryCatalog() {
    Catalog catalog;
    int choice;
    string input;

    showWelcomeMessage();

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                cout << "\n ADD NEW RESOURCE\n";
                string Title, Author, ISBN, type, input;

                cout << "Enter Title: ";
                getline(cin, Title);
                cout << "Enter Author: ";
                getline(cin, Author);
                cout << "Enter ISBN: ";
                getline(cin, ISBN);
                cout << "Enter type (Book/Journal/Digital): ";
                getline(cin, type);

                if(type == "Book") {
                    cout << "Enter edition: ";
                    getline(cin, input);
                    catalog.addResource(make_shared<Book>(Title, Author, ISBN, input));
                }
                else if(type == "Journal") {
                    cout << "Enter volume: ";
                    getline(cin, input);
                    catalog.addResource(make_shared<Journal>(Title, Author, ISBN, input));
                }
                else if(type == "Digital") {
                    catalog.addResource(make_shared<DigitalResource>(Title, Author, ISBN));
                }
                break;
            }
            case 2: {
                cout << "\n REMOVE RESOURCE\n";
                cout << "Enter ISBN of resource to remove: ";
                getline(cin, input);
                catalog.removeResourceByISBN(input);
                break;
            }
            case 3: {
                cout << "\n SEARCH BY Title\n";
                cout << "Enter Title to search: ";
                getline(cin, input);
                catalog.searchByTitle(input);
                break;
            }
            case 4: {
                cout << "\n SEARCH BY Author\n";
                cout << "Enter Author name: ";
                getline(cin, input);
                catalog.searchByAuthor(input);
                break;
            }
            case 5:
                catalog.generateReport();
                cout << "\nThank you for using Richfield Library Catalog System! Goodbye!\n";
                cout << "\nInvalid option. Please try again.\n";
                break;
        }
    } while(choice != 5);
}

int main() {
    runLibraryCatalog();
    return 0;
}*/

/*#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

using namespace std;

struct classstudent {
int bookID;
char Title[30];
char Authorofbook[30];
int costofbook;
};

const int books = 5;
int arr;

classstudent classstudentobj[books];

void Add_Book() {
if(arr < books){
    cout<<"---***Enter the details of Books***---"<<endl;
    cout<< "Enter a book id:" <<endl;
    cin>>classstudentobj[arr].bookID;
    cout<< "Enter book Title:" <<endl;
    cin>>classstudentobj[arr].Title;
    cout<< "Enter name of Author:" <<endl;
    cin>>classstudentobj[arr].Authorofbook;
    cout<< "Enter the cost of book:" <<endl;
    cin>>classstudentobj[arr].costofbook;
    arr++;
}
else{
    cout<<"No more space in system for another"<<endl;
}

}

void Display_Books() {
for(int i = 0; i< arr; i++){
    cout<< "---***Details of all books in library---***";
    cout<< "Book ID = "<<classstudentobj[i].bookID<<endl;
    cout<< "Book Title is = "<<classstudentobj[i].Title<<endl;
    cout<< "Author Name = "<<classstudentobj[i].Authorofbook<<endl;
    cout<< "cost of book = "<<classstudentobj[i].costofbook<<endl;
}
}

void Book_Author(){
char search_book[30];
cout<< "Enter the name of Author"<<endl;
cin>>search_book;
int i = 0;
while(i< arr){
    if(strcmp(search_book,classstudentobj[i].Authorofbook)==0){
        cout<< "Book ID = "<<classstudentobj[i].bookID<<endl;
    cout<< "Book Title is = "<<classstudentobj[i].Title<<endl;
    cout<< "Author Name = "<<classstudentobj[i].Authorofbook<<endl;
    cout<< "cost of book = "<<classstudentobj[i].costofbook<<endl;
    }
}
}

int main()
{
    int choice;
    char input;

    do {
    cout<< "***---Library Book Record System***---"<<endl;
    cout << "1: enter a book record:" <<endl;
    cout << "2: enter a book record:" <<endl;
    cout << "3: enter a book record:" <<endl;
    cout << "4: enter a book record:" <<endl;
    cout << "5: enter a book record:" <<endl;
    cout << "Enter the choice:" <<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
            Add_Book();
            break;
        case 2:
            Display_Books();
            break;

        case 3:
            Add_Book();
            break;

        case 4:
            Add_Book();
            break;

        case 5:
            exit(0);
        default:
            cout<< "Invalid choice please try again";<<endl;
    }
    cout<< "Are you sure you want to continue, please press y or Y"<<endl;
    cin>>input;
    }while(input == 'y' || input== 'Y');

}
return 0;
}*/

/*#include <iostream>
#include <cstring>  // Use <cstring> for string operations in C++
using namespace std;

struct classstudent {
    int bookID;
    char Title[30];
    char Authorofbook[30];
    int costofbook;
};

const int books = 5;
int arr = 0;  // Initialize arr to 0

classstudent classstudentobj[books];

void Add_Book() {
    if (arr < books) {
        cout << "---***Enter the details of Books***---" << endl;
        cout << "Enter a book id: " << endl;
        cin >> classstudentobj[arr].bookID;
        cout << "Enter book Title: " << endl;
        cin >> classstudentobj[arr].Title;
        cout << "Enter name of Author: " << endl;
        cin >> classstudentobj[arr].Authorofbook;
        cout << "Enter the cost of book: " << endl;
        cin >> classstudentobj[arr].costofbook;
        arr++;
    } else {
        cout << "No more space in the system for another book." << endl;
    }
}

void Display_Books() {
    if (arr == 0) {
        cout << "No books available in the library." << endl;
        return;
    }

    for (int i = 0; i < arr; i++) {
        cout << "---***Details of all books in library---***" << endl;
        cout << "Book ID = " << classstudentobj[i].bookID << endl;
        cout << "Book Title = " << classstudentobj[i].Title << endl;
        cout << "Author Name = " << classstudentobj[i].Authorofbook << endl;
        cout << "Cost of book = " << classstudentobj[i].costofbook << endl;
    }
}

void Book_Author() {
    char search_book[30];
    cout << "Enter the name of the Author:" << endl;
    cin >> search_book;
    bool found = false;

    for (int i = 0; i < arr; i++) {
        if (strcmp(search_book, classstudentobj[i].Authorofbook) == 0) {
            found = true;
            cout << "---***Book Found***---" << endl;
            cout << "Book ID = " << classstudentobj[i].bookID << endl;
            cout << "Book Title = " << classstudentobj[i].Title << endl;
            cout << "Author Name = " << classstudentobj[i].Authorofbook << endl;
            cout << "Cost of book = " << classstudentobj[i].costofbook << endl;
        }
    }
    if (!found) {
        cout << "No books found by this Author." << endl;
    }
}

int main() {
    int choice;
    char input;

    do {
        cout << "***---Library Book Record System***---" << endl;
        cout << "1: Add a book record" << endl;
        cout << "2: Display all book records" << endl;
        cout << "3: Search book by Author" << endl;
        cout << "4: Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                Add_Book();
                break;
            case 2:
                Display_Books();
                break;
            case 3:
                Book_Author();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice, please try again." << endl;
        }
        cout << "Do you want to continue? Press 'y' or 'Y' for yes: ";
        cin >> input;
    } while (input == 'y' || input == 'Y');

    return 0;
}*/

// Required header files
/*#include <iostream>    // For input/output operations
#include <vector>      // For storing collections of resources
#include <string>      // For string handling
#include <memory>      // For smart pointers (unique_ptr)
#include <algorithm>   // For algorithms like find_if
#include <map>         // For grouping resources by type
using namespace std;

// Base abstract class for all library resources
class Resource {
protected:
    // Common attributes for all resources
    string ISBN;           // Unique identifier for the resource
    string Title;          // Title of the resource
    string Author;         // Author of the resource
    int publicationYear;   // Year of publication

public:
    // Constructor initializing common attributes
    Resource(const string& ISBN, const string& Title, const string& Author, int year)
        : ISBN(ISBN), Title(Title), Author(Author), publicationYear(year) {}

    // Virtual destructor for proper cleanup of derived classes
    virtual ~Resource() = default;

    // Pure virtual function making this an abstract class
    // Each derived class must implement its own type string
    virtual string getTypeStr() const = 0;

    // Const getter methods to ensure data cannot be modified
    const string& getISBN() const { return ISBN; }
    const string& getTitle() const { return Title; }
    const string& getAuthor() const { return Author; }

    // Virtual display method that can be overridden by derived classes
    virtual void display() const {
        cout << "Type: " << getTypeStr() << "\n"
             << "ISBN: " << ISBN << "\n"
             << "Title: " << Title << "\n"
             << "Author: " << Author << "\n"
             << "Year: " << publicationYear << "\n";
    }
};

// Derived class for Books
class Book : public Resource {
private:
    string edition;    // Specific to books: edition information
public:
    // Constructor initializing book-specific attributes
    Book(const string& ISBN, const string& Title, const string& Author,
         int year, const string& edition)
        : Resource(ISBN, Title, Author, year), edition(edition) {}

    // Implementation of the pure virtual function
    string getTypeStr() const { return "Book"; }

    // Override display to include book-specific information
    void display() const {
        Resource::display();
        cout << "Edition: " << edition << "\n";
    }
};

// Derived class for Journals
class Journal : public Resource {
private:
    int volume;    // Journal-specific: volume number
    int issue;     // Journal-specific: issue number
public:
    // Constructor initializing journal-specific attributes
    Journal(const string& ISBN, const string& Title, const string& Author,
            int year, int vol, int iss)
        : Resource(ISBN, Title, Author, year), volume(vol), issue(iss) {}

    string getTypeStr() const { return "Journal"; }

    void display() const {
        Resource::display();
        cout << "Volume: " << volume << ", Issue: " << issue << "\n";
    }
};

// Derived class for Digital Resources
class DigitalResource : public Resource {
public:
    // Constructor for digital resources
    DigitalResource(const string& ISBN, const string& Title, const string& Author, int year)
        : Resource(ISBN, Title, Author, year) {}

    string getTypeStr() const { return "Digital"; }
};

// Main catalog class to manage all resources
class Catalog {
private:
    // Vector of smart pointers to store all resources
    vector<unique_ptr<Resource>> resources;

public:
    // Method to add a new resource to the catalog
    // Takes ownership of the resource using unique_ptr
    void addResource(unique_ptr<Resource> resource) {
        resources.push_back(move(resource));
    }

    // Method to remove a resource by ISBN
    // Returns true if resource was found and removed
    bool removeResource(const string& ISBN) {
        for (auto it = resources.begin(); it != resources.end(); ++it) {
            if ((*it)->getISBN() == ISBN) {
                resources.erase(it);
                return true;
            }
        }
        return false;
    }

    // Method to search resources by Title
    // Returns vector of const pointers to found resources
    vector<const Resource*> searchByTitle(const string& Title) const {
        vector<const Resource*> results;
        for (const auto& res : resources) {
            if (res->getTitle().find(Title) != string::npos) {
                results.push_back(res.get());
            }
        }
        return results;
    }

    // Method to search resources by Author
    vector<const Resource*> searchByAuthor(const string& Author) const {
        vector<const Resource*> results;
        for (const auto& res : resources) {
            if (res->getAuthor().find(Author) != string::npos) {
                results.push_back(res.get());
            }
        }
        return results;
    }

    // Method to generate a report of all resources grouped by type
    void generateReport() const {
        // Map to group resources by their type
        map<string, vector<const Resource*>> groupedResources;

        // Group all resources by their type
        for (const auto& res : resources) {
            groupedResources[res->getTypeStr()].push_back(res.get());
        }

        // Display the grouped resources
        cout << "\n=== Library Resource Report ===\n";
        for (const auto& group : groupedResources) {
            cout << "\n" << group.first << "s (" << group.second.size() << "):\n";
            cout << "------------------------\n";
            for (const auto& res : group.second) {
                res->display();
                cout << "------------------------\n";
            }
        }
    }
};

// Main function implementing the user interface
int main() {
    Catalog catalog;   // Create catalog instance
    int choice;

    // Main program loop
    do {
        // Display menu
        cout << "\nLibrary Catalog System\n"
             << "1. Add new resource\n"
             << "2. Remove resource\n"
             << "3. Search by Title\n"
             << "4. Search by Author\n"
             << "5. Generate report\n"
             << "6. Exit\n"
             << "Enter choice: ";

        cin >> choice;
        cin.ignore();  // Clear input buffer

        // Handle user choice
        switch (choice) {
            case 1: {  // Add new resource
                // Get resource type
                cout << "Select resource type:\n"
                     << "1. Book\n"
                     << "2. Journal\n"
                     << "3. Digital Resource\n"
                     << "Enter choice: ";
                int type;
                cin >> type;
                cin.ignore();

                // Get common resource information
                string ISBN, Title, Author;
                int year;

                cout << "Enter ISBN: ";
                getline(cin, ISBN);
                cout << "Enter Title: ";
                getline(cin, Title);
                cout << "Enter Author: ";
                getline(cin, Author);
                cout << "Enter publication year: ";
                cin >> year;

                // Create specific resource type based on user choice
                switch (type) {
                    case 1: {  // Book
                        string edition;
                        cout << "Enter edition: ";
                        cin.ignore();
                        getline(cin, edition);
                        catalog.addResource(make_unique<Book>(
                            ISBN, Title, Author, year, edition));
                        break;
                    }
                    case 2: {  // Journal
                        int volume, issue;
                        cout << "Enter volume: ";
                        cin >> volume;
                        cout << "Enter issue: ";
                        cin >> issue;
                        catalog.addResource(make_unique<Journal>(
                            ISBN, Title, Author, year, volume, issue));
                        break;
                    }
                    case 3: {  // Digital Resource
                        catalog.addResource(make_unique<DigitalResource>(
                            ISBN, Title, Author, year));
                        break;
                    }
                }
                cout << "Resource added successfully!\n";
                break;
            }
            case 2: {  // Remove resource
                string ISBN;
                cout << "Enter ISBN to remove: ";
                getline(cin, ISBN);
                if (catalog.removeResource(ISBN)) {
                    cout << "Resource removed successfully!\n";
                } else {
                    cout << "Resource not found!\n";
                }
                break;
            }
            case 3: {  // Search by Title
                string Title;
                cout << "Enter Title to search: ";
                getline(cin, Title);
                auto results = catalog.searchByTitle(Title);
                cout << "\nFound " << results.size() << " matches:\n";
                for (const auto& res : results) {
                    res->display();
                    cout << "------------------------\n";
                }
                break;
            }
            case 4: {  // Search by Author
                string Author;
                cout << "Enter Author to search: ";
                getline(cin, Author);
                auto results = catalog.searchByAuthor(Author);
                cout << "\nFound " << results.size() << " matches:\n";
                for (const auto& res : results) {
                    res->display();
                    cout << "------------------------\n";
                }
                break;
            }
            case 5: {  // Generate report
                catalog.generateReport();
                break;
            }
            case 6:  // Exit
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Resource {
protected:
    string ISBN;
    string Title;
    string Author;
    int publicationYear;

public:
    Resource(const string& ISBN, const string& Title, const string& Author, int year)
        : ISBN(ISBN), Title(Title), Author(Author), publicationYear(year) {}

    virtual ~Resource() = default;

    const string& getISBN() const { return ISBN; }
    const string& getTitle() const { return Title; }
    const string& getAuthor() const { return Author; }

    virtual void display() const {
        cout << "ISBN: " << ISBN << "\n"
             << "Title: " << Title << "\n"
             << "Author: " << Author << "\n"
             << "Year: " << publicationYear << "\n";
    }
};

class Book : public Resource {
private:
    string edition;

public:
    Book(const string& ISBN, const string& Title, const string& Author, int year, const string& edition)
        : Resource(ISBN, Title, Author, year), edition(edition) {}

    void display() const {
        Resource::display();
        cout << "Edition: " << edition << "\n";
    }
};

class Journal : public Resource {
private:
    int volume;
    int issue;

public:
    Journal(const string& ISBN, const string& Title, const string& Author, int year, int vol, int iss)
        : Resource(ISBN, Title, Author, year), volume(vol), issue(iss) {}

    void display() const {
        Resource::display();
        cout << "Volume: " << volume << ", Issue: " << issue << "\n";
    }
};

class DigitalResource : public Resource {
public:
    DigitalResource(const string& ISBN, const string& Title, const string& Author, int year)
        : Resource(ISBN, Title, Author, year) {}
};

class Catalog {
private:
    vector<shared_ptr<Resource>> resources; // Use smart pointers

public:
    void addResource(shared_ptr<Resource> resource) {
        resources.push_back(resource);
    }

    bool removeResource(const string& ISBN) {
        for (auto it = resources.begin(); it != resources.end(); ++it) {
            if ((*it)->getISBN() == ISBN) {
                resources.erase(it);
                return true;
            }
        }
        return false;
    }

    vector<shared_ptr<Resource>> searchByTitle(const string& Title) const {
        vector<shared_ptr<Resource>> results;
        for (const auto& res : resources) {
            if (res->getTitle().find(Title) != string::npos) {
                results.push_back(res);
            }
        }
        return results;
    }

    vector<shared_ptr<Resource>> searchByAuthor(const string& Author) const {
        vector<shared_ptr<Resource>> results;
        for (const auto& res : resources) {
            if (res->getAuthor().find(Author) != string::npos) {
                results.push_back(res);
            }
        }
        return results;
    }

    vector<shared_ptr<Resource>> searchByISBN(const string& ISBN) const {
        vector<shared_ptr<Resource>> results;
        for (const auto& res : resources) {
            if (res->getISBN() == ISBN) {
                results.push_back(res);
            }
        }
        return results;
    }

    void generateReport() const {
        cout << "\n=== Library Resource Report ===\n";
        for (const auto& res : resources) {
            res->display();
            cout << "------------------------\n";
        }
    }
};

void addResourceMenu(Catalog& catalog) {
    cout << "Select resource type:\n"
         << "1. Book\n"
         << "2. Journal\n"
         << "3. Digital Resource\n"
         << "Enter choice: ";
    int type;
    cin >> type;
    cin.ignore();

    string ISBN, Title, Author;
    int year;

    cout << "Enter ISBN: ";
    getline(cin, ISBN);
    cout << "Enter Title: ";
    getline(cin, Title);
    cout << "Enter Author: ";
    getline(cin, Author);
    cout << "Enter publication year: ";
    cin >> year;
    cin.ignore();

    switch (type) {
        case 1: {
            string edition;
            cout << "Enter edition: ";
            getline(cin, edition);
            catalog.addResource(make_shared<Book>(ISBN, Title, Author, year, edition));
            break;
        }
        case 2: {
            int volume, issue;
            cout << "Enter volume: ";
            cin >> volume;
            cout << "Enter issue: ";
            cin >> issue;
            catalog.addResource(make_shared<Journal>(ISBN, Title, Author, year, volume, issue));
            break;
        }
        case 3: {
            catalog.addResource(make_shared<DigitalResource>(ISBN, Title, Author, year));
            break;
        }
        default:
            cout << "Invalid resource type!\n";
            break;
    }
    cout << "Resource added successfully!\n";
}

int main() {
    Catalog catalog;
    int choice;

    do {
        cout << "\nLibrary Catalog System\n"
             << "1. Add Resource\n"
             << "2. Remove Resource\n"
             << "3. Search Resource\n"
             << "4. Generate Report\n"
             << "5. Exit\n"
             << "Choose any option: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addResourceMenu(catalog);
                break;
            case 2: {
                string ISBN;
                cout << "Enter ISBN to remove: ";
                getline(cin, ISBN);
                if (catalog.removeResource(ISBN)) {
                    cout << "Resource removed successfully!\n";
                } else {
                    cout << "Resource not found!\n";
                }
                break;
            }
            case 3: {
                cout << "Search by:\n1. Title\n2. Author\n3. ISBN\nChoose option: ";
                int searchType;
                cin >> searchType;
                cin.ignore();

                if (searchType == 1) {
                    string Title;
                    cout << "Enter Title to search: ";
                    getline(cin, Title);
                    auto results = catalog.searchByTitle(Title);
                    cout << "\nFound " << results.size() << " matches:\n";
                    for (const auto& res : results) {
                        res->display();
                        cout << "------------------------\n";
                    }
                } else if (searchType == 2) {
                    string Author;
                    cout << "Enter Author to search: ";
                    getline(cin, Author);
                    auto results = catalog.searchByAuthor(Author);
                    cout << "\nFound " << results.size() << " matches:\n";
                    for (const auto& res : results) {
                        res->display();
                        cout << "------------------------\n";
                    }
                } else if (searchType == 3) {
                    string ISBN;
                    cout << "Enter ISBN to search: ";
                    getline(cin, ISBN);
                    auto results = catalog.searchByISBN(ISBN);
                    cout << "\nFound " << results.size() << " matches:\n";
                    for (const auto& res : results) {
                        res->display();
                        cout << "------------------------\n";
                    }
                } else {
                    cout << "Invalid search type!\n";
                }
                break;
            }
            case 4:
                catalog.generateReport();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}






