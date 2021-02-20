/**
* To represent a matrix using vector, we can use a vector of vectors. Notice the following steps for creating an
* n by m matrix:
*	1- We reserve n places for n rows in the matrix.
*	2- We create one vector of size m, using the two integer constructor of vector.
*	3- Now, we add this vector to matrix n times (the same vector), and because we're using the inherent copy
*	of the data, we're fine.
*   4- Alternatively, we can use the rvalue push_back method!
*/
#include <vector>
#include <algorithm>
using std::vector;

struct matrix {
	vector<vector<int>> data;

	matrix(int n, int m) {
		data.reserve(n);

		//vector<int> row_vec(m, 0);	// Initialize each row to zero.
		//for (int row = 0; row < n; row++) {
		//	data.push_back(row_vec);
		//}

		for (int row = 0; row < n; row++) {
			data.push_back(vector<int>(m,0));
		}
	}
};