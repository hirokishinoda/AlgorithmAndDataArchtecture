#include <stdio.h>
#include <stdlib.h>

typedef struct CELL{
  struct CELL *prev;
  struct CELL *next;
  int val;
}CELL;


/*
 * セルの挿入
 * */
void insert_cell(CELL *p,int val){
  CELL *q;

  if((q = malloc(sizeof(CELL))) != NULL){
    q->val = val;
    q->prev = p;
    q->next = p->next;
    p->next->prev = q;
    p->next = q;
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
  q->next->prev = p;

  free(q);
}

/*
 * リストの初期化
 * */
void init_list(CELL *head){
  head->next = head->prev = head;
}

/*
 * リストの表示
 * */
void disp_list(CELL *head){
  CELL *p;

  printf("head prev:%p this:%p next:%p\n",head->prev,head,head->next);
  for (p = head->next;p != head;p = p->next){
    printf("val:%d prev:%p this:%p next:%p\n",p->val,p->prev,p,p->next);
  }
}

int main(void){
  CELL head;

  init_list(&head);

  insert_cell(&head,10);
  insert_cell(&head,20);
  insert_cell(head.next,15);

  disp_list(&head);
  
  remove_cell(&head);
  
  disp_list(&head);

  return 0;
}
