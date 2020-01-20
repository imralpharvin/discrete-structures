/*Name: Ralph Arvin De Castro
Student ID: 0923223
*/

#include <stdio.h>

//Create binary strings recursively and print them
void createBinaryStrings(int n, int arr[], int i)
{
    //Print binary string if array size is filled with bits
    if (i == n)
    {
      for (int i = 0; i < n; i++)
      {
        printf("%d", arr[i]);
      }
      printf("\n");
      return;
    }

    //Recursively create the binary strings
    arr[i] = 0;
    createBinaryStrings(n, arr, i + 1);
    arr[i] = 1;
    createBinaryStrings(n, arr, i + 1);
}

int main()
{
    int n = 0;
    int arr[n];

    //Prompt user to enter number
    printf("Enter number greater than 5:");
    scanf("%d",&n);

    //Create and print binary strings
    createBinaryStrings(n, arr, 0);

    return 0;
}
