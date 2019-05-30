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

  printf("%d t:%p r:%p l:%p\n",p->val,p,p->right,p->left);
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

/*
 * 最小ノードを探す
 * */
NODE *min_node(NODE **p){
  NODE *q;

  while((*p)->left != NULL){
    p = &(*p)->left;
  }
  q = *p;
  *p = (*p)->right;

  return q;
}

/*
 * 削除
 * */
int remove_node(NODE **root,int val){
  NODE **p,*x;

  p = root;
  while(p != NULL){
    if((*p)->val == val){

      x = *p;
      if((*p)->right == NULL && (*p)->left == NULL){
        *p = NULL;
      }else if((*p)->right == NULL){
        *p = (*p)->left;
      }else if((*p)->left == NULL){
        *p = (*p)->right;
      }else{
        *p = min_node(&(x->right));
        (*p)->right = x->right;
        (*p)->left = x->left;
      }
      free(x);

      printf("removed %d\n.",val);
      return 1;

    }else if((*p)->val > val){
      p = &(*p)->left;
    }else{
      p = &(*p)->right;
    }
  }
  printf("Not Found.\n");
  return 0;
}

int main(void){
  NODE *root = NULL;

  insert_node(&root,5);
  insert_node(&root,8);
  insert_node(&root,3);
  insert_node(&root,2);
  insert_node(&root,1);
  insert_node(&root,4);
  insert_node(&root,6);
  insert_node(&root,9);
  insert_node(&root,10);

  preorder(root);

  search_node(root,4);

  remove_node(&root,8);
  preorder(root);

  return 0;
}
