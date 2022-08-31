#include <Rcpp.h>
using namespace Rcpp;
using namespace std;
//' Función para unir una matriz con un vector y que este ultimo quede
//' en la ultima columna de la matriz.
//' @param NumericMatriz de tipo nxm.
//' @param NumericVector de largo n.
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
//' B<- c(1, 2, 3)
//' #Donde A es
//'#      [,1] [,2] [,3]
//'#[1,]  1.0  0.9  0.5
//'#[2,]  0.8  1.0  0.9
//'#[3,]  0.4  0.0  1.0
//'
//'
//' cbind_rcpp(A,B)
//' #Da como resultado
//'#      [,1] [,2] [,3] [,4]
//'#[1,]  1.0  0.9  0.9     1
//'#[2,]  1.0  1.0  0.9     2
//'#[3,]  0.5  0.4  1.0     3
//'
// [[Rcpp::export]]
NumericMatrix cbind_rcpp(NumericMatrix matrix_1, NumericVector vector_1)
{
    int nrow_1 = matrix_1.nrow();
    int ncol_1 = matrix_1.ncol();
    int nrow_2 = vector_1.size();
    int ncol_2 = 1;
    NumericMatrix matrix_2(nrow_1, ncol_1 + ncol_2);
    for (int i = 0; i < nrow_1; i++)
    {
        for (int j = 0; j < ncol_1; j++)
        {
            matrix_2(i, j) = matrix_1(i, j);
        }
    }

    for (int i = 0; i < nrow_2; i++)
    {
        matrix_2(i, nrow_2) = vector_1(i);
    }
    return matrix_2;
}
