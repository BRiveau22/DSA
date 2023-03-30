#include "Node.h"
#include <vector>
#include <string>
#include<iostream>

#pragma once
class Sparse_Matrix {
private:
	int rows;
	int cols;
	Node* head;
	Node* tail;
	int num_elements;
	std::vector<std::vector<int>> add(Sparse_Matrix longer, Sparse_Matrix shorter, int max_row, int max_col);
	std::vector<std::vector<int>> multiply(Sparse_Matrix first, Sparse_Matrix second);
	std::pair<int, int> get_max_row_col(Sparse_Matrix other);
public:
	Sparse_Matrix();
	Sparse_Matrix(std::vector<std::vector<int>> matrix);
	Sparse_Matrix multiply(Sparse_Matrix mult_matrix);
    Sparse_Matrix add(Sparse_Matrix add_matrix);
	void insert(int row, int col, int val);
	void print_matrix();
    Node* getHead();

};