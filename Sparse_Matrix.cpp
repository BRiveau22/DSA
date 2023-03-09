#include "Sparse_Matrix.h"

Sparse_Matrix::Sparse_Matrix() {
	this->rows = 0;
	this->cols = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

Sparse_Matrix::Sparse_Matrix(std::vector<std::vector<int>> matrix) {
	this->rows = matrix.size();
	this->cols = matrix[0].size();
	this->head = new Node(0, 0, matrix[0][0]);
	this->tail = new Node(matrix.size() - 1, matrix[matrix.size() - 1].size() - 1, matrix[matrix.size() - 1][matrix[matrix.size() - 1].size() - 1]);
}