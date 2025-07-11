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
        void serachRecord();
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

int main(){

    return 0;
}