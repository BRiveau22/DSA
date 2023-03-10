#pragma once

class Node {
private:
    int row;
    int col;
    int val;
    Node* next;
    Node* prev;

    friend class Sparse_Matrix;

public:
    Node();
    Node(int row,int col,int val);
    Node(int row, int col, int val, Node* prev);
    Node(int row,int col,int val,Node* prev,Node* next);
    ~Node();
};