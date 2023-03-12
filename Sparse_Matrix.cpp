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
	//Determine whether or not mult_matrix has the same number of columns as this->matrix has rows
	//If there is a difference, assume adding zeroes to the matrix to make them match

	//Multiply every value in each row by every value in each column
	//Take the summation of the multiplied values for the given row and column
}

Sparse_Matrix Sparse_Matrix::add(Sparse_Matrix add_matrix) {
	//Adds the current matrix with add_matrix
	//Checks if the two matrices are the same order (size)
	//If there is a difference, assume adding zeroes to the matrix to make them match

	//Add the two values at the corresponding locations
}


Sparse_Matrix Sparse_Matrix::insert_row(int row, std::vector<int> new_row) {
	//Inserts a new row at the specified index (with indexes < 0 prepending 
	//the row, and indexes > num_rows appending the row)
	
	//Create node pointers for every value in new_row
	//Switch pointers from row before insertion index to the start value of new_row
	//Switch pointers from new_row to next_row

}

Sparse_Matrix Sparse_Matrix::insert_col(int col, std::vector<int> new_col) {
	//Inserts a new col at the specified index (with indexes < 0 prepending 
	//the col, and indexes > col appending the row)

	//Create node pointers for every value in new_col
	//Loop through every value in the Sparse_Matrix
	//When current_col is less than the insertion index, insert first value
	//Point to new value
	//Point from new value to next value
	//Repeat until all columns are filled
}