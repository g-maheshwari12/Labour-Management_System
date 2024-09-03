#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<conio.h>
using namespace std;

class Labour {
private:
    string name;
    string id;
    string designation;
    int age;
    int salary;
    int experience;

    void waitForEnter() {
        cout << "\n\n\n Press enter to go back \n\n";
        cin.ignore();
        cin.get();
    }

    void listLabours() {
        system("cls");
        ifstream file("data.txt");
        if (!file.is_open()) {
            cerr << "Error opening file!\n";
            return;
        }
        cout << "\n\t      List of labours\n";
        cout << "\n----------------------------------------------";
        cout << "\n NAME        |     ID     |     DESIGNATION\n";
        cout << "----------------------------------------------";

        while (file >> name >> id >> designation >> age >> salary >> experience) {
            cout << "\n" << name << "\t\t" << id << "\t\t" << designation;
        }
        file.close();
        waitForEnter();
    }

    void showDetails() {
        system("cls");
        ifstream file("data.txt");
        if (!file.is_open()) {
            cerr << "Error opening file!\n";
            return;
        }
        string checkId;
        cout << "\n\nEnter labour ID: ";
        cin >> checkId;

        bool found = false;
        while (file >> name >> id >> designation >> age >> salary >> experience) {
            if (checkId == id) {
                found = true;
                cout << "\n---------------------";
                cout << "\nName: " << name;
                cout << "\n---------------------";
                cout << "\nId: " << id;
                cout << "\n---------------------";
                cout << "\nDesignation: " << designation;
                cout << "\n---------------------";
                cout << "\nAge: " << age;
                cout << "\n---------------------";
                cout << "\nSalary: " << salary;
                cout << "\n---------------------";
                cout << "\nExperience in years: " << experience;
                cout << "\n---------------------";
            }
        }

        if (!found) {
            cout << "\nNo record found for ID: " << checkId << "\n";
        }
        file.close();
        waitForEnter();
    }

    void editExisting() {
        system("cls");
        string checkId;
        cout << "\nEnter labour id: ";
        cin >> checkId;

        string newDesignation;
        cout << "\n-----------------------------";
        cout << "\nEnter new designation: ";
        cin >> newDesignation;

        int newSalary;
        cout << "------------------------------";
        cout << "\nEnter new Salary: ";
        cin >> newSalary;

        ifstream file("data.txt");
        ofstream tempFile("temp.txt");

        if (!file.is_open() || !tempFile.is_open()) {
            cerr << "Error opening file!\n";
            return;
        }

        bool found = false;
        while (file >> name >> id >> designation >> age >> salary >> experience) {
            if (checkId == id) {
                tempFile << name << " " << id << " " << newDesignation << " " << age << " " << newSalary << " " << experience << "\n";
                found = true;
            } else {
                tempFile << name << " " << id << " " << designation << " " << age << " " << salary << " " << experience << "\n";
            }
        }

        file.close();
        tempFile.close();

        if (!found) {
            cout << "\nNo record found for ID: " << checkId << "\n";
        } else {
            remove("data.txt");
            rename("temp.txt", "data.txt");
        }

        waitForEnter();
    }

    void addNewLabour() {
        system("cls");
        cout << "\n----------------------------------------";
        cout << "\n Enter First Name of labour: ";
        cin >> name;
        cout << "\n----------------------------------------";
        cout << "\n Enter labour ID [max 4 digits]: ";
        cin >> id;
        cout << "\n----------------------------------------";
        cout << "\n Enter Designation: ";
        cin >> designation;
        cout << "\n----------------------------------------";
        cout << "\n Enter labour Age: ";
        cin >> age;
        cout << "\n----------------------------------------";
        cout << "\n Enter labour Salary: ";
        cin >> salary;
        cout << "\n----------------------------------------";
        cout << "\n Enter labour Experience in years: ";
        cin >> experience;
        cout << "\n----------------------------------------";

        char ch;
        cout << "\nEnter 'y' to save above information\n";
        cin >> ch;
        if (ch == 'y') {
            ofstream file("data.txt", ios::app);
            if (!file.is_open()) {
                cerr << "Error opening file!\n";
                return;
            }
            file << name << " " << id << " " << designation << " " << age << " " << salary << " " << experience << "\n";
            file.close();
            cout << "\nNew labour has been added to the database\n";
        } else {
            addNewLabour();
        }
        waitForEnter();
    }

    void deleteLabourDetails() {
        system("cls");
        string checkId;
        cout << "\n----------------------------------";
        cout << "\nEnter labour Id To Remove: ";
        cin >> checkId;

        char ch;
        cout << "----------------------------------";
        cout << "\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
        cin >> ch;

        if (ch == 'y') {
            ifstream file("data.txt");
            ofstream tempFile("temp.txt");

            if (!file.is_open() || !tempFile.is_open()) {
                cerr << "Error opening file!\n";
                return;
            }

            bool found = false;
            while (file >> name >> id >> designation >> age >> salary >> experience) {
                if (checkId != id) {
                    tempFile << name << " " << id << " " << designation << " " << age << " " << salary << " " << experience << "\n";
                } else {
                    found = true;
                }
            }

            file.close();
            tempFile.close();

            if (found) {
                remove("data.txt");
                rename("temp.txt", "data.txt");
                cout << "\nRemoved Successfully\n";
            } else {
                cout << "\nNo record found for ID: " << checkId << "\n";
            }

            waitForEnter();
        } else {
            deleteLabourDetails();
        }
    }

public:
    void options() {
        if (login() != 0) return;
        while (true) {
            system("cls");
            cout << "\n\t\t\t>>>>>>>>>  LABOUR MANAGEMENT SYSTEM  <<<<<<<<<";
            cout << "\n";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\t\t\tENTER   1:   To Add New labour Details";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\t\t\tENTER   2:   To Modify Existing labour Details";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\t\t\tENTER   3:   To View labour Details";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\t\t\tENTER   4:   To View List of labours";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\t\t\tENTER   5:   To Remove a labour Details";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\t\t\tENTER   0:   To Exit     ";
            cout << "\n\t\t\t------------------------------------------------";
            cout << "\n\n\t\t\t   Please Enter Your Choice: ";
            int choice;
            cin >> choice;
            switch (choice) {
            case 0:
                system("CLS");
                cout << "\n\nLABOUR MANAGEMENT SYSTEM \n\n Brought To You By Gaurav Maheshwari\n\n ";
                Sleep(100);
                return;
            case 1: addNewLabour();
                break;
            case 2: editExisting();
                break;
            case 3: showDetails();
                break;
            case 4: listLabours();
                break;
            case 5: deleteLabourDetails();
                break;
            default: cout << "\n Sorry! I don't understand that! \n";
                break;
            }
        }
    }

    int login() {
        string password = "";
        char ch;
        cout << "\n\n\n\n\t\t\t\t\tLABOUR MANAGEMENT SYSTEM";
        cout << "\n\n\n\n\n\t\t\t\t\tEnter Your Password :";
        ch = _getch();
        while (ch != 13) {  // character 13 is enter
            password.push_back(ch);
            cout << '*';
            ch = _getch();
        }

        if (password == "gaurav") {
            cout << "\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
            for (int a = 1; a < 8; a++) {
                Sleep(500);
                cout << "...";
            }
            cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";
            system("PAUSE");
            system("CLS");
            return 0;
        } else {
            cout << "\nAccess Aborted...\n";
            return login();
        }
    }
};

int main() {
    Labour l;
    l.options();
    return 0;
}
