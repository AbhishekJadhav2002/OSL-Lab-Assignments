/*
Problem Statement - Implement the C program in which main program accepts the integers to be sorted. Main program uses the FORK system call to create a new process called a child process. Parent process sorts the integers using sorting algorithm and waits for child process using WAIT system call to sort the integers using any sorting algorithm. Also demonstrate zombie and orphan states
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// using merge and quick sort, but any sorting algorithm will be fine
void merge(int a[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = a[l + i];
  for (j = 0; j < n2; j++)
    R[j] = a[m + 1 + j];

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

void mergeSort(int a[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    merge(a, l, m, r);
  }
}

void printArray(int A[], int n) { int i; }

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int a[], int low, int high) {
  int pivot = a[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (a[j] < pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[high]);
  return (i + 1);
}

void quickSort(int a[], int low, int high) {
  if (low < high) {
    int pi = partition(a, low, high);

    quickSort(a, low, pi - 1);
    quickSort(a, pi + 1, high);
  }
}

// implementing first part of the statement
void normal() {
  int n;
  printf("array size\n");
  scanf("%d", &n);

  int a[n];

  printf("\nEnter array\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  printf("\nGiven array is \n");
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");

  pid_t pid = fork();

  if (pid == -1) {
    printf("Error: error while executing fork()");
    return;
  }

  // child quick sort
  if (pid == 0) {
    printf("Child is: %d\n", (int)getpid());
    printf("Parent is: %d\n", (int)getppid());
    quickSort(a, 0, n - 1);
    printf("Sorted array \n");
    for (int i = 0; i < n; i++)
      printf("%d ", a[i]);
    printf("\n");
    exit(0); //child exiting and informing the parent that child has been terminated 
  }
  // parent merge sort
  else {
    pid_t cpid = wait(NULL); //parent waiting for all child to finish and start after receiving the response from child (https://stackoverflow.com/a/42426884/17222693)

    printf("Process ID is: %d\n", (int)getpid());

    mergeSort(a, 0, n - 1);

    printf("Sorted array is \n");
    for (int i = 0; i < n; i++)
      printf("%d ", a[i]);
    printf("\n");
  }
}

//child becomes orphan beacause parent exits without waiting for the child process to finish
void orphan() {
  pid_t pid = fork();

  if (pid == 0) {
    printf("\nChild %d is going to sleep for 5 sec...\n", (int)getpid());
    sleep(10); //explicitly running child process for desired long enough time, parentid will be different before and after sleep()
    printf("\nAfter child wakes up...\nParent of child is %d\n", (int)getppid());  //prints id of init process (after re-parenting) as original parent has been exited
    system("ps -elf | grep fork");  //system command to display all the processes with current program('fork') in full format

    exit(0); //child exits immediately
  } else {
    sleep(5);
    printf("\nParent Process %d, child is still executing\nParent exits.\n", (int)getpid()); //parent exits without waiting for the child to finish
  }
  return;
}

//child becomes zombie as it exits without informing it's parent, so parent doesn't actually know that the child has finished
void zombie() {
  pid_t pid = fork();

  if (pid > 0) {
    system("ps -efl | grep defunct"); //parent start executing without checking child's status
    sleep(2); //explicitly running parent's block for desired long enough time so that in meantime child will exit
    system("ps -efl | grep defunct");
  } else {
    printf("Inside child process, Parent process ID: %d\nChild exit.\n", getppid());

    exit(0);
  }
  return;
}

int main() {
  int opt = 1;

  while (opt) {
    printf("1 Normal\n");
    printf("2 Orphan\n");
    printf("3 Zombie\n");
    printf("Enter an option: ");
    scanf("%d", &opt);

    switch (opt) {
    case 1:
      normal();
      break;
    case 2:
      orphan();
      break;
    case 3:
      zombie();
      break;
    default:
      break;
    }
  }

  return 0;
}

/*
gcc 'Assignment 2a.c' -o 'Assignment 2a.out'
*/
