#include <stdio.h>
#include <stdlib.h>

/*
 *  セルの構造体
 * */
typedef struct CELL{
  struct CELL *next;
  int val;
}CELL;

/*
 * リストへのセルの挿入
 * */
void insert_cell(CELL *p,int val){
  CELL *q;

  // 新しいセルの領域を確保
  if((q = malloc(sizeof(CELL))) != NULL){
    // 新しいセルのデータを入れる
    q->val = val;
    q->next = p->next;
    // セルを挿入
    p->next = q;

    printf("complete insert.\n");
  }else{
    printf("メモリ不足です．");
  }
}

/*
 * リストからのセルを削除
 * */
void remove_cell(CELL *p){
  CELL *q;

  q = p->next;
  p->next = q->next;
  free(q);
  printf("complete remove.\n");
}

/*
 * リストを初期化する
 * */
void init_list(CELL *head){
  // nextは，ないのでNULL
  head->next = NULL;
}

/*
 * リストを表示する
 * */
void disp_list(CELL *head){
  CELL *p;

  for (p=head->next;p != NULL;p = p->next){
    printf("val:%d\n",p->val);
  }
}

int main(void){
  CELL header;
  // 初期化
  init_list(&header);
  // 挿入
  insert_cell(&header,10);
  insert_cell(&header,20);
  insert_cell(header.next,30);
  // 表示
  disp_list(&header);
  // 削除
  remove_cell(header.next);
  // 表示
  disp_list(&header);

  return 0;
}

