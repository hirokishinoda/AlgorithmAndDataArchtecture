#include <stdio.h>
#include <stdlib.h>

typedef struct CELL{
  struct CELL *next;
  int value;
}CELL;

/*
 * セルの挿入
 * */
void insert_cell(CELL *p,int val){
  CELL *new;

  if((new = malloc(sizeof(CELL))) != NULL){
    // セルに情報を追加
    new->value = val;
    new->next = p->next;
    // 新しいセルを追加
    p->next = new;

    printf("complete insert.\n");
  }else{
    printf("メモリ不足です．");
  }
}

/*
 * セルの削除
 * */
void remove_cell(CELL *p){
  CELL *q;

  q = p->next;
  p->next = q->next;
  free(q);
  printf("complete remove.\n");
}

/*
 * リストの初期化
 * */
void init_list(CELL *head){
  head->next = head;
}

/*
 * リストの表示
 * */
void disp_list(CELL *head){
  CELL *p;

  printf("head:%p next:%p\n",head,head->next);
  for(p = head->next; p != head;p = p->next){
    printf("val:%d this:%p next:%p\n",p->value,p,p->next);
  }
}

int main(void){
  CELL header;

  // 初期化
  init_list(&header);
  // 挿入
  insert_cell(&header,10);
  insert_cell(&header,20);
  insert_cell(header.next,15);
  // 表示
  disp_list(&header);
  // 削除
  remove_cell(&header);
  // 表示
  disp_list(&header);

  return 0;
}
