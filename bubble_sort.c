#include <stdio.h>

#define N 15

void bubble_sort(int *array){
  int i,j,tmp;

  int n = N;

  for(i = 0;i < n-1;i++){
    for(j = n-1;j > i;j--){
      // 前後関係がおかしければ交換する
      if(array[j] < array[j-1]){
        // 交換部分(前後入れ替え)
        tmp = array[j];
        array[j] = array[j-1];
        array[j-1] = tmp;
      }
    }
  }
}

void disp_array(int *array){
  int i;

  int n = N;

  printf("[");
  for(i = 0;i < n;i++){
    printf("%d,",array[i]);
  }
  printf("]\n");
}

int main(void){
  int array[N] = {7,4,5,3,2,6,9,8,6,5,0,3,2,1};

  disp_array(array);

  bubble_sort(array);

  disp_array(array);

  return 0;
}
