#include<stdlib.h>
#include<stdio.h>


struct AVL {
  int data;
  struct AVL* left;
  struct AVL* right;
  struct AVL* parent;
};

struct AVL* insert(struct AVL* node, int data);
int height(struct AVL* node);
int balanceFactor(struct AVL* node);
int isAVL(struct AVL* node);

int max(int a, int b){
  return (a > b) ? a : b;
}


struct AVL* newNode(int data){
  struct node* node = malloc(sizeof(node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  return node;
}



struct AVL* insert(struct node*, int data){
  if(node){
    if(data <= node->data){
      node->left = insert(node->left, data);
      node->left->parent = node;
    } else {
      node->right = insert(node->right, data);
      node->right->parent = node;
    }
  }else
    return newNode(data);
  return node;
}

int height(struct AVL* node){
  if(node == NULL)
    return -1;
  return 1 + max(height(node->left) ,height(node->right));
}

int balanceFactor(struct AVL* node){
  if(node)
    return height(node->right) -
           height(node->left)
  return 0;
}
int isAVL(struct AVL* node){
  if(!node) return 1;
  return abs(balanceFactor(node)) <= 1 && isAVL(node->left) && isAVL(node->right);
}
 
