/**Name: Ralph Arvin De Castro
***Student ID: 0923223
***Course: CIS*2910***/

/***This is C file. Please compile it with the input data (input-graphs.txt) in the same directory***/

#include <stdio.h>
#include <stdlib.h>

/*Sorts an integer array in an ascending order*/
void sortArray(int length, int* array);

/*Prints an integer array*/
void printArray(int length, int* array);

/*Put values in a matrix from file*/
void populateMatrix(int length, int matrix[length][length], FILE *fp);

/*Determine the degree sequences of the matrix*/
void findDegreeSeq(int length, int matrix[length][length],int * array);

/*Compare two degree sequences and check if they are equal*/
void compareDegreeSeqs(int length, int *array1, int * array2);

void sortArray(int length, int* array)
{
  int a, i ,j;

  for(i = 0; i < length; i++)
  {
    for (j = i + 1; j < length; ++j)
    {
      if (array[i] > array[j])
      {
        a =  array[i];
        array[i] = array[j];
        array[j] = a;
      }
    }
  }
}

void printArray(int length, int* array)
{
  int i;
  for(i = 0; i < length; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void populateMatrix(int length, int matrix[length][length], FILE *fp)
{
  char line[256];
  int i = 0;
  for(i = 0; i < length; i++)
  {
    fgets(line, sizeof(line), fp);

    int j = 0;
    int k = 0;
    for(j = 0; j < length; j++)
    {
      matrix[i][j] = (int)line[k] - 48;
      k = k + 2;
    }
  }

}

void findDegreeSeq(int length, int matrix[length][length],int * array)
{
  int mRow;
  int mCol;
  for(mRow = 0; mRow< length; mRow ++)
  {
    array[mRow] = 0;
    for(mCol= 0; mCol < length; mCol++)
    {
      if(matrix[mRow][mCol] == 1)
      {
        array[mRow]++;
      }
    }
  }
}

void compareDegreeSeqs(int length, int *array1, int * array2)
{
  int i = 0;
  for(i = 0; i < length; i++)
  {
      if(array1[i] != array2[i])
      {
          printf("The graphs do NOT have the same degree sequence.\n\n");
          return;
      }
  }
  printf("The graphs do have the same degree sequence and might be isomorphic.\n\n");
}


int main()
{
  FILE *fp;
  fp = fopen("input-graphs.txt", "r");
  char line[256];
  int currentMatrix = 0;

  while (!feof(fp))
  {
    int counter ;

    /*Matrix 1*/
    fscanf (fp, "%d", &counter); /*Read size of matrix 1*/
    fgets(line, sizeof(line), fp);
    if(feof(fp)){
      break;
    }
    int matrix1[counter][counter];    /*Initialize matrix1 and degree sequence*/
    int degreeSeq1[counter];
    populateMatrix(counter, matrix1 ,fp);    /*Populate matrix 1*/
    findDegreeSeq(counter,matrix1, degreeSeq1);
    sortArray(counter, degreeSeq1);
    printf("Degree seq for G1: ");
    printArray(counter, degreeSeq1);

    /*Matrix 2*/
    fscanf (fp, "%d", &counter);
    fgets(line, sizeof(line), fp);
    int matrix2[counter][counter];
    int degreeSeq2[counter];
    populateMatrix(counter, matrix2 ,fp);
    findDegreeSeq(counter,matrix2, degreeSeq2);
    sortArray(counter, degreeSeq2);
    printf("Degree seq for G2: ");
    printArray(counter, degreeSeq2);

    //Compare two degree sequences
    compareDegreeSeqs(counter, degreeSeq1, degreeSeq2);

  }
  fclose(fp);

  return 0;
}
