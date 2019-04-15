#include <stdio.h>

#define LENGTH 10

int partition(int *a, int l, int r){
  int i, j, pivot, t;

  // 左端に移動
  // あとで++iを行うためl-1にしている
  i = l-1;
  // 右端に移動
  j = r;
  // 右端をピボットにする
  pivot = a[r];

  while(1){
    // 左側から見ていきピボットよりも
    // 大きい値が見つかるまで回す
    while(a[++i] < pivot);
    // 右側から見ていきピボットよりも
    // 小さい値が見つかるまで回す
    // iを飛び越さないように注意
    while(i < --j && pivot < a[j]);

    // 重なるもしくは超えたら
    // ループ終了
    if (i >= j) break;

    // 入れ替えを行う
    t = a[i]; a[i] = a[j]; a[j] = t;
  }
  // pivot と i を入れ替え
  t = a[i]; a[i] = a[r]; a[r] = t;

  return i;
}

void quick_sort(int *array,int l,int r){
  // pivot
  int v;

  // 要素数が１なら返る
  if( l >= r ) return;

  // pivot vを基準に分割
  v = partition(array, l, r);

  // 左側をソート
  quick_sort(array, l, v-1);

  // 右側をソート
  quick_sort(array, v+1, r);
}

void disp_array(int *a){
  int i;

  printf("[ ");
  for (i = 0; i < LENGTH;i++){
    printf("%d ",a[i]);
  }
  printf("]\n");
}

int main(void){
  int array[LENGTH] = {2,5,4,8,6,1,9,10,3,7};

  disp_array(array);

  quick_sort(array, 0, LENGTH-1);

  disp_array(array);

  return 0;
}

