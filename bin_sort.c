#include <stdio.h>

typedef struct{
  int key;  // 格納番号

  int other; // その他
} DATA;

#define LENGTH 10
#define BIN_LENGTH 100

DATA bin[BIN_LENGTH+1];

void bin_sort(DATA *array){
  int i, j;

  // びんを空にする
  for(i = 0;i <= BIN_LENGTH;i++){
    bin.key[i] = -1;
  }

  // 配列のデータをビンに格納
  for(i = 0;i < LENGTH;i++){
    bin[bin[i].key] = array[i];
  }

  // ビンから取り出して格納
  j = 0;
  for(i = 0;i <= BIN_LENGTH;i++){
    if(bin[i].key = -1){
      a[j++] = bin[i].key;
    }
  }
}

int main(void){
  int array[LENGTH] = {2,5,6,7,3,4,8,9,0,1};

  bin_sort(array);

  return 0;
}
