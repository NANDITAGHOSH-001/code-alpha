#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
const string CREDENTIALS_FILE = "users.txt";
bool usernameExists(const string& username) {
    ifstream infile(CREDENTIALS_FILE);
    string storedUsername, storedPassword;

    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            return true;
        }
    }
    return false;
}
void registerUser() {
    string username, password;
    cout << "Registration\n";
    cout << "Enter username: ";
    cin >> username;
    if (usernameExists(username)) {
        cout << "Error: Username already exists. Please choose another one.\n";
        return;
    }
    cout << "Enter password: ";
    cin >> password;
    ofstream outfile(CREDENTIALS_FILE, ios::app);
    outfile << username << " " << password << endl;
    cout << "Registration successful!\n";
}
void loginUser() {
    string username, password;
    cout << "Login\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    ifstream infile(CREDENTIALS_FILE);
    string storedUsername, storedPassword;
    bool found = false;
    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "Login failed: Invalid username or password.\n";
    }
}
int main() {
    int choice;
    while (true) {
        cout << "\nLogin & Registration System\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}