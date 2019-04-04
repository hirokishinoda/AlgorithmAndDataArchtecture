#include <stdio.h>

#define N 7

void select_sort(int *array){
  int i,j,tmp;

  for(i = 0; i < N-1;i++){
    for(j = i;j < N;j++){
      if(array[i] > array[j]){
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
}

void display_array(int *array){
  int i;

  for(i = 0;i < N;i++){
    printf(" %d",array[i]);
  }
  printf("\n");
}

int main(void){
  int array[N] = {4,1,2,10,9,6,3};

  display_array(array);

  select_sort(array);

  display_array(array);
  return 0;
}
