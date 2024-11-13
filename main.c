#include "avl.h"
int main(int argc, char* argv[]){
  struct AVL* root = 0;
  root = insert(root,5);
  int h = height(root);
  printf("%d\n", h);
  }

