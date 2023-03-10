#include "Node.h"

Node::Node() {
    this->row = 0;
    this->col = 0;
    this->val = 0;
    this->prev = nullptr;
    this->next = nullptr;
}

Node::Node(int row, int col, int val) {
    this->row = row;
    this->col = col;
    this->val = val;
    this->next = nullptr;
    this->prev = nullptr;
}

Node::Node(int row, int col, int val, Node* prev) {
    this->row = row;
    this->col = col;
    this->val = val;
    this->prev = prev;
    this->next = nullptr;
}

Node::Node(int row, int col, int val, Node *prev, Node *next) {
    this->row = row;
    this->col = col;
    this->val = val;
    this->prev = prev;
    this->next = next;
}

Node::~Node() {
    if(this->next != nullptr){
        delete this->next;
        delete this->prev;
    }
}
