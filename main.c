#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* left;
  struct node* right;
}node_t;

void Insert(node_t**root, int num){
  if(*root==NULL){
    *root=(node_t*)malloc(sizeof(node_t));
    (*root)->data = num;
    (*root)->left=NULL;
    (*root)->right=NULL;
  }
  else{
    if(num < (*root)->data){
      Insert(&(*root)->left, num);
    }
    else if(num > (*root)->data){
      Insert(&(*root)->right, num);
    }
    else{
      printf("Duplicate number. Enter a different number");
    }
  }
}

node_t* Min(node_t*root){
  if(root->left == NULL){
    return(root);
  }
  else{
    return(Min(root->left));
  }
}

void Delete(node_t**root, int num){
  if(*root==NULL){
    printf("Underflow");
  }
  else if(num < (*root)->data){
    Delete(&(*root)->left, num);
  }
  else if(num > (*root)->data){
    Delete(&(*root)->right, num);
  }
  else{
    if((*root)->left==NULL && (*root)->right == NULL){
      node_t* ptr = *root;
      free(ptr);
      *root=NULL;
    }
    else if((*root)->right == NULL){
      node_t* ptr = *root;
      *root=(*root)->left;
      free(ptr);
    }
    else if((*root)->left == NULL){
      node_t* ptr = *root;
      *root=(*root)->right;
      free(ptr);
    }
    else{
      node_t* temp = Min((*root)->right);
      (*root)->data=temp->data;
      Delete(&(*root)->right, temp->data);
    }
  }
}

void Pre(node_t*root){
  if(root==NULL){
    return;
  }
  else{
    printf("%d  ", root->data);
    Pre(root->left);
    Pre(root->right);
  }
}

void Post(node_t*root){
  if(root==NULL){
    return;
  }
  else{
    Post(root->left);
    Post(root->right);
    printf("%d  ", root->data);
  }
}

void In(node_t*root){
  if(root==NULL){
    return;
  }
  else{
    In(root->left);
    printf("%d  ", root->data);
    In(root->right);
  }
}



int main(void) {
  node_t*root=NULL;
  Insert(&root, 5);
  Insert(&root, 9);
  Insert(&root, 4);
  Insert(&root, 2);
  Insert(&root, 3);
  Insert(&root, 8);
  Insert(&root, 7);
  In(root);
  printf("\n");
  Pre(root);
  printf("\n");
  Post(root);
  printf("\n");
  Delete(&root, );
  In(root);
  printf("\n");
  Pre(root);
  printf("\n");
  Post(root);
  return 0;
}