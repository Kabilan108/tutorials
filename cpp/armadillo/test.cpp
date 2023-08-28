// compile with g++ -o test.o test.cpp -larmadillo

#include <iostream>
#include <armadillo>

int main()
{
    // initialize matrix
    arma::mat A = arma::randu<arma::mat>(4, 4);
    A.print("A:");

    // determinant
    double det_A = arma::det(A);
    std::cout << "det(A): " << det_A << std::endl;

    // inverse
    arma::mat A_inv = arma::inv(A);
    A_inv.print("inv(A):");

    return 0;
}
