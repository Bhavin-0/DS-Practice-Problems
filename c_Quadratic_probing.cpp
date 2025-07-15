#include <iostream>
using namespace std;

const int TABLE_SIZE = 11;

class HashTable {
private:
    int table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = -1;
    }

    void insert(int key) {
        int index = key % TABLE_SIZE;
        int i = 0;
        while (table[(index + i*i) % TABLE_SIZE] != -1) {
            i++;
            if (i == TABLE_SIZE) {
                cout << "Hash table is full!\n";
                return;
            }
        }
        table[(index + i*i) % TABLE_SIZE] = key;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++)
            cout << i << " --> " << (table[i] == -1 ? -1 : table[i]) << endl;
    }
};

int main() {
    HashTable ht;
    int mangoes[] = {25,15,10,5,11,19,16,36,42,28,32};
    for (int i = 0; i < 11; i++)
        ht.insert(mangoes[i]);
    ht.display();
    return 0;
}