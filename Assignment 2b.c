/*
Problem Statement - Implement the C program in which main program accepts aninteger array. Main program uses the FORK system call to create a new process called a child process. Parent process sorts an integer array and passes the sorted array to child process through the command line arguments of EXECVE system call. The child process uses EXECVE system call to load new program which display array in reverse order
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// using merge sort, but any sorting algorithm will be fine
void merge(int a[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++) {
    L[i] = a[l + i];
  }

  for (j = 0; j < n2; j++) {
    R[j] = a[m + 1 + j];
  }

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}

void sort(int a[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    sort(a, l, m);
    sort(a, m + 1, r);
    merge(a, l, m, r);
  }
}

int main() {
  //-------------- Taking array input and sorting it --------------
    int n;
    printf("\nNo of elements\n");
    scanf("%d", &n);

    int a[n];
    printf("\nElements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, 0, n - 1);

    printf("\nSorted array\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
  //---------------------------------------------------------------

  char strArr[n][1000];  //for storing the array elements as strings
  for (int i = 0; i < n; i++) {
    sprintf(strArr[i], "%d", a[i]);  //stores prepared string to the buffer strArr[i]
  }
  char *args[n + 2]; //filename + no. of array elements + NULL item = n + 2
  args[0] = "./reverse"; //first argument to the exec() is the filename of the executable

  for (int i = 0; i < n; i++) {
    args[i + 1] = strArr[i]; //storing array element in the argument array
  }

  args[n + 1] = NULL; //last item of argument as NULL

  execvp(args[0], args); //calling another program using exevp() system call
  return 0;
}

/* Sequence is important here

gcc reverse.c -o reverse.out
gcc 'Assignment 2b.c' -o 'Assignment 2b.out'
./'Assignment 2b.out'

*/
