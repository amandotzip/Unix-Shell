/*
  Establishes core struct for project
A Unix node can be either a file or a dir, determined
by the is_dir field (1=is a dir, 0=is not).

Every node has a list, with that list's head being head_child. Said
list is all the nodes within the current node. A file node will
always have an empty list, only a directory will have a populated
list (or also empty, if nothing is in the directory).
*/
#if !defined(UNIX_C)
#define UNIX_C



/*Unix structs are nodes for all intents and purposes*/
typedef struct Unix{
  char *name;
  int is_dir;
  struct Unix *parent_dir;/*pointer to parent of this file/dir*/
  struct Unix *current_dir;/*current dir of the filesystem*/
  struct Unix *next;/*next item in the list of current_dir files*/
  struct Unix *head_child;/*head of current_dir files list*/
  struct Unix *root;/*reference to root of filesystem*/
}Unix;

/*Helper functions for recursion*/
char* pwd_helper(Unix *current, char *path);
void rmfs_helper(Unix *current);

#endif
