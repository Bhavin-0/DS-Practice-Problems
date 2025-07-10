#include <iostream>
#include <string>
using namespace std;

const int MAX=100;

class Person {
private:
    string aadhaarNumber;
    string name;
    int age;
    string mobileNumber;
    string address;
    string gender;

    // Aadhaar validator
    bool validateAadhaar(string input) {
        if (input.size() != 12) {
            cout << " Invalid Aadhaar: It must be exactly 12 digits.\n";
            return false;
        }
        for (char c : input) {
            if (!isdigit(c)) {
                cout << " Invalid Aadhaar: Only digits (0-9) are allowed.\n";
                return false;
            }
        }
        return true;
    }

    // Mobile number validator
    bool validateMobileNumber(string input) {
        if (input.length() != 10) {
            cout << "Invalid Mobile Number: It must be exactly 10 digits.\n";
            return false;
        }
        for (char c : input) {
            if (!isdigit(c)) {
                cout << " Invalid Mobile Number: Only digits (0-9) are allowed.\n";
                return false;
            }
        }
        return true;
    }

public:
    // Input method
    void input() {
        // Aadhaar input with validation loop
        do {
            cout << "Enter Aadhaar Number (12 digits): ";
            cin >> aadhaarNumber;
        } while (!validateAadhaar(aadhaarNumber));
        cout << " Valid Aadhaar Number.\n";

        // Name
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        // Age
        cout << "Enter Age: ";
        cin >> age;

        // Gender
        cout << "Enter Gender (Male/Female/Other): ";
        cin >> gender;

        // Address
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);

        // Mobile input with validation loop
        do {
            cout << "Enter Mobile Number (10 digits): ";
            cin >> mobileNumber;
        } while (!validateMobileNumber(mobileNumber));
        cout << " Valid Mobile Number.\n";
    }

    // Display method
    void display() {
        cout << "\n--- Aadhaar Record ---\n";
        cout << "Aadhaar Number: " << aadhaarNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl;
        cout << "Mobile: " << mobileNumber << endl;
    }

    string getAadhaarNumber() {
        return aadhaarNumber;
    }

    // Update record
    void updateAadhaar() {
        cout << "\nUpdating record...\n";
        input();
    }
};

// Test in main
int main() {
    Person records[MAX];
    int numberOfRecords=0;

    int choice;
    cout<<"Enter your choice : ";
    cin>>choice;

    do{
        cout<<"\n1. Add Record";
        cout<<"\n2. View All Records";
        cout<<"\n3. Search Record";
        cout<<"\n4. Update Record";
        cout<<"\n5. Delete Record";
        cout<<"\n6. Exit";

        switch(choice){
            case 1:
                if(numberOfRecords<MAX){
                    records[numberOfRecords].input();
                    numberOfRecords++;
                }else{
                    cout<<"\nRecord Limit Reached.";
                }
                break;
            case 2:
                for(int i=0;i<=numberOfRecords;i++){
                    records[i].display();
                }
                break;
            case 3:
                string searchId;
                cout<<"Enter the Aadhaar Number : ";
                cin>>searchId;
                bool found = false;
                for(int i=0;i<=numberOfRecords;i++){
                    if(records[i].getAadhaarNumber() == searchId){
                        records[i].display();
                        cout<<"Record found.";
                        found = true;
                        break;
                    }
                    if(!found)  cout<<"Record does not exists.\n";
                }
            case 4:
                string updateId;
                cout<<"Enter Aadhaar Number to update : ";
                cin>>updateId;
                bool found = false;
                for(int i=0;i<=numberOfRecords;i++){
                    if(records[i].getAadhaarNumber()==updateId){
                        records[i].updateAadhaar();
                        cout<<"Record updated Successfully.";
                        found = true;
                        break;
                    }
                    if(!found)  cout<<"Aadhaar does not exists.\n";
                }
            case 5:
                string deleteId;
                cout<<"Enter the Aadhaar Number to delete : ";
                cin>>deleteId;
                bool deleted = false;
                for(int i=0;i<=numberOfRecords;i++){
                    if(records[i].getAadhaarNumber() == deleteId){
                        records[i] = records[numberOfRecords-1];
                        deleted = true;
                        cout<<"Record deleted Succesfully.";
                        numberOfRecords--;
                        break;
                    }
                    if(!deleted)    cout<<"Record not found !."
                }
            case 6:
            default:
        }

    }while(choice != 6);
    {
        /* code */
    }
    
    
    return 0;
}
