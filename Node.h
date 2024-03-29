#pragma once

class Node {
private:
    int row;
    int col;
    int val;
    Node* next;

    friend class Sparse_Matrix;

public:
    Node();
    Node(int row,int col,int val);
    Node(int row,int col,int val,Node* next);
    ~Node();
    int get_val();
    int get_col();
    Node* get_next();
};