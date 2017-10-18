#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Btree.h"

int main()
{
  struct node *treeRoot = NULL;
  char *value;
  char option = 'x';

  while(option != 'q')
    {
      menu();
      
      option = getch();

      if(option =='i'){
	printf("Please enter a name");
	scanf("%s",&value);
	insert(value, &treeRoot, (Compare)CmpStr);
      }
      
    }
  return 0;
}

void menu()
{
  printf("\nPress 'i' to insert a name\n");
  printf("Press 's' to search for a name\n");
  printf("Press 'p' to print the tree inorder\n");
  printf("Press 'q' to quit\n");
}
