#include<stdlib.h>
#include "avl.h"
#include<stdio.h>

struct AVL* newNode(int data){
  struct AVL* node = malloc(sizeof(node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  return node;
}


int max(int a, int b){
  return (a > b) ? a : b;
}


struct AVL* insert(struct AVL* node, int data){
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
           height(node->left);
  return 0;
}
int isAVL(struct AVL* node){
  if(!node) return 1;
  return abs(balanceFactor(node)) <= 1 && isAVL(node->left) && isAVL(node->right);
}

struct AVLNode* leftRotation(struct AVLNode* node){
  struct AVLNode* x = node;
  struct AVLNode* y = node->right;
  x->right = y->left;
  y->left = x;
  return y;
}

struct AVLNode* leftRotation(struct AVLNode* x){
  assert(x != NULL);

  struct AVLNode* y = x->right;
  struct AVLNode* px = x->parent;
  b = y->left;
  y->left = x;
  x->parent = y;
  
  x->right = b;
  b->parent = x;
  if(px){
    if(parentx->left ==x)
      parentx->left = y;
    else
      parentx->right = y;
  }
  y->parent = parentx;
  return y;
}

struct AVLNode* rightRotation(struct AVLNode* y){
  assert(y != NULL);
  //Asigno segun el grafico
  struct AVLNode* x = y->left;
  struct AVLNode* py = y->parent;
  struct AVLNode* b = x->right;
  //Realizo rotacion
  x->right = y;
  y->parent = x;
  
  y->left = b;
  b->parent = y;
  if(py){
    if(py->left ==y)
      py->left = x;
    else
      py->right = x;
  }
  x->parent = py;
  return x;
}



