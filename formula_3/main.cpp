#include <iostream>
#include <vector>
#include <cmath>


std::vector<int> get_vector(std::string title, char separator = ' ', char end = ';') {

	std::cout << title;

	std::string str;
	std::vector<int> vector;
	while ((std::getline(std::cin, str, separator) && str.back() != end)) {
		vector.push_back(std::atoi(str.c_str()));
	};
	return (vector);

};


std::vector<std::vector<int>> get_matrix(std::vector<int> vector) {

	std::vector<std::vector<int>> matrix;
	for (int n = 0; n < vector.size() - 1; n++) {
		matrix.push_back({});
		for (auto el : vector) {
			matrix.back().push_back(pow(el, n));
		};
	};
	return (matrix);

};


void print_matrix(std::vector<std::vector<int>> matrix) {

	for (unsigned int i = 0; i < matrix.size(); i++) {
		std::cout << "│ ";
		for (unsigned int n = 0; n < matrix[i].size(); n++) {
			std::vector<int> line;
			for (unsigned int t = 0; t < matrix.size(); t++) {
				line.push_back(matrix[t][n]);
			};

			int max = std::to_string(
				line[
					std::distance(
					line.begin(),
					std::max_element(
						line.begin(),
						line.end()))
					]
				).size();

			std::cout << matrix[i][n];
			unsigned int el_len = std::to_string(matrix[i][n]).size();
			while (el_len <= max) {
				std::cout << ' ';
				el_len++;
			};
		};
		std::cout << "│" << '\n';
	};

};


int main() {

	std::cout << "│ x1:1^(n-1) x1:2^(n-1) x1:3^(n-1) ... x1:n^(n-1) │" << '\n';
	std::cout << "│ ·                                               │" << '\n';
	std::cout << "│ ·                                               │" << '\n';
	std::cout << "│ ·                                               │" << '\n';
	std::cout << "│ xm:1^(n-1) xm:2^(n-1) xm:3^(n-1) ... xm:n^(n-1) │" << '\n';
	std::cout << '\n';
	std::cout << "example vector: 1, 2, ... n ;(space)" << '\n';
	std::cout << '\n';

	auto vector = get_vector("enter vector: ", ' ', ';');
	auto matrix = get_matrix(vector);
	print_matrix(matrix);

	return (0);

};
