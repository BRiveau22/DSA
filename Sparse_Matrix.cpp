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

	this->tail = current_node->prev;
	this->head->prev = this->tail;
	this->tail->next = this->head;
}