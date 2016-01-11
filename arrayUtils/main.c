#include"lib.h"
#include<stdio.h>

int main(void){
  ArrayUtil arr = create(4, 1);
  ArrayUtil arr2 = create(4, 3);
  areEqual(arr, arr2);
  arr = resize(arr, 7);
  print_arr(arr);
  int x = 20;
  *((int *)arr.base) = 20;
  printf("The index of %d is %d ", x, findIndex(arr, &x));
  print_arr(arr);
  dispose(arr);
  return 0;
};
