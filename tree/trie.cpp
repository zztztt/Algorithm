/*
 * Trie Tree
 * input string includes ascii from 32 to 126
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 225 // ascii index from 32 to 256
#define CHAR_OFFSET 32 // ascii index start at 32

/*
 * Trie Tree Struct
 */
typedef struct trie_tree_s trie_tree_t;
struct trie_tree_s
{
  bool end; // whether end is the end of the word
  trie_tree_t *next[MAX_NUM];
};
// find the index of the char
int char_index(char x)
{
  return x - CHAR_OFFSET;
}
// insert element to the trie tree
void insert(trie_tree_t *root, char *x)
{
  trie_tree_t *cur;
  cur = root;
  int i;
  for (i = 0; x[i] != '\0'; ++i)
  {
    if (cur->next[char_index(x[i])] == NULL)
    {
      cur->next[char_index(x[i])] = (trie_tree_t*) malloc(sizeof(trie_tree_t));
      memset(cur->next[char_index(x[i])], 0, sizeof(trie_tree_t));
    }
    cur = cur->next[char_index(x[i])];
  }
  cur->end = true;
}
// find element of the trie tree
bool find(trie_tree_t *root, char *x)
{
  trie_tree_t *cur;
  cur = root;
  int i;
  for (i = 0; x[i] != '\0'; ++i)
  {
    if (cur->next[char_index(x[i])] == NULL)
    {
      return false; 
    }
    cur = cur->next[char_index(x[i])];
  }
  return cur->end;
  
}

int main(int argc, char* argv[])
{
  trie_tree_t *root = (trie_tree_t*) malloc(sizeof(trie_tree_t));
  insert(root, "adewf");
  insert(root, "ade113412wf");
  insert(root, "adewwefaweff");
  insert(root, "adewflllll");
  insert(root, "abc");
  insert(root, "uxu");
  char *input;
  if (argc > 1)
  {
    input = argv[1];
  }
  else
  {
    input = (char*)malloc(sizeof(char) * 100);
    scanf("%s",input);
  }

  if (find(root, input)) 
  {
    printf("yes\n");
  }
  else
  {
    printf("no\n");
  }
}
