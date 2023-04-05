#include "Node.h"

Node::Node() {
    this->row = 0;
    this->col = 0;
    this->val = 0;
    this->next = nullptr;
}

Node::Node(int row, int col, int val) {
    this->row = row;
    this->col = col;
    this->val = val;
    this->next = nullptr;
}


Node::Node(int row, int col, int val, Node *next) {
    this->row = row;
    this->col = col;
    this->val = val;
    this->next = next;
}

Node::~Node() {
    if(this->next != nullptr){
        delete this->next;
    }
}

int Node::get_val(){
    return this->val;
};

int Node::get_col(){
    return this->col;
};

Node* Node::get_next(){
    return this->next;
};