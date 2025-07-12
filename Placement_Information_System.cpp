#include<iostream>
using namespace std;

class PlacementRecord{
    friend class PlacementSystem;

    private:
        int prn;
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
        PlacementSystem();
        void insertRecord();
        void updateRecord();
        void searchRecord();
        void sortRecord();
        void listRecord();
        void deleteRecord();
        ~PlacementSystem();
};

void PlacementSystem::insertRecord(){
    PlacementRecord* newRecord = new PlacementRecord;

    cout<<"Enter PRN : ";
    cin>>newRecord->prn;

    cout<<"Enter your Name : ";
    cin>>newRecord->name;

    cout<<"Enter your CGPA : ";
    cin>>newRecord->cgpa;

    cout<<"Enter branch : ";
    cin>>newRecord->branch;

    cout<<"Enter Company Name : ";
    cin>>newRecord->companyName;

    if(head == nullptr){
        head = newRecord;
    }else{
        PlacementRecord* temp = head;
        while(temp != nullptr){
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
    int updateId;
    cout<<"Enter the PRN : ";
    cin>>updateId;
    PlacementRecord* temp = head;
    while(temp != nullptr){
        if(temp->prn == updateId){
            cout<<"\n========== RECORD FOUND OF "<<temp->prn<<" ==========";
            cout << "Current Name: " << temp->name << endl;
            cout << "Current Branch: " << temp->branch << endl;
            cout << "Current Percentage: " << temp->cgpa << endl;
            cout << "Current Company Name: " << temp->companyName << endl;

            cout<<"\nEnter New Name : ";
            cin>>temp->name;

            cout<<"Enter New Branch : ";
            cin>>temp->branch;

            cout<<"Enter New CGPA : ";
            cin>>temp->cgpa;

            cout<<"Enter New Company Name : ";
            cin>>temp->companyName;

            cout<<"Record Updated Successfully.";
            return;
        }
        temp = temp->next;
    }

    cout<<"Record with "<<temp->prn<<" not found !!";
}

void PlacementSystem::listRecord(){
    PlacementRecord* temp = head;
    int count=1;
    cout<<"\n========== LIST OF PLACEMENT RECORDS ==========";
    while (temp != nullptr)
    {
        cout<<"\n Record # "<<count++;
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

    int deleteId;
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
        cout << "\nRecord deleted successfully for PRN: " << deleteId;
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
    int searchId;
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

int main(){

    return 0;
}