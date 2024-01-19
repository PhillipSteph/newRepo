#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void swap(int* ptr1, int* ptr2);
void reverse(int* ptr1, int* ptr2);
int* find_smaller(int arr[],int* ptr);
int* find_larger(int arr[],int* ptr, int a);
void fill(int arr[],int a);
void print(int* arr,int a);
bool perm(int* arr,int a);


int main(int argc, const char *argv[]){

if(argc!=2 || atoi(argv[1])<1 || atoi(argv[1])>30){
 return 1;
}

int n = atoi(argv[1]);
int arr[n];
fill(arr,n);
print(arr,n);


while(perm(arr,n)){
print(arr,n);
}

    return 0;
}


void swap(int* ptr1, int* ptr2){
int temp= *ptr1;
*ptr1 = *ptr2;
*ptr2 = temp;
}
void reverse(int* ptr1, int* ptr2){

while(ptr2>ptr1){
    swap(ptr1, ptr2);
    ptr1++;ptr2--;
}

}

int* find_smaller(int* arr,int* ptr){

    while(ptr>arr){
        int* temp = ptr;
        ptr--;
        if(*ptr<*temp){
            return ptr;
        }
    }
    return NULL;
}

int* find_larger(int* arr,int* ptr,int a){

    while(ptr>arr){
        if(*ptr>a){
            return ptr;
        }
        ptr--;
    }
return NULL;
}
bool perm(int* arr,int a){

    int* lastptr = arr+a-1;
    int* links = find_smaller(arr,lastptr);
    if(links==NULL) return false;
    int* rechts = find_larger(arr,lastptr,*links);
    swap(links, rechts);
    reverse(links+1,lastptr);
    
return true;
}
void fill(int arr[],int a){

    for(int i=0;i<a;i++){
        arr[i]=i+1;
    }
}

void print(int* arr,int a){

      for (const int *p = arr; p < arr + a; ++p) {
    printf("%d ", *p);
  }
  printf("\n");

}