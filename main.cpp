#include<bits/stdc++.h>
using namespace std;

struct Node {
    int node_number;
    char name;
    Node* next_node;
};

void insert_alphabet(Node*& head, int node_number, char name) {
    Node* newNode = new Node;
    newNode->node_number = node_number;
    newNode->name = name;
    newNode->next_node = nullptr;

    if (!head || node_number < head->node_number) {
        newNode->next_node = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next_node && node_number >= current->next_node->node_number) {
            current = current->next_node;
        }
        newNode->next_node = current->next_node;
        current->next_node = newNode;
    }
}

void delete_alphabet(Node*& head, char name) {
    Node* current = head;
    Node* prev = nullptr;

    while (current && current->name != name) {
        prev = current;
        current = current->next_node;
    }

    if (current) {
        if (prev)
            prev->next_node = current->next_node;
        else
            head = current->next_node;
        delete current;
    }
}

Node* search_alphabet(Node* head, char name) {
    Node* current = head;
    while (current && current->name != name) {
        current = current->next_node;
    }
    return current;
}

void update_info(Node* head, char old_name, char new_name, int new_node_number) {
    Node* nodeToModify = search_alphabet(head, old_name);
    if (nodeToModify) {
        nodeToModify->name = new_name;
        nodeToModify->node_number = new_node_number;
    }
}

void display_name(Node* head) {
    Node* current = head;
    string name;
    while (current) {
        name += current->name;
        current = current->next_node;
    }
    cout << "Name: " << name << endl;
}

void delete_list(Node*& head) {
    Node* current = head;
    while (current) {
        Node* next = current->next_node;
        delete current;
        current = next;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;
    char choice;
    char name;
    int node_number;
    char old_name, new_name;
    bool loop = true;

    while (loop) {
        cout << "Choose an operation:" << endl;
        cout << "1. Insert an alphabet" << endl;
        cout << "2. Delete an alphabet" << endl;
        cout << "3. Search for an alphabet" << endl;
        cout << "4. Update node information" << endl;
        cout << "5. Display the name" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "Enter the alphabet: ";
            cin >> name;
            cout << "Enter the node number: ";
            cin >> node_number;
            insert_alphabet(head, node_number, name);
            break;

        case '2':
            cout << "Enter the alphabet to delete: ";
            cin >> name;
            delete_alphabet(head, name);
            break;

        case '3':
            cout << "Enter the alphabet to search: ";
            cin >> name;
            Node* foundNode = search_alphabet(head, name);
            if (foundNode)
                cout << "Character '" << name << "' found in Node number: " << foundNode->node_number << endl;
            else
                cout << "Character '" << name << "' not found in the list." << endl;
            break;

        case '4':
            cout << "Enter the alphabet to update: ";
            cin >> old_name;
            cout << "Enter the new alphabet: ";
            cin >> new_name;
            cout << "Enter the new node number: ";
            cin >> node_number;
            update_info(head, old_name, new_name, node_number);
            break;

        case '5':
            display_name(head);
            break;

        case '6':
            delete_list(head);
            loop = false;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}