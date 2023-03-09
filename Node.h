//
// Created by PC on 3/9/2023.
//

#ifndef DSA_NODE_H
#define DSA_NODE_H


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
};


#endif //DSA_NODE_H
