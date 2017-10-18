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
      
      scanf("%c",&option);
      
      if(option =='i'){
	printf("\nPlease enter a name\n");
	scanf("%s",&value);
	printf("Inserting %s\n",value);
	insert(value, &treeRoot, (Compare)CmpStr);
      }
      else if(option =='s'){
	printf("\nPlease enter a name to look for\n");
	scanf("%s",&value);
	search(value, treeRoot, (Compare)CmpStr);
      }
      else if(option =='p'){
	in_order(treeRoot);
      }
      else if(option =='q'){
	printf("\nQuitting\n");
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
