#include<iostream>
using namespace std;

class Node{
    int marks;
    Node* prev;
    Node* next;

    Node(int marks){
        marks = this->marks;
        prev = next = nullptr;
    }
};

class DoublyLinkedList{
    private:
        Node* head;

    public:
        DoublyLinkedList(){
            head = nullptr;
        }
        void insert(int marks);
        void display();
        void sort();
        Node* getHead();

        static DoublyLinkedList mergeSorted(DoublyLinkedList& list1,DoublyLinkedList& list2){

        }
};

int main(){
    DoublyLinkedList list1,list2,mergedList;
    int choice, marks;
    
    do{
        cout << "\n=== Technical Skill Marks Manager ===";
        cout << "\n1. Insert marks into List 1";
        cout << "\n2. Insert marks into List 2";
        cout << "\n3. Sort List 1";
        cout << "\n4. Sort List 2";
        cout << "\n5. Display Lists";
        cout << "\n6. Merge Sorted Lists";
        cout << "\n7. Display Merged List";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if(cin.fail()){
            cin.clear();
            
        }

    }while(choice != 8);


    return 0;
}