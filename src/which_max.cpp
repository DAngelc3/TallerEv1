#include <Rcpp.h>
using namespace Rcpp;
using namespace std;
//' Función para encontrar el o los máximos valores de una matrix, esta retorna en un data frame las posiciones (las posiciones estan pensadas para comenzar desde 1 como funciona en R).
//' @param NumericMatriz de tipo mxn.
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
//' #Donde A es
//'#      [,1] [,2] [,3]
//'#[1,]  1.0  0.9  0.5
//'#[2,]  0.8  1.0  0.9
//'#[3,]  0.4  0.0  1.0
//'
//'
//' wich_max_rcpp(A)
//' #Da como resultado
//'#  pos_max_fila pos_max_columna
//'#1            1               1
//'#2            2               2
//'#3            3               3
//'
// [[Rcpp::export]]
DataFrame wich_max_rcpp(NumericMatrix matrix_1)
{
  int nrow_1 = matrix_1.nrow();
  int ncol_1 = matrix_1.ncol();
  NumericVector pos_max_i;
  NumericVector pos_max_j;
  float max_1 = matrix_1(0,0);

  for (int i = 0; i < nrow_1; i++)
  {
    for (int j = 0; j < ncol_1; j++)
    {
      if (matrix_1(i, j) >= max_1)
      {
        max_1 = matrix_1(i, j);
      }
    }
  }

  for (int i = 0; i < nrow_1; i++)
  {
    for (int j = 0; j < ncol_1; j++)
    {
      if (matrix_1(i, j) >= max_1)
      {
        pos_max_i.push_back(i+1);
        pos_max_j.push_back(j+1);
      }
    }
  }
  DataFrame df_min = DataFrame::create(
    _["pos_max_fila"] = pos_max_i,
    _["pos_max_columna"] = pos_max_j);
  return df_min;
}
