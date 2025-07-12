#include <iostream>
using namespace std;

class Node {
public:
    int marks;
    Node* prev;
    Node* next;

    Node(int m) {
        marks = m;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insert(int marks) {
        Node* newNode = new Node(marks);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void sort() {
        if (!head || !head->next) return;

        for (Node* i = head; i != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->marks > j->marks) {
                    swap(i->marks, j->marks);
                }
            }
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->marks << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }

    static DoublyLinkedList mergeSorted(DoublyLinkedList& l1, DoublyLinkedList& l2) {
        DoublyLinkedList mergedList;
        Node* p1 = l1.getHead();
        Node* p2 = l2.getHead();

        while (p1 && p2) {
            if (p1->marks <= p2->marks) {
                mergedList.insert(p1->marks);
                p1 = p1->next;
            } else {
                mergedList.insert(p2->marks);
                p2 = p2->next;
            }
        }

        while (p1) {
            mergedList.insert(p1->marks);
            p1 = p1->next;
        }

        while (p2) {
            mergedList.insert(p2->marks);
            p2 = p2->next;
        }

        return mergedList;
    }
};

int main() {
    DoublyLinkedList list1, list2, mergedList;
    int choice, marks;

    do {
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

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter marks to insert into List 1: ";
                cin >> marks;
                list1.insert(marks);
                break;

            case 2:
                cout << "Enter marks to insert into List 2: ";
                cin >> marks;
                list2.insert(marks);
                break;

            case 3:
                list1.sort();
                cout << "List 1 sorted.\n";
                break;

            case 4:
                list2.sort();
                cout << "List 2 sorted.\n";
                break;

            case 5:
                cout << "List 1: ";
                list1.display();
                cout << "List 2: ";
                list2.display();
                break;

            case 6:
                list1.sort();
                list2.sort();
                mergedList = DoublyLinkedList::mergeSorted(list1, list2);
                cout << "Lists merged successfully.\n";
                break;

            case 7:
                cout << "Merged List: ";
                mergedList.display();
                break;

            case 8:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
