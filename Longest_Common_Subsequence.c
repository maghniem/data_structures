/* Dynamic Programming implementation of Longest Contiguous Subsequence problem */

//this program finds the longest subsequence whithin 2 strings that are contiguous
//it uses a Dynamic approach to build a 2 demensional array and has a complexity of O(M x N)


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(a,b)\
({ __typeof__ (a) _a = (a);\
  __typeof__ (b) _b = (b);\
_a > _b ? _a : _b; })
 

void lcs( char X[], char Y[], int m, int n );
 

int main(int argc, char *argv[])
{
  char X[] = "ABAZDC";
  char Y[] = "BACBAD";
  int m = strlen(X);
  int n = strlen(Y);
  lcs(X, Y, m, n);
  return 0;
}
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs( char X[], char Y[], int m, int n )
{
  int i, j;

  //create multidimensial array L[m+1][n+1], +1 to hold null at end of strings
  int **Lcs_Table;

  Lcs_Table = malloc((m+1)*sizeof(int*));

  for (i = 0; i < (m+1); i++)
  {
    Lcs_Table[i] = malloc((n+1) * sizeof(int));
  }
 
   /* Following steps build L[m+1][n+1] in bottom up fashion.
      L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
  for (i=0; i<=m; i++)
  {
    for (j=0; j<=n; j++)
    {
      if (i == 0 || j == 0) //setting values to be incrmented by else condition
        Lcs_Table[i][j] = 0;
      else if (X[i-1] == Y[j-1])
        Lcs_Table[i][j] = Lcs_Table[i-1][j-1] + 1;
      else
        Lcs_Table[i][j] = max(Lcs_Table[i-1][j], Lcs_Table[i][j-1]);
    }
  }
 
   // Following code is used to print LCS
  int index = Lcs_Table[m][n];
  
  // Create a character array to store the lcs string
  char *lcs;
  lcs = malloc((index+1) * sizeof(char));
   
  lcs[index] = '\0'; // Set the terminating character

 
  // Start from the right-most-bottom-most corner and
  // store characters in lcs[]
  i = m, j = n;
  while (i > 0 && j > 0)
  {
     // If current character in X[] and Y[] are same, then
     // current character is part of LCS, move diagonally 
     if (X[i-1] == Y[j-1])
     {
         lcs[index-1] = X[i-1]; // Put current character in lcs[]
         i--; j--; index--;     // reduce values of i, j and index to move diagonally
     }
 
      // If not same, then find the larger of two and
     // go in the direction of larger value
     else if (Lcs_Table[i-1][j] > Lcs_Table[i][j-1])
        i--;
     else
        j--;
  }
    // Print the lcs
  printf("LCS of %s and %s is %s\n", X, Y, lcs);
  printf("LCS has length %d\n", Lcs_Table[m][n]);
  
  //free allocated storage
  
  for (i = 0; i < (m+1); i++) {
    free(Lcs_Table[i]);
  }

  free(Lcs_Table);
  free(lcs);

   return;
   
}