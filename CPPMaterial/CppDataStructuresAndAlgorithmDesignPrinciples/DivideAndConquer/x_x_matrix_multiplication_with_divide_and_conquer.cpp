/**
* Question: It's been said that we better use divide and conquer to multiple two matrices. How does this help?
* This is because one has to after all go over the entire matrix and multiply them, so a for loop has to do so.
* 
* Well, for one thing, if we break down the multiplication operation into small chunks, we can use the cache to
* multiply elements properly. The other is the possibility of reducing the order by clever manipulations of divided
* elements, as we shall discuss below.
* 
* Note that a normal multiplication algorithm is as follows (for matrices A*B=C of size n):
* for i in n:	// over matrix A
*	for j in n:	// over matrix C
*		for k in n:	// Over matrix B
*			Let sum = sum + a[i][k]*b[k][j]
*		set c[i][j] = sum
* 
* Clearly, the computational complexity of this algorithm is O(n^3). 
* 
* Now, assuming the cache alignemnt is either row major or column major, we can improve this algorithm to reduce the
* number of cache misshes. If we want to consider that, we need to tile the matrices, and then multiply each 
* submatrix. The implementation for row major cache systems is to tile in matrices of size sqrt(M), then multiply
* each tile, and add the result in the previous tile.
* 
* Now consider, breaking down A and B into four equal parts. Calling these Aij,Bij,Cij for A, B and C respectively.
* We can use a recrusive algorith to keep on tiling, and then add the results of tiling to get the matrix. Now,
* we can compute the computational burden as follows:
* For each part, we need to compute 2 multiplications of size n/2. Then, we have a an addition of size n/2 to add
* the results of multiplcations together. Let's call the computational burden of multiplication T(n), we have that:
* T(n) = 8 * T(n/2) + 4 * O(n^2/2) = 8 * T(n/2) + O(n^2). If we solve this relation for T, we would see that we 
* have a computational complexity of O(n^3) once again! This method is called Master's theorem.
* 
* Now, the third option is to introduce some trickery to reduce the 8 factor in the above equation. This is known
* as Strassen's theorem, and what he does is to define p1 to p7 polynomials, and then for example C11 = p5+p4-p2+p6
* where for example p1 = A11(B12 - B22) and so forth. In this scheme, the computational formula is written as
* T(n) = 7 * T(n/2) + O(n^2), and we can show that T(n) = O(n^log7). Consequently, the computational burden has
* decreased compared to the original recursive method.
* 
* In application however, we prefer to use parallelization to improve the speed.
*/