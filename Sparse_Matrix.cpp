#include "Sparse_Matrix.h"

Sparse_Matrix::Sparse_Matrix() {
	this->rows = 0;
	this->cols = 0;
	this->head = nullptr;
	this->tail = nullptr;
	this->num_elements = 0;
}

Sparse_Matrix::Sparse_Matrix(std::vector<std::vector<int>> matrix) {
	Node* current_node = new Node();
	this->head = current_node;
	this->num_elements = 0;

	for (int y = 0; y < matrix.size(); y++) {
		for (int x = 0; x < matrix[y].size(); x++) {

			if (matrix[y][x] != 0) {
				current_node->row = y;
				current_node->col = x;
				current_node->val = matrix[y][x];
				this->num_elements++;
			}

			if (y == matrix.size() - 1 && x == matrix[y].size() - 1) {
				this->tail = current_node;
				this->rows = this->tail->row + 1;
				this->cols = this->tail->col + 1;
			}
			else {
				current_node->next = new Node();
				current_node = current_node->next;
			}
		}
	}
}

//Private Methods
std::pair<int, int> Sparse_Matrix::get_max_row_col(Sparse_Matrix other) {
	int max_row = 0;
	int max_col = 0;

	//Finds the max row and column of the two matrices
	if (other.rows > this->rows) {
		max_row = other.rows;
	}
	else {
		max_row = this->rows;
	}
	if (other.cols > this->cols) {
		max_col = other.cols;
	}
	else {
		max_col = this->cols;
	}

	return { max_row, max_col };
}

std::vector<std::vector<int>> Sparse_Matrix::add(Sparse_Matrix longer, Sparse_Matrix shorter, int max_row, int max_col) {
	std::vector<std::vector<int>> new_matrix(max_row, std::vector<int>(max_col, 0));
	Node* current_node_longer = longer.head;
	Node* current_node_shorter = shorter.head;

	while (current_node_longer != nullptr) {
		new_matrix[current_node_longer->row][current_node_longer->col] += current_node_longer->val;
		current_node_longer = current_node_longer->next;
	}

	while (current_node_shorter != nullptr) {
		new_matrix[current_node_shorter->row][current_node_shorter->col] += current_node_shorter->val;
		current_node_shorter = current_node_shorter->next;
	}

	return new_matrix;
}

std::vector<std::vector<int>> Sparse_Matrix::multiply(Sparse_Matrix first, Sparse_Matrix second) {
	std::vector<std::vector<int>> new_matrix(first.rows, std::vector<int>(second.cols, 0));
	Node* current_node1 = first.head;
	Node* current_node2 = second.head;

	while (current_node1 != nullptr) {
		while (current_node2 != nullptr) {
			if (current_node1->col == current_node2->row) {
				new_matrix[current_node1->row][current_node2->col] += current_node1->val * current_node2->val;
			}
			current_node2 = current_node2->next;
		}
		current_node1 = current_node1->next;
		current_node2 = second.head;
	}

	return new_matrix;
}

//Public Methods
Sparse_Matrix Sparse_Matrix::add(Sparse_Matrix add_matrix) {
	std::pair<int, int> extremes = this->get_max_row_col(add_matrix);
	int max_row = extremes.first;
	int max_col = extremes.second;

	//Creates a new 2D vector with the max row and column
	std::vector<std::vector<int>> new_matrix;

	//Reassigns the new matrix to the sum of the two matrices
	if (this->num_elements > add_matrix.num_elements) {
		new_matrix = this->add(*this, add_matrix, max_row, max_col);
	}
	else {
		new_matrix = this->add(add_matrix, *this, max_row, max_col);
	}

	//Creates a sparse matrix from the new matrix
	Sparse_Matrix out_matrix = Sparse_Matrix(new_matrix);
	return out_matrix;
}

Sparse_Matrix Sparse_Matrix::multiply(Sparse_Matrix mult_matrix) {
	std::pair<int, int> extremes = this->get_max_row_col(mult_matrix);
	int max_row = extremes.first;
	int max_col = extremes.second;

	//Creates a new 2D vector with the max row and column
	std::vector<std::vector<int>> new_matrix;

	//Reassigns the new matrix to the product of the two matrices
	new_matrix = this->multiply(*this, mult_matrix);

	//Creates a sparse matrix from the new matrix
	Sparse_Matrix out_matrix = Sparse_Matrix(new_matrix);
	return out_matrix;
}

/*Sparse_Matrix Sparse_Matrix::insert_row(int row, std::vector<int> new_row) {
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
}*/

void Sparse_Matrix::print_matrix() {
	Node* current_node = this->head;

	while (current_node != nullptr) {
		std::cout << current_node->val << " ";

		if (current_node->next != nullptr && current_node->next->row != current_node->row) {
			std::cout << "\n";
		}
		current_node = current_node->next;
	}
}