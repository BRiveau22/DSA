#pragma once

class Node {
private:
    int row;
    int col;
    int val;
    Node* next;
    Node* prev;

public:
    Node();
    Node(int row,int col,int val);
    Node(int row,int col,int val,Node* prev,Node* next);
    ~Node();
};