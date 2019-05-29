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

  inorder((p)->left);
  printf("%d\n",(p)->val);
  inorder((p)->right);
}

// 帰りがけ
void postorder(NODE *p){
  if(p == NULL) return;

  postorder((p)->left);
  postorder((p)->right);
  printf("%d\n",(p)->val);
}

/*
 * 新しいノードを作成
 * */
NODE *new_node(NODE *left,NODE *right,int val){
  NODE *new;

  if((new = malloc(sizeof(NODE))) != NULL){
    (new)->left = left;
    (new)->right = right;
    (new)->val = val;
  }else{
    printf("memory...\n");
  }

  return new;
}

/*
 * 挿入
 * */
void insert_node(NODE **node,int val){
  NODE **p;

  p = node;
  while(*p != NULL){
    if((*p)->val == val){
      return;
    }else if((*p)->val > val){
      p = &(*p)->left;
    }else{
      p = &(*p)->right;
    }
  }
  *p = new_node(NULL,NULL,val);
}

/*
 * 探索
 * */
int search_node(NODE *root,int val){
  NODE *p;

  while(p != NULL){
    if(p->val == val){
      printf("p->val:%d\n",p->val);
      printf("   val:%d\n",val);
      return 0;
    }else if(p->val > val){
      p = p->left;
    }else{
      p = p->right;
    }
  }

  printf("Not Found.\n");
  return -1;
}

int main(void){
  NODE *root = NULL;

  insert_node(&root,1);
  insert_node(&root,2);
  insert_node(&root,3);

  preorder(root);

  search_node(root,4);

  return 0;
}
