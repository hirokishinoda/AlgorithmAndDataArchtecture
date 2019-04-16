#include <stdio.h>

#define LENGTH  10

// 作業用バッファ
int b[LENGTH];

void merge_sort(int *array, int low, int high){
  int mid, i, j, k;

  if(low >= high) return;

  // 分割箇所を計算
  mid = (low + high) / 2;

  // 前半部分をソート
  merge_sort(array, low, mid);

  // 後半部分をソート
  merge_sort(array, mid+1, high);

  // 前半を作業用バッファに代入
  for(i = 0; i <= mid;i++){
    b[i] = array[i];
  }

  // 後半を後ろから作業用バッファに代入
  for(i = mid+1, j = high;i <= high;i++,j--){
    b[i] = array[j];
  }

  // 前半と後半から比較
  i = low;
  j = high;
  for(k = low;k <= high;k++){
    if(b[i] <= b[j]) array[k] = b[i++]; //前半のほうが小さかったら代入
    else array[k] = b[j--]; //後半のほうが小さかったら代入
  }
}

int disp_array(int *array){
  int i;

  printf("[ ");
  for(i = 0;i < LENGTH;i++){
    printf("%d ",array[i]);
  }
  printf("]\n");
}

int main(void){
  int array[LENGTH] = {2,9,6,3,5,1,4,7,8,0};

  disp_array(array);

  merge_sort(array, 0, LENGTH-1);

  disp_array(array);

  return 0;
}
