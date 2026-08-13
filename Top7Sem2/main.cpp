int main() {
    try {
        // Problem 1: Handle student IDs with table size 19
        cout << "\nProblem 1 Solution:\n";
        HashTable ht1(19);
        vector<long long> students = {197354883, 933185971, 132489992, 134152075,
                                    216500325, 106500325, 216510325, 197354884};

        cout << "Inserting student IDs using linear probing...\n";
        for (long long id : students) {
            try {
                ht1.insertLinearProbing(id);
                cout << "Successfully inserted ID: " << id << endl;
            } catch (const runtime_error& e) {
                cout << "Error inserting ID " << id << ": " << e.what() << endl;
            }
        }
        ht1.display();
        cout << "Current load factor: " << fixed << setprecision(2)
             << ht1.getCurrentLoadFactor() << endl;

        // Problem 2: Handle worker IDs with table size 13
        cout << "\nProblem 2 Solution:\n";
        HashTable ht2(13);
        vector<long long> workers1 = {147, 169, 580, 216, 974, 124};

        cout << "Inserting worker IDs using linear probing...\n";
        for (long long id : workers1) {
            try {
                ht2.insertLinearProbing(id);
                cout << "Successfully inserted ID: " << id << endl;
            } catch (const runtime_error& e) {
                cout << "Error inserting ID " << id << ": " << e.what() << endl;
            }
        }
        ht2.display();
        cout << "Current load factor: " << ht2.getCurrentLoadFactor() << endl;

        // Problem 3: Handle shop worker IDs with table size 7
        cout << "\nProblem 3 Solution:\n";
        HashTable ht3(7);
        vector<long long> workers2 = {909, 185, 657, 116, 150};

        cout << "Inserting shop worker IDs using linear probing...\n";
        for (long long id : workers2) {
            try {
                ht3.insertLinearProbing(id);
                cout << "Successfully inserted ID: " << id << endl;
            } catch (const runtime_error& e) {
                cout << "Error inserting ID " << id << ": " << e.what() << endl;
            }
        }
        ht3.display();
        cout << "Current load factor: " << ht3.getCurrentLoadFactor() << endl;

        // Problem 4: Handle student IDs with double hashing
        cout << "\nProblem 4 Solution:\n";
        HashTable ht4(19);
        vector<long long> students2 = {5701, 9302, 4210, 9015, 1553, 9902, 2104};

        cout << "Inserting student IDs using double hashing...\n";
        for (long long id : students2) {
            try {
                ht4.insertDoubleHashing(id, (id + 1) % 17);
                cout << "Successfully inserted ID: " << id << endl;
            } catch (const runtime_error& e) {
                cout << "Error inserting ID " << id << ": " << e.what() << endl;
            }
        }
        ht4.display();
        cout << "Current load factor: " << ht4.getCurrentLoadFactor() << endl;

        // Demonstrate new functionality
        cout << "\nDemonstrating additional functionality:\n";

        // Search demonstration
        long long searchKey = students[0];
        cout << "\nSearching for ID " << searchKey << ": ";
        cout << (ht1.search(searchKey) ? "Found" : "Not found") << endl;

        // Remove demonstration
        cout << "Removing ID " << searchKey << ": ";
        cout << (ht1.remove(searchKey) ? "Successful" : "Failed") << endl;
        cout << "After removal:" << endl;
        ht1.display();

        // Load factor calculations demonstration
        cout << "\nLoad Factor Analysis for a table with 750 items and 1001 slots:\n";
        try {
            double loadFactor = calculateLoadFactor(750, 1001);
            cout << "Load Factor: " << fixed << setprecision(3) << loadFactor << endl;
            cout << "Average Comparisons:\n";
            cout << "Linear Probing: " << avgComparisonsLinearProbing(loadFactor) << endl;
            cout << "Quadratic Probing: " << avgComparisonsQuadraticProbing(loadFactor) << endl;
            cout << "Chaining: " << avgComparisonsChaining(loadFactor) << endl;
        } catch (const invalid_argument& e) {
            cout << "Error in calculations: " << e.what() << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "Error creating hash table: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }

    return 0;
}
