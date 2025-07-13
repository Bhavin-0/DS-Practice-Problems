#include<iostream>
using namespace std;

const int SIZE = 6;

class HashTable{
private:
    int table[SIZE];

public:
    HashTable(){
        for(int i = 0; i < SIZE; i++){
            table[i] = -1;
        }
    }

    void insert(int key);
    void display();
};

void HashTable::insert(int key){
    int index = key % SIZE;

    if(table[index] == -1){
        table[index] = key;
        return;
    } else {
        int i = 1;
        while(i < SIZE){
            int newIndex = (index + i) % SIZE;
            if(table[newIndex] == -1){
                table[newIndex] = key;
                return;
            }
            i++;
        }
    }

    cout << "Hash Table is full. Cannot insert the key: " << key << endl;
}

void HashTable::display(){
    cout << "\n===== HASHTABLE =====\n";
    for(int i = 0; i < SIZE; i++){
        cout << "Index " << i << " -> ";
        if(table[i] != -1)
            cout << table[i] << endl;
        else
            cout << "Empty" << endl;
    }
}

int main(){
    HashTable ht;
    int totalKeys, key;

    cout << "Enter number of keys to insert: ";
    cin >> totalKeys;

    for(int i = 0; i < totalKeys; i++){
        cout << "Enter key #" << (i + 1) << " : ";
        cin >> key;
        ht.insert(key);
    }

    ht.display();

    return 0;
}
