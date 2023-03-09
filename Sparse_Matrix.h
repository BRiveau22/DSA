#include "Node.h"
#include <vector>
#include <string>

#pragma once
class Sparse_Matrix {
private:
	int rows;
	int cols;
	Node* head;
	Node* tail;
	void decrement(std::string row_col, bool decrement);
public:
	Sparse_Matrix();
	Sparse_Matrix(std::vector<std::vector<int>> matrix);
	Sparse_Matrix multiply(Sparse_Matrix mult_matrix);
	Sparse_Matrix add(Sparse_Matrix add_matrix);
	Sparse_Matrix insert_row(int row, std::vector<int> new_row);
	Sparse_Matrix insert_col(int col, std::vector<int> new_col);
};