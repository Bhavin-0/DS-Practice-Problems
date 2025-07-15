#include <iostream>
using namespace std;

const int SIZE = 20;
class Node{
    public:
        int value;
        Node* next;
    
        Node(int val){
            value = val;
            next = nullptr;
        }
};

class HashTable{
    private:
        Node* table[SIZE];

    public:
        HashTable(){
            for(int i=0;i<SIZE;i++){
                table[i] = nullptr;
            }
        }
        void insert(int key);
        void display();
};

void HashTable::insert(int key){
    int index = key % SIZE;
    Node* newNode = new Node(key);

    if(table[index] == nullptr){
        table[index] = newNode;
    }else{
        Node* temp = table[index];
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void HashTable::display(){
    cout<<"===== HASH TABLE ( Seperate Chaning ) =====";
    for(int i=0;i<SIZE;i++){
        cout<<"Index "<<i<<" -> ";
        Node* temp = table[i];
        if(temp == nullptr){
            cout<<" Empty";
        }else{
            while(temp != nullptr){
                cout<<temp->value<<" -> ";
                temp = temp->next;
            }
            cout<<" NULL ";
        }
        cout<<endl;
    }
}

int main(){
    HashTable ht;
    int marks[] = {33, 56, 78, 12, 10, 67, 89, 99, 100, 23, 45, 71, 39, 62, 59, 90, 91, 20, 75, 66};

    for(int i=0;i<SIZE;i++){
        ht.insert(marks[i]);
    }

    ht.display();
    return 0;
}