/*
Problem Statement - Implement the C program in which main program accepts an integer array. Main program uses the FORK system call to create a new process called a child process. Parent process sorts an integer array and passes the sorted array to child process through the command line arguments of EXECVE system call. The child process uses EXECVE system call to load new program which display array in reverse order
*/

#include <stdio.h>
#include <stdlib.h>

// function to search for the key using Binary search
// int search(int arr[], int l, int r, int x) {
//   if (r >= l) {
//     int mid = l + (r - l) / 2;

//     if (arr[mid] == x)
//       return mid;

//     if (arr[mid] > x)
//       return search(arr, l, mid - 1, x);

//     return search(arr, mid + 1, r, x);
//   }
//   return -1;
// }

//argc provides the argument count
int main(int argc, char *argv[]) {
  int n = argc - 1; //excluding the last NULL character
  int arr[n]; //preparing new array of elements
  for (int i = 1; i <= n; i++) { // i = 1 because, argv[0] is pointing to filename
    arr[i - 1] = atoi(argv[i]); //charater string to integer
  }

  //printing the provided array in reverse order
  printf("\nInside child process through execvp() command...\nArray in reverse order: ");
  for(int i = n - 1; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  printf("\n");

//   int x;
//   printf("\nEnter element to search\n");
//   scanf("%d", &x);

//   int result = search(arr, 0, n - 1, x);  //executing search on the array with key x

//   if (result == -1) {
//     printf("Not found\n");
//   } else {
//     printf("Found at index %d\n", result);
//   }
  return 0;
}
