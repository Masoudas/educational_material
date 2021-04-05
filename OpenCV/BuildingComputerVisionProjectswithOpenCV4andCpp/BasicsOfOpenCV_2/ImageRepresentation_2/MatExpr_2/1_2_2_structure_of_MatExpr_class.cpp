/**
 * The MatExpr class has the following methods and constructors. Most of these resemble those of the Mat class,
 * hence, we only consider the other important ones. First, however, note the name of the attributes of the class:
 *
 *  Note: Alhamdolellah, it appears that OpenCV is smart enough to satureate the result of operations. Hence, if
 *        I use mul to multiply to unsigned char matrices, then 127*127 would be 127.
 *      
 *      Fields:
 *      -   Mat a;  double alpha;  Mat b;  double beta;   Mat c;  
 *          Me: So each input matrix a or b can be supplied with a scalar factor alpha or beta.
 *      
 *      -   int flags;  const MatOp* op;   Scalar s
 *          Me: The pointer points to the operation to be performed, and flags are the possible flags of that op,
 *          like the decomposition method for inversion.
 * 
 *      Methods:
 *      -   MatExpr ()
 *      -   MatExpr (const Mat &m)
 *      -   MatExpr (const MatOp *_op, int _flags, const Mat &_a=Mat(), const Mat &_b=Mat(), const Mat &_c=Mat(), 
 *                   double _alpha=1, double _beta=1, const Scalar &_s=Scalar())
 *          Me: Supply an operation together with matrices A, B and result matrix C.
 *      -   MatExpr 	col(int x) const
 *      -   Mat 	cross(const Mat &m) const
 *      -   MatExpr 	diag(int d=0) const
 *      -   double 	dot(const Mat &m) const
 *      -   MatExpr inv(int method=DECOMP_LU) const
 *      -   MatExpr mul(const MatExpr &e, double scale=1) const
 *      -   MatExpr mul(const Mat &m, double scale=1) const
 *      -   operator Mat() const    
 *          Me: The famous cast operator, which as we can see is constant. It generates a new matrix instance 
 *          each time we cast to a mat.
 *      -   template<typename _Tp >	operator Mat_< _Tp >() const
 *          Me: Cast to a new mat of different matrix type.
 *      -   MatExpr operator() (const Range &rowRange, const Range &colRange) const
 *      -   MatExpr operator() (const Rect &roi) const
 *      -   MatExpr row(int y) const
 *      -   Size size() const
 *      -   void swap(MatExpr &b)
 *      -   MatExpr t() const
 *      -   int type() const
 *
 * Note: Based on the above description, we can either generate a new MatExpr from a matrix, and then work with it
 * to generate new expressions, or we can freely mix MatExpr instances with Mats.
 *
 */