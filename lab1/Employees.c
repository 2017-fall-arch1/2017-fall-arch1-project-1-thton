#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#inlcude "Btree.h"

int main()
{
  struct node *treeRoot = NULL;
  char *value;
  char option = 'x';

  while(option != 'q')
    {
      menu();
      
      option = getch();
      
    }
  
}

void menu()
{
  printf("\nPress 'i' to insert a name\n");
  printf("Press 's' to search for a name\n");
  printf("Press 'p' to print the tree inorder\n");
  printf("Press 'q' to quit");
}
