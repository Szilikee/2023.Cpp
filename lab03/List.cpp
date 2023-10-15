//
// Created by Szilikee on 2023. 10. 15..
//

#include <iostream>
#include "List.h"
using namespace std;

List::List() {
    cout << "Konstruktor meghivva." << endl;
    first = nullptr;
    nodeCounter = 0;
}

List::~List() {
    cout << "Destruktor meghivva." << endl;
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}

bool List::exists(int d) const {
    // Megvizsgálja, hogy d benne van-e a listában
    Node* current = first;
    while (current != nullptr) {
        if (current->value == d) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    return nodeCounter == 0;
}

void List::insertFirst(int d) {
    Node* newNode = new Node(d, first);
    first = newNode;
    nodeCounter++;
}

int List::removeFirst() {
    if (empty()) {
        throw std::runtime_error("A lista ures, nincs amit eltavolitani!");
    }
    Node* oldFirst = first;
    first = first->next;
    int value = oldFirst->value;
    delete oldFirst;
    nodeCounter--;
    return value;
}

void List::remove(int d, DeleteFlag df) {
    Node* current = first;
    Node* prev = nullptr;

    while (current != nullptr) {
        bool remove = false;
        if (df == DeleteFlag::LESS && current->value < d) {
            remove = true;
        } else if (df == DeleteFlag::EQUAL && current->value == d) {
            remove = true;
        } else if (df == DeleteFlag::GREATER && current->value > d) {
            remove = true;
        }

        if (remove) {
            if (prev == nullptr) {
                first = current->next;
            } else {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            delete temp;
            nodeCounter--;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void List::print() const {
    Node* current = first;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
