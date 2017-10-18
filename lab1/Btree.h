#ifndef node_included
#define node_included
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  char *value;
  struct node *left,*right;
};

typedef int (*Compare)(const char *, const char *);

void insert(char* name, struct node** leaf, Compare cmp)
{
  int res;
  if( *leaf == NULL ){
    *leaf = (struct node*) malloc( sizeof( struct node ) );
    (*leaf)->value = malloc( strlen(name)+1);
    strcpy ((*leaf)->value,name);
    (*leaf)->left = NULL;
    (*leaf)->right = NULL;
  }
  else{
    res = cmp(name, (*leaf)->value);
    if( res < 0 )
      insert(name, &(*leaf)->left, cmp);
    else if(res > 0)
      insert(name, &(*leaf)->right, cmp);
    else
      printf("The employee '%s' is already in the system\n",name);
  }
}

int CmpStr(const char *a, const char *b)
{
  return (strcmp (a,b));
}

void in_order(struct node *root)
{
  if(root != NULL){
    in_order(root->left);
    printf("   %s\n", root->value);
    in_order(root->right);
  }
}
void search(char* name, struct node* leaf, Compare cmp)
{
  int res;
  if(leaf != NULL){
    res = cmp(name, leaf->value);
    if(res < 0)
      search(name,leaf->left,cmp);
    else if(res > 0)
      search(name,leaf->right,cmp);
    else
      printf("\n'%s' found!\n",name);
  }
  else printf("\nNot Found\n");
  return;
}

/*struct node* delete(char* name, struct node* leaf, Compare cmp)
{
  int res;
  if(leaf == NULL)
    return NULL;
  res = cmp(name, leaf->value);
  if(res < 0)
    leaf->left = delete(name, leaf->left, cmp);
  else if(res > 0)
    leaf->right = delete(name, leaf->right,cmp);
  else{
    if(leaf->left == NULL && leaf->right  == NULL){
      free(leaf);
      leaf=NULL;
    }
    else if(leaf->left == NULL){
      struct node *temp = leaf;
      leaf = leaf->right;
    }
    else if(leaf->right == NULL){
      struct node *temp = leaf;
      leaf = leaf->left;
    }
    else{
      struct node *temp = FindMin(leaf->right);
      leaf->value = temp->value;
      leaf->right = delete(temp->value,leaf->right,cmp);
    }
  }
  return leaf;
}

struct node* FindMin(struct node* leaf)
{
  if(leaf == NULL)
    return NULL;
  if(leaf->left != NULL)
    return FindMin(leaf->left);
  return leaf;
  }*/

#endif
