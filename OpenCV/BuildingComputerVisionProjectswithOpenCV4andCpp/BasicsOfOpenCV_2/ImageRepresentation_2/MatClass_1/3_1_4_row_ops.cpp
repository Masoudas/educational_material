/**
 * So far, we've only generated views of submatrices. Particularly, we can use row or column method to for example
 * generate a new row or column and perform operations on that particular row or column, as we can see below.
 * 
 * The question that may arise here is that can we assign one row to another? Consider the following operation:
 * 
 
   Mat A;
   A.row(i) = A.row(j);
  
 * In this piece of code, we create a new header both on the left and right, and then assign them to one another.
 * Recall that data is shared, whereas header is assigned. In this schema, we say that the left object points to
 * the data on right. However, notice that the actual row(i) has not been assigned in this schema (it's still the
 * same in the original matrix.) Consequently, row 'i' remains unchanged after this operation.
 * 
 * How can we remedy this? We have two solutions:
 *      (1) A.row(i) = A.row(j) + 0;    // Here, a new data object is generated, which is then reassigned to row
 *                                      // j, but it's rather awkward!
 * 
 *      (2) A.row(j).copyTo(A.row(i));  // Copy row j to row i.
 * 
 * Of course, we should know that the same story goes for columns.
 * 
 * Note: This is not python! Have some decorum. You can't simply say A.col(j).copyTo(A.row(i)) to copy column j
 * to row i, even if both have the same number of elements.
 */

#include <opencv2/core.hpp>
#include <iostream>

void row_or_col_ops(cv::Mat& m1){
    auto r1 = m1.row(1);
    r1 = r1 * 5;    // Multiply by 5 and reassign.

    auto c1 = m1.col(1);
    c1 = c1 + 2;    // Add 2 to the column.  
}

void legitimate_reassignment_of_rows(cv::Mat& m, int r, int r_o, int alpha){
    m.row(r) = m.row(r_o) * alpha;  // A new data instance is generated.

    std::cout << "The original row was: " << m.row(r_o);
    std::cout << "\n The changed reassigned row is: " << m.row(r_o);

    // An equivalent implementation.
    m.row(r_o) *= 2;
    m.row(r_o).copyTo(m.row(r));
}

void copy_rows(cv::Mat& m){
    CV_Assert_1(m.rows == m.cols);    // Error! Not a sqaure matrix. Throw at debug time!

    std::cout << "\nThe original matrix is: \n"; 
    std::cout << m;

    // m.row(0) = m.row(1); // Subtle error. Row i remains unchanged.
    m.row(0).copyTo(m.row(1));     // Fine.

    std::cout << "\nAfter replacing row 1 with row 0, the matrix is: \n"; 
    std::cout << m << '\n';
}

//int main(){
    //cv::Mat m(2, 2, CV_8S, cv::Scalar{0,0,255});
    //m.at<schar>(0, 0) = 1; m.at<schar>(0,1) = 1;   // schar is among the typedifs of opencv
    //copy_rows(m);
//}