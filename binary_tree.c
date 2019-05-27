#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
  struct NODE *right;
  struct NODE *left;
  int val; 
}NODE;


/*
 * 表示・3パターン
 * */

// 行きがけ
void preorder(NODE *p){
  if(p == NULL) return;

  printf("%d\n",p->val);
  preorder(p->left);
  preorder(p->right);
}

// 通りがけ
void inorder(NODE *p){
  if(p == NULL) return;

  inorder(p->left);
  printf("%d\n",p->val);
  inorder(p->right);
}

// 帰りがけ
void postorder(NODE *p){
  if(p == NULL) return;

  postorder(p->left);
  postorder(p->right);
  printf("%d\n",p->val);
}

int main(void){
  return 0;
}
