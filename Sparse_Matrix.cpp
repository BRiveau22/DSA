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
	this->rows = 0;
	this->cols = 0;

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
			}

			if (current_node->row > this->rows) {
				this->rows = current_node->row;
			}
			if (current_node->col > this->cols) {
				this->cols = current_node->col;
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
	std::vector<std::vector<int>> new_matrix(max_row+1, std::vector<int>(max_col+1, 0));
	Node* current_node_first = longer.head;
	Node* current_node_second = shorter.head;

	while (current_node_first != nullptr) {
		new_matrix[current_node_first->row][current_node_first->col] += current_node_first->val;
		current_node_first = current_node_first->next;
	}

	while (current_node_second != nullptr) {
		new_matrix[current_node_second->row][current_node_second->col] += current_node_second->val;
		current_node_second = current_node_second->next;
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
	if (this->num_elements >= add_matrix.num_elements) {
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

	//Creates a new 2D vector with the max row and column
	std::vector<std::vector<int>> new_matrix;

	//Reassigns the new matrix to the product of the two matrices
	new_matrix = this->multiply(*this, mult_matrix);

	//Creates a sparse matrix from the new matrix
	Sparse_Matrix out_matrix = Sparse_Matrix(new_matrix);
	return out_matrix;
}

void Sparse_Matrix::insert(int row, int col, int val) {
	Node* current_node = this->head;

	while (current_node->next != nullptr) {
		//Handles the case where the node is inserted in the middle
		if (current_node->next->row > row || (current_node->next->row == row && current_node->next->col > col)) {
			current_node->next = new Node(row, col, val, current_node->next);
			this->num_elements++;
		}
		//Handles the case where the node is inserted in the middle and the location is the same
		else if (current_node->next->row == row && current_node->next->col == col) {
			current_node->next->val = val;
		}
		current_node = current_node->next;
	}

	//Handles the case where the node is inserted at the tail or the head of an otherwise empty matrix
	if (current_node->next == nullptr && (current_node->row <= row || (current_node->row == row && current_node->col < col))) {
		current_node->next = new Node(row, col, val);
		this->num_elements++;
	}
	//Handles the case where the node is inserted at the head of an otherwise empty matrix
	else if (current_node == this->head && current_node->next == nullptr && (current_node->row > row || (current_node->row == row && current_node->col > col))) {
		Node* new_node = new Node(row, col, val, current_node);
		this->head = new_node;
		this->num_elements++;
	}
	//Handles the case where the node is inserted at the tail, or the head of an otherwise empty matrix and the location is the same
	else if (current_node->next == nullptr && current_node->row == row && current_node->col == col) {
		current_node->val = val;
	}
}

void Sparse_Matrix::print_matrix() {
	Node* current_node = this->head;

	while (current_node != nullptr) {
        if(current_node->val != 0){
            std::cout << current_node->val << " ";
        }


		if (current_node->next != nullptr && current_node->next->row != current_node->row) {
			std::cout << "\n";
		}
		current_node = current_node->next;
	}
}

Node* Sparse_Matrix::get_head(){
    return this->head;
};

