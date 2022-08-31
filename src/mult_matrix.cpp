#include <Rcpp.h>
using namespace Rcpp;
using namespace std;
//' Función para realizar una multiplicacion matricial procesada en C++
//' @param NumericMatriz de tipo mxn.
//' @param NumericMatriz de tipo nxc.
//' @export
//' @examples
//' matriz_aleatoria <- function(n) {
//'matriz <- matrix(round(runif(n^2, 0, 1), 1), nrow = n, ncol = n)
//'  for (i in 1:n) {
//'    matriz[i, i] <- 1
//'  }
//'  return(matriz)
//'    }
//' set.seed(123)
//' A<- matrizAleatoria(3)
//' B<- matrizAleatoria(3)
//' #Donde A es
//'#      [,1] [,2] [,3]
//'#[1,]  1.0  0.9  0.5
//'#[2,]  0.8  1.0  0.9
//'#[3,]  0.4  0.0  1.0
//'
//'#Donde B es
//'#      [,1] [,2] [,3]
//'#[1,]  1.0  0.9  0.5
//'#[2,]  1.0  1.0  0.9
//'#[3,]  0.5  0.1  1.
//'
//'
//' mult_matrix_rcpp(A,B)
//' #Da como resultado
//'#      [,1] [,2] [,3]
//'#[1,]  2.15 1.65 1.58
//'#[2,]  2.25 1.65 1.82
//'#[3,]  0.90 0.38 1.36
//'
// [[Rcpp::export]]
NumericMatrix mult_matrix_rcpp(NumericMatrix matrix_1, NumericMatrix matrix_2)
{
    int nrow_1 = matrix_1.nrow();
    int ncol_1 = matrix_1.ncol();
    int nrow_2 = matrix_2.nrow();
    int ncol_2 = matrix_2.ncol();
    NumericMatrix matrix_3(nrow_1, ncol_2);
    if (ncol_1 == nrow_2){
      for (int i = 0; i < nrow_1; i++)
      {
        for (int j = 0; j < ncol_2; j++)
        {
          for (int k = 0; k < ncol_1; k++)
          {
            matrix_3(i, j) += matrix_1(i, k) * matrix_2(k, j);
          }
        }
      }
      return matrix_3;
    }
    else return EXIT_FAILURE;

}
