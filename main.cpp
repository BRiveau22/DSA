#include "Sparse_Matrix.h"

int main(int argc, char* argv[]) {
	std::vector<std::vector<int>> matrix1(2, std::vector<int>(2, 1));
	std::vector<std::vector<int>> matrix2(4, std::vector<int>(4, 3));

	Sparse_Matrix working_matrix(matrix1);
	Sparse_Matrix operating_matrix(matrix2);

	Sparse_Matrix out_matrix = working_matrix.add(operating_matrix);
	out_matrix.print_matrix();
}