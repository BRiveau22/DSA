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

	Node* current_node = this->head;
	for (int y = 0; y < matrix.size(); y++) {
		for (int x = 0; x < matrix[y].size(); x++) {
			current_node->next = new Node(y, x, matrix[y][x], current_node);
			current_node = current_node->next;
		}
	}

	//Sets the tail as well as updates prev and next for tail and head
	this->tail = current_node->prev;
	this->head->prev = this->tail;
	this->tail->next = this->head;
}

Sparse_Matrix Sparse_Matrix::multiply(Sparse_Matrix mult_matrix) {
	//Multiplies the current matrix by mult_matrix
}

Sparse_Matrix Sparse_Matrix::add(Sparse_Matrix add_matrix) {
	//Adds the current matrix with add_matrix
}


Sparse_Matrix Sparse_Matrix::insert_row(int row, std::vector<int> new_row) {
	//Inserts a new row at the specified index (with indexes < 0 prepending 
	//the row, and indexes > num_rows appending the row)
}

Sparse_Matrix Sparse_Matrix::insert_col(int col, std::vector<int> new_col) {
	//Inserts a new col at the specified index (with indexes < 0 prepending 
	//the col, and indexes > col appending the row)
}