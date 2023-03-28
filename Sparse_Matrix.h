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
	void decrement(std::string row_col, bool decrement);
	std::vector<std::vector<int>> add(Sparse_Matrix longer, Sparse_Matrix shorter, int max_row, int max_col);
	std::vector<std::vector<int>> multiply(Sparse_Matrix longer, Sparse_Matrix shorter);
	std::pair<int, int> get_max_row_col(Sparse_Matrix other);
public:
	Sparse_Matrix();
	Sparse_Matrix(std::vector<std::vector<int>> matrix);
	Sparse_Matrix multiply(Sparse_Matrix mult_matrix);
	Sparse_Matrix add(Sparse_Matrix add_matrix);
	Sparse_Matrix insert_row(int row, std::vector<int> new_row);
	Sparse_Matrix insert_col(int col, std::vector<int> new_col);
	void print_matrix();
};