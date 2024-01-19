
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nk(int n,int k);
static int counter;

int main(int argc, const char *argv[]){

int val = nk(atoi(argv[1]),atoi(argv[2]));

printf("%d",val);
    return 0;
}

int nk(int n,int k){

counter++;
static int arr[35][35];
if(k>n) return 0;

if((n==k || k==0)){ arr[n][k]=1; return 1;}
if((n<0 || k<0)) return 0;

if(arr[n][k]==0){
    arr[n][k]=nk(n-1,k)+nk(n-1,k-1);
    return arr[n][k];
}
else{
    return 0;
}


}

/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 34

unsigned int callCnt = 0;
static int arr[MAX_VAL][MAX_VAL];
unsigned int binom(unsigned int n, unsigned int k)
{
  ++callCnt; 
  if (k > n) return 0;

  if ((k == 0) || (k == n)) return 1;

  if (n > MAX_VAL) {
    printf("%u über %u ist zu groß (max. %d)\n", n, k, MAX_VAL);
    exit(EXIT_FAILURE);
  }
    if(arr[n][k]==0){
        arr[n][k]=binom(n - 1, k - 1) + binom(n - 1, k);
        return arr[n][k];
    }else{
        return arr[n][k];
    }
}

int main(int argc, const char *argv[])
{
  if (argc != 3) {
    printf("Aufruf: %s n k\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  printf("%s über %s = %u\n", argv[1], argv[2],
        binom(atoi(argv[1]),atoi(argv[2])));

  printf("Funktionsaufrufe: %u\n", callCnt);

  exit(EXIT_SUCCESS);
}
*/