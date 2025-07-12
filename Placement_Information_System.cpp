#include<iostream>
using namespace std;

class PlacementRecord{
    friend class PlacementSystem;

    private:
        long long prn;
        string name;
        float cgpa;
        string branch;
        string companyName;
        PlacementRecord* next;
};

class PlacementSystem{
    private:
        PlacementRecord* head;

    public:
        PlacementSystem(){
            head = nullptr;
        }
        void insertRecord();
        void updateRecord();
        void searchRecord();
        void sortRecord();
        void listRecords();
        void deleteRecord();
        ~PlacementSystem();
};

void PlacementSystem::insertRecord(){
    PlacementRecord* newRecord = new PlacementRecord;

    cout<<"Enter PRN : ";
    cin>>newRecord->prn;
    cin.ignore();

    cout<<"Enter your Name : ";
    getline(cin, newRecord->name);

    cout<<"Enter your CGPA : ";
    cin>>newRecord->cgpa;
    cin.ignore();

    cout<<"Enter branch : ";
    getline(cin, newRecord->branch);

    cout<<"Enter Company Name : ";
    getline(cin, newRecord->companyName);

    newRecord->next = nullptr;

    if(head == nullptr){
        head = newRecord;
    }else{
        PlacementRecord* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newRecord;
    }
    cout<<"Record Inserted Successfully.";
}

void PlacementSystem::updateRecord(){
    if(head == nullptr){
        cout<<"\nNo Records to Update.";
    }
    long long updateId;
    cout<<"Enter the PRN : ";
    cin>>updateId;
    cin.ignore();
    PlacementRecord* temp = head;
    while(temp != nullptr){
        if(temp->prn == updateId){
            cout<<"\n========== RECORD FOUND OF "<<temp->prn<<" =========="<<endl;
            cout << "Current Name: " << temp->name << endl;
            cout << "Current Branch: " << temp->branch << endl;
            cout << "Current Percentage: " << temp->cgpa << endl;
            cout << "Current Company Name: " << temp->companyName << endl;

            cout<<"\nEnter New Name : ";
            getline(cin, temp->name);

            cout<<"Enter New Branch : ";
            getline(cin, temp->branch);

            cout<<"Enter New CGPA : ";
            cin>>temp->cgpa;
            cin.ignore();

            cout<<"Enter New Company Name : ";
            getline(cin, temp->companyName);

            cout<<"Record Updated Successfully.";
            return;
        }
        temp = temp->next;
    }

    cout<<"Record with "<<updateId<<" not found !!";
}

void PlacementSystem::listRecords(){
    PlacementRecord* temp = head;
    int count=1;
    cout<<"\n========== LIST OF PLACEMENT RECORDS ==========";
    while (temp != nullptr)
    {
        cout<<"\n Record # "<<count++<<endl;
        cout<<"PRN : "<<temp->prn<<endl;
        cout<<"Name : "<<temp->name<<endl;
        cout<<"branch : "<<temp->branch<<endl;
        cout<<"CGPA : "<<temp->cgpa<<endl;
        cout<<"Company Name : "<<temp->companyName<<endl;
        cout << "-------------------------------\n";

        temp = temp->next;
    }
}

void PlacementSystem::deleteRecord(){
    if(head == nullptr){
        cout<<"\nNo Records to delete!! ";
        return;
    }

    long long deleteId;
    cout<<"Enter PRN to delete : ";
    cin>>deleteId;
    PlacementRecord* temp = head;
    PlacementRecord* prev = nullptr;
    //case 1: delete head node 
    if(temp->prn == deleteId){
        head = head->next;
        delete temp;
        cout<<"\nRecord deleted Successfully.";
        return;
    }
    //case 2: To Traverse the list of nodes
    while(temp != nullptr && temp->prn != deleteId){
        prev = temp;
        temp = temp->next;
    }

    if(temp == nullptr) {
        cout << "\nRecord with PRN " << deleteId << " not found!";
        return;
    }
    
    //case 3: if node found  
    prev->next = temp->next;
    delete temp;
    cout<<"\nRecord Successfully deleted. ";
}

void PlacementSystem::searchRecord(){
    if(head == nullptr){
        cout<<"\nNo Records to search.";
        return;
    }

    bool found = false;
    long long searchId;
    cout<<"\nEnter PRN to search : ";
    cin>>searchId;

    PlacementRecord* temp = head;

    while(temp != nullptr){
        if(temp->prn == searchId){
            found = true;
            cout<<"\n--------- Searched Record --------- ";
            cout<<"PRN : "<<temp->prn<<endl;
            cout<<"Name : "<<temp->name<<endl;
            cout<<"branch : "<<temp->branch<<endl;
            cout<<"CGPA : "<<temp->cgpa<<endl;
            cout<<"Company Name : "<<temp->companyName<<endl;
            cout << "-------------------------------\n";
            cout<<"\nRecord Found. ";
            break;
        }
        temp = temp->next;
    }

    if(!found){
        cout<<"\nRecord Not Found !!.";
    }
}

void PlacementSystem::sortRecord(){
    // check if the LL is null or only 1 node 
    if(head == nullptr || head->next == nullptr){
        cout<<"\nNot enough records to sort.";
        return;
    }

    //use two pointer current/index 
    PlacementRecord* current = head;
    PlacementRecord* index = nullptr;

    while(current != nullptr){
        index = current->next;
        while(index != nullptr){
            if(current->prn > index->prn){
                swap(current->prn,index->prn);
                swap(current->name,index->name);
                swap(current->branch,index->branch);
                swap(current->cgpa,index->cgpa);
                swap(current->companyName,index->companyName);
            }
            index = index->next;
        }
        current = current->next;
    }
    cout<<"Record sorted Successfully by PRN.";
}

PlacementSystem::~PlacementSystem(){
    PlacementRecord* temp = head;
    while(temp!=nullptr){
        PlacementRecord* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}

int main() {
    PlacementSystem system;
    int choice;

    do {
        cout << "\n===== Placement Information System =====";
        cout << "\n1. Insert Record";
        cout << "\n2. Update Record";
        cout << "\n3. Search Record";
        cout << "\n4. Delete Record";
        cout << "\n5. Sort Records by PRN";
        cout << "\n6. List All Records";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        //To handle invalid input 
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
            cout<<"Invalid input Please enter within (1-7) digits!!";
            continue;
        }

        switch(choice) {
            case 1:
                system.insertRecord();
                break;
            case 2:
                system.updateRecord();
                break;
            case 3:
                system.searchRecord();
                break;
            case 4:
                system.deleteRecord();
                break;
            case 5:
                system.sortRecord();
                break;
            case 6:
                system.listRecords();
                break;
            case 7:
                cout << "\nExiting the program. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.";
        }

    } while (choice != 7);

    return 0;
}
