#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Base class for file operations
class FileManager {
protected:
    string files[2] = {"file1.txt", "file2.txt"};
    string contents[2];

public:
    void loadFiles() {
        for (int i = 0; i < 2; i++) {
            ifstream infile(files[i]);
            if (infile.is_open()) {
                string line, text = "";
                while (getline(infile, line)) {
                    text += line + " ";
                }
                contents[i] = text;
                infile.close();
            } else {
                cout << "Failed to open " << files[i] << endl;
            }
        }
    }

    void showFiles() {
        for (int i = 0; i < 2; i++) {
            cout << "Content of " << files[i] << ":\n";
            cout << contents[i] << endl << endl;
        }
    }
};

// Derived class with search function
class SearchEngine : public FileManager {
public:
    void searchWord(string word) {
        bool found = false;
        for (int i = 0; i < 2; i++) {
            if (contents[i].find(word) != string::npos) {
                cout << "Word \"" << word << "\" found in " << files[i] << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Word \"" << word << "\" not found in any file.\n";
        }
    }
};

// Main function using POP style
int main() {
    SearchEngine se;
    se.loadFiles(); // Load the documents

    int choice;
    string keyword;

    do {
        cout << "\n==== Simple C++ Search Engine ====\n";
        cout << "1. Show File Contents\n";
        cout << "2. Search Word\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                se.showFiles();
                break;
            case 2:
                cout << "Enter word to search: ";
                cin >> keyword;
                se.searchWord(keyword);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}

