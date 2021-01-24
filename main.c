#include <stdio.h>
#include <stdlib.h>

int sign(int x) {
    return (x > 0) - (x < 0);
}

int getNRows(int nRows)
{
  do
  {
    printf("give the number of rows \n");
    scanf("%d",&nRows);
  } while(nRows % 2 != 0);
  return nRows;
}

int getNCols(int nCol)
{
    printf("give the number of columns \n");
    scanf("%d",&nCol);
    return nCol;
}

int ** scan(int nRows, int nCol)
{
  int i;
  i = 0;
  int **matrix = malloc(nRows * sizeof(int *));
	matrix[0] = malloc(nRows * nCol * sizeof(int));
	for(i = 1; i < nRows; i++)
		matrix[i] = matrix[0] + i * nCol;
  // scan matrix values
  int j;

  for(i = 0; i < nRows-1; i++)
  {
    j = 0;
    printf("give the value of matrix[%d][%d]\n", i, j);
    scanf("%d", &matrix[i][j]);
    int signOf = sign(matrix[i][j]);
    while(j < nCol-1)
    {
      j ++;
      do
      {
        printf("give the value of matrix[%d][%d]\n", i, j);
        scanf("%d", &matrix[i][j]);
      } while(sign(matrix[i][j]) != signOf);
    }
  }
  return matrix;
}

char is_unimodal(int** matrix, int nRows, int nCol)
{
  int i = 0;
  int j = 0;
  char result = '1';
  while(i < nRows && result == '1')
  {
    while(j < (nCol-1) && result == '1')
    {
      printf("%d < %d: %d\n", matrix[i][j], matrix[i][j+1], matrix[i][j] < matrix[i][j+1]);
      printf("%d > %d: %d\n", matrix[i+1][j], matrix[i+1][j+1], matrix[i+1][j] > matrix[i+1][j+1]);
      if((matrix[i][j] > matrix[i][j+1]) || (matrix[i+1][j] < matrix[i+1][j+1]))
      {
        result = '0';
        return result;
      }
      j ++;
    }
    i += 2;
  }
  return '1';
}

int main()
{
  // init
  int nCol;
  int nRows;
  nRows = getNRows(nRows);
  nCol = getNCols(nCol);
  printf("Peace :D\n");
  int ** matrix = scan(nRows, nCol);
  char result = is_unimodal(matrix, nRows, nCol);
  if (result == '1')
  {
    printf("the matrix is unimodal");
  }
  else
  {
    printf("the matrix isn't unimodal");
  }
}