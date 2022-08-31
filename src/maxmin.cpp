#include <Rcpp.h>
using namespace Rcpp;
using namespace std;
//' Función para obtener el maxmimo de los minimos valores entre
//' las columna de una matriz y las filas de otra matriz, ambas cuadraticas
//'
//' @param NumericMatriz de tipo nxn.
//' @param NumericMatriz de tipo nxn.
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
//'#y B es
//'#     [,1] [,2] [,3]
//'#[1,]  1.0  0.7  0.9
//'#[2,]  1.0  1.0  0.2
//'#[3,]  0.5  0.1  1.0
//'
//'
//' maxmin_cpp(A,B)
//' #Da como resultado
//'#      [,1] [,2] [,3]
//'#[1,]  1.0  0.9  0.9
//'#[2,]  1.0  1.0  0.9
//'#[3,]  0.5  0.4  1.0
//'
// [[Rcpp::export]]
NumericMatrix maxmin_cpp(NumericMatrix matrix_1, NumericMatrix matrix_2)
{
    int n = matrix_1.nrow();
    int m = matrix_1.ncol();
    int l = matrix_2.ncol();
    NumericMatrix matrix_3(n, l);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            NumericVector vector_1;
            for (int k = 0; k < m; k++)
            {
                vector_1.push_back(min(matrix_1(i, k), matrix_2(k, j)));
            }
            matrix_3(i, j) = max(vector_1);
        }
    }
    return matrix_3;
}
