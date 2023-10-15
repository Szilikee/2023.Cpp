//
// Created by Szilikee on 2023. 10. 15..
//
#include <stdexcept>
#include "List.h"

class Stack {
public:
    Stack() : list() {
    }

    void push(int e) {
        list.insertFirst(e);
    }

    int pop() {
        if (isEmpty()) {
            throw std::runtime_error("A verem ures!");
        }
        return list.removeFirst();
    }

    bool isEmpty() const {
        return list.empty();
    }

private:
    List list;
};