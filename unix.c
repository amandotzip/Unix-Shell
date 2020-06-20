/*TerpConnect: aawoke
  UID: 114094155
  Discussion #: 0202
  I pledge on my honor that I have not given nor recieved
  any unauthorized assistance on this assignment
*/



/*
Project is focused on application of structs to implement
a UNIX like filesystem. Unix structs are essentially Nodes
(but in application files or dirs),all containing a reference to root, 
current directory, parent of current directory, list of children, and next.
Throughout the project when mallocing or reallocing, 
immedaitely below we'll check NULL to confirm enough space was 
available to allocate. Any char pointers or Unix
structs created for data manipulation are also always freed 
once use has expired.

The updated pwd, rmfs, and rm function all take advantage of 
recursion to traverse the filesystem.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unix.h"
#include "memory-checking.h"


/*Creates an empty filesystem (the root of it all), 
with the name being "/" to  represent root. The root
will be the current_dir, and the parent of the root is 
nothing so parent_dir will equal NULL. The root has
no children yet, so head_child should = NULL. There 
are no dirs on the same level as root, so that should also = NULL.*/


/*makes filesystem point to the root,
and the root leads to the rest of the nodes
int the system*/
void mkfs(Unix *filesystem){
  Unix *root;

  /*standard faulty param check*/
  if (filesystem != NULL){

    /*Root is allocated space along with char *name */
    root = malloc(sizeof(Unix));
    if (root == NULL)
      return;
    
    root->name = malloc(strlen("/") + 1);
    if (root->name == NULL) /*if not enough space*/
      return;
    
    strcpy(root->name,"/");

    /*root is always a dir, so set is_dir to true*/
    root->is_dir = 1;

    /*Parent is size of Unix struct, but NULL for now*/
    root->parent_dir = NULL;

    /*current directory is root initially*/
    root->current_dir = root;
    /*there are no files or dirs same level as root dir, so NULL
      and next is NULL*/
    root->head_child = NULL;
    root->next = NULL;

    /*defining filesystem root and current_dir fields*/
    filesystem->root = root;
    filesystem->current_dir = root;
  }
}


/*touch aims to create files. the file name is determined by the arg
parm. if a file or dir with the same name 
already exists, a new file should not be added. current is used
to traverse the list of files/dirs within the current directory.
NOTE this function inserts in order.*/
int touch(Unix *filesystem, const char arg[]){

  /*begin at head_child of current dir. that is the list of 
  what the current dir contains*/
  Unix *current;
  Unix *new;
  char *arg_copy;

  /*Initial null checks*/
  if (arg == NULL || strlen(arg) == 0 || filesystem == NULL)
    return 0;

  /*if contains a "/"" and isnt a single "/"*/
  if ((strlen(arg) > 1) && strchr(arg + 1, '/') != NULL)
    return 0; 

  /*any of these as an arg should have no effect*/
  if (strcmp(arg, ".") == 0 || strcmp(arg, "..") == 0
   || strcmp(arg, "/") == 0)
    return 1;


  /*begin current at head child to traverse current directory*/
  current = filesystem->current_dir->head_child;
  /*if the list of files for current directory is empty,
    make sure not to traverse list.*/   
  if (current == NULL){
    /*inits new Unix*/
    new = malloc(sizeof(Unix));
    if (new == NULL)
      return 0;

    /*new unix shares parent of current, the parent being NULL*/
    new->parent_dir = filesystem->current_dir->parent_dir;
    
    /*dynamically allocates size of new Unix name, then
    copies arg onto name*/
    
    new->name = malloc(strlen(arg) + 1);
    if (new->name == NULL)
      return 0;
    strcpy(new->name, arg);
    
    /*this is a file, so is_dir is set to false*/
    new->is_dir = 0;
    
    /*first item in list is the head_child*/
    filesystem->current_dir->head_child = new;
    new->next = NULL;
    new->head_child = NULL;
    return 1;
  }

  /*arg_copy is the name of the arg with a '/' concatenated
  additional + 1 in malloc for '/' char */
  arg_copy = malloc(strlen(arg) + 2);
  if (arg_copy == NULL)
    return 0;

  strcpy(arg_copy, arg);
  strcat(arg_copy, "/");

  /*begin to traverse list of dir items.*/
  while (current != NULL){
  /*if a file with same name already exists, exit but not error case*/
    if (strcmp(current->name, arg) == 0 
      || strcmp(current->name,arg_copy) == 0){
      free(arg_copy);
      return 1;
    }
    current = current->next;
  }
  free(arg_copy);



  /*left while loop means didnt find copy of name arg
  meaning we will be able to add it
  and inits new Unix*/
  
  new = malloc(sizeof(Unix));
  if (new == NULL)
      return 0;
  /*parent should be current, since we're in the list under current*/
  new->parent_dir = filesystem->current_dir;
  /*dynamically allocates size of new Unix name, then
    copies arg onto name*/
 
  new->name = malloc(strlen(arg) + 1);
  if (new->name == NULL)
      return 0;
  strcpy(new->name, arg);

  /*this is a file, so is_dir is set to false*/
  new->is_dir = 0;
  new->head_child = NULL;


  /*if alphabetically file name should be placed before the head,
    place before head in list before traversing*/
  if (strcmp(arg, filesystem->current_dir->head_child->name) < 0){
    new->next = filesystem->current_dir->head_child;
    filesystem->current_dir->head_child = new;
    return 1;
  }
  else {
    /*resets current to head of list*/
    current = filesystem->current_dir->head_child;
    /*traverse through list
      if next thing is bigger than new, new is in the right place.
      on insertion return 1*/
    while (current->next != NULL){
      if (strcmp(new->name, current->next->name) < 0){
        new->next = current->next;
        current->next = new;
        return 1;
      }
      current = current->next;
    }
    /*if at end of list, add to end of list.
      on insertion return 1.*/
    if (current->next == NULL){
      current->next = new;
      new->next = NULL;
      return 1;
    }
  }
  /*new file/dir was never added, so free what we created*/
  free(new->name);
  free(new);
  /*this is only reached if list traversal errors occur*/
  return 0;
}



/*nearly identical to the touch() function. Only difference
is the modification to the argument string for comparison,
and the fact that any new Unix would have is_dir be true.*/
int mkdir(Unix *filesystem, const char arg[]){
  /*begin at head_child of current dir. that is the list of 
    what the current dir contains*/
  Unix *current;
  Unix *new;
  char *arg_copy;

  /*Initial null checks*/
  if (arg == NULL || strlen(arg) == 0 || filesystem == NULL)
    return 0;

  /*if contains a "/"" and isnt a single "/"*/
  if ((strlen(arg) > 1) && strchr(arg, '/') != NULL)
    return 0; 

  /*any of these as an arg are also error*/
  if (strcmp(arg, ".") == 0 || strcmp(arg,"..") == 0
   || strcmp(arg,"/") == 0)
    return 0;

  /*makes copy of arg name, appends "/" to
  mark as dir*/
  arg_copy = malloc(strlen(arg) + 2);
  if (arg_copy == NULL)
    return 0;
  strcpy(arg_copy, arg);
  strcat(arg_copy, "/");

  /*begin current at head child to traverse current directory*/
  current = filesystem->current_dir->head_child;
  /*if the list of files for current directory is empty,
    make sure not to traverse list.*/ 
  if (current == NULL){
  /*inits new Unix*/
    new = malloc(sizeof(Unix));
    if (new == NULL){
      free(arg_copy);
      return 0;
    }
    /*new unix shares parent of current, the parent being NULL*/
    new->parent_dir = filesystem->current_dir;

    /*when comparing names we have to check
      for '/' char, because all dirs have a '/'*/
    new->name = malloc(strlen(arg_copy) + 1);
    if (new->name == NULL){
      free(arg_copy);
      free(new);
      return 0;
    }
    strcpy(new->name, arg_copy);
    free(arg_copy);
    
    /*this is indeed a dir, so is_dir should be true*/
    new->is_dir = 1;
    new->head_child = NULL;

    /*first item in list is the head_child*/
    filesystem->current_dir->head_child = new;
    new->next = NULL;
    
    return 1;
  }


  /*begin to traverse list of dir items.*/
  while (current != NULL){
  /*if a dir with same name already exists, exit as error*/
    if (strcmp(current->name,arg) == 0 
      || strcmp(current->name,arg_copy) == 0 ){
      free(arg_copy);
      return 0;
    }
    current = current->next;
  }

  /*left while loop means didnt find copy of name arg
    meaning we will be able to add it
    and inits new Unix*/
  new = malloc(sizeof(Unix));
   if (new == NULL){
      free(arg_copy);
      return 0;
   }
  /*parent should be current, since we're in the list under current*/
  new->parent_dir = filesystem->current_dir;
  
  /*dynamically allocates size of new Unix name, then
    copies arg onto name*/

  new->name = malloc(strlen(arg_copy) + 1);
  if (new->name == NULL){
      free(arg_copy);
      return 0;
  }
  strcpy(new->name, arg_copy);
  free(arg_copy);

  /*again this is a dir so dir set to true*/
  new->is_dir = 1;
  new->head_child = NULL;

  /*if alphabetically file name should be placed before the head,
  place before head in list before traversing*/
  if (strcmp(arg, filesystem->current_dir->head_child->name) < 0){
    new->next = filesystem->current_dir->head_child;
    filesystem->current_dir->head_child = new; 
  }
  else {
  /*resets current to head of list*/
    current = filesystem->current_dir->head_child;
    /*traverse through list
      if next thing is bigger than new, new is in the right place.
      on insertion return 1*/
    while (current->next != NULL)
    {
      if (strcmp(new->name, current->next->name) < 0){
        new->next = current->next;
        current->next = new;
        return 1;
      }
      current = current->next;
    }
     /*if at end of list, add to end of list.
      on insertion return 1.*/
    if (current->next == NULL){
      current->next = new;
      new->next = NULL;
      return 1;
    }
  }
  /*this is only reached if list traversal errors occur*/
  return 0;
}



/*Changes the current_dir pointer of filesystem
  depenging on arg.*/
int cd(Unix *filesystem, const char arg[]){
  Unix *current;
  char *arg_copy;

  /*standard faulty param checks*/
  if (arg == NULL || filesystem == NULL)
    return 0;

  /*if contains a "/"" and isnt a single "/"*/
  if ((strlen(arg) > 1) && strchr(arg + 1, '/') != NULL)
    return 0; 

  /*if arg is . or empty, not error case but should exit*/
  if (strcmp(arg, ".") == 0 || strlen(arg) == 0)
    return 1;

  /*.. changed cd to parent*/
  if (strcmp(arg, "..") == 0){
    /*if we're at the root, parent is NULL.
      not error case but should exit*/
    if (filesystem->current_dir->parent_dir == NULL)
      return 1;
    /*change current_dir to parent_dir*/
    else
      filesystem->current_dir = filesystem->current_dir->parent_dir;
    return 1;
  }

  /*root char as arg changes current_dir to root */
  if (strcmp(arg, "/") == 0){
    filesystem->current_dir = filesystem->root;
    return 1;
  }
  current = filesystem->current_dir->head_child;

  /*traverse list of items within current. if it 
    is a dir and name matches argument, enter that dir*/
  while (current != NULL){
    /*arg_copy is the arg without the '/' */ 
    arg_copy = malloc(strlen(arg) + 2);
    if (arg_copy == NULL)
      return 0;
    strcpy(arg_copy, arg);
    strcat(arg_copy, "/");

    /*if current is a dir and name matches*/
    if (current->is_dir && strcmp(current->name, arg_copy) == 0){
      /*updates parent, and reassigns current*/
      current->parent_dir = filesystem->current_dir;
      filesystem->current_dir = current;
      free(arg_copy);
      return 1;
    }
    free(arg_copy);
    current = current->next;
  }
  /*returns 0 if argument was a legal word but a 
    matching dir was not found*/
  free(arg_copy);
  return 0;
}



/*prints list of items within a directory
depending on arg passed in. if passed a name print 
whole name*/
int ls(Unix *filesystem, const char arg[]){
  Unix *current;
  char * arg_copy;
  
  /*standard faulty param checks*/
  if (filesystem == NULL || arg == NULL)
    return 0;

  /*if contains a "/" and isnt a single "/"*/
  if ((strlen(arg) > 1) && strchr(arg + 1, '/') != NULL)
    return 0; 

  /*if . or empty, print all within current dir*/
  if (strcmp(arg, ".") == 0 || strcmp(arg, "") == 0){
    /*traverse current dir*/
    current = filesystem->current_dir->head_child;
    while (current != NULL){
      printf ("%s\n", current->name);
      current = current->next;
    }
    return 1;
  }
  /*if .., print parents children.*/
  else if (strcmp(arg, "..") == 0){
    /*if at root*/
    if (filesystem->current_dir->parent_dir == NULL){
      current = filesystem->current_dir->head_child;
      while (current != NULL){
        printf ("%s\n", current->name);
        current = current->next;
      }
      return 1;
    }

    /*reassigns current to parent
      and traverse parent dir*/


    current = filesystem->current_dir->parent_dir->head_child;
    while (current != NULL){
      printf ("%s\n", current->name);
      current= current->next;
    }
  }
  /*root means print immediate children of root*/
  if (strcmp(arg,"/") == 0){
    /*traverse root dir*/
    current = filesystem->root->head_child;
    while (current != NULL){
      printf ("%s\n", current->name);
      current= current->next;
    }
    return 1;
  }
  /*now checks for specific file or dir name to ls*/
  else {
    /*traverse current dir*/
    current = filesystem->current_dir->head_child;
    while (current != NULL){
      /*if it is a dir and name matches with arg,
      reassign current then print list of arg dir*/
      

      arg_copy = malloc(strlen(arg) + 2);
      if (arg_copy == NULL)
        return 0;
      strcpy(arg_copy, arg);
      strcat(arg_copy, "/");

      if (current->is_dir && strcmp(arg_copy, current->name) == 0){
      /*name was found so head_child is list of things within that
        Unix dir*/
        current = current->head_child;
        while (current != NULL){
          printf ("%s\n", current->name);
          current = current->next;
        }
        free(arg_copy);
        return 1;
      }
      /*if arg name is found as a file, print that single file then
      exit.*/
      if (current->is_dir == 0 && strcmp(arg, current->name) == 0){
        /*name was found so head_child is list of things within that
        Unix dir*/
        printf ("%s\n", current->name);
        free(arg_copy);
        return 1;
      }
      free(arg_copy);
      current = current->next;
    } 
  }
  /*if file/dir name not present, return 0*/
  free(arg_copy);
  return 0;
}



/*Print entire directory from root to current directory. If at root,
  just prints "/". Majority of work is done by passing the
  current directory into pwd_helper.*/
void pwd(Unix *filesystem){
  char *path;

  if(filesystem == NULL)
    return;

  path = malloc(1);
  if(path == NULL)
    return;
  strcpy(path, "");

  printf ("%s\n", pwd_helper(filesystem->current_dir, path));
  free(path);
}

/*effectively prepends name of current dir, and then makes a
recursive call to the parent, going up this n-ary tree.
We realloc the path we've built with enough space
for itself AND current->name, in order to add current->name
to the FRONT of the path (prepending it). We prepend by 
storing path in temp, store current->name in path, then conctenate
temp onto path. 

Once current->parent is NULL, we are at the 
root (our base case) so return the path.*/
char* pwd_helper(Unix *current, char *path){
  char *temp_store_path;

  /*if at the root, base case returns path*/
  if (current->parent_dir == NULL){
    /*increases space of path to accomodate current name we're about
    to add*/
    path = realloc(path, strlen(current->name) + strlen(path) + 2);
    if (path == NULL)
      return 0;

    /*store current path in temp (not including current)*/
    temp_store_path = malloc(strlen(path) + 1);
    strcpy(temp_store_path, path);
    /*overwrite path with current name*/
    strcpy(path, current->name);
    /*concatenate original path stored in temp. last
      param used to cut off slash from string*/
    strncat(path, temp_store_path, strlen(temp_store_path) - 1);
    free(temp_store_path);

    return path;
  }
  /*case for the first call, the path is currently empty*/
  if (strlen(path) == 0){
    path = malloc(strlen(current->name) + 1);
    strcpy(path, current->name);
  }  
  /*otherwise, recursive call continues upwards*/
  else {
    /*increases space of path to accomodate current name we're about
    to add*/
    path = realloc(path, strlen(current->name) + strlen(path) + 2);
    if (path == NULL)
      return 0;
    /*store current path in temp*/
    temp_store_path = malloc(strlen(path) + 1);
    strcpy(temp_store_path, path);

    /*overwrite path with current name*/
    strcpy(path, current->name);
    /*concatenate original path stored in temp.*/
    strcat(path, temp_store_path);
    free(temp_store_path);
  }
  /*recursive call to parent*/
  return pwd_helper(current->parent_dir, path);
}





/*Removes and frees up all files/dirs within the filesystem. Helper function
does majority of the work, we pass in the list of 
items within the root directory into rmfs_helper. Helper is
unable to free the root itself, root is manually freed after
recursive function.*/
void rmfs(Unix *filesystem){
  /*if children2 of children1 is an empty list, free children1*/
  if (filesystem == NULL)
    return;

  /*free everything besides root*/
  /*begin with root dir*/
  rmfs_helper(filesystem->root->head_child);

  /*free root now that all below root is freed*/
  free(filesystem->root->name);
  free(filesystem->root);
}

/*Loop through child list of each child within child list. if a child 
  doesnt have a child, free that child because it is 
  a leaf. if a child DOES have a child, recursive call the 
  child of the child. Ultimately the leaves of this n-ary tree
  are freed up*/
void rmfs_helper(Unix *root){
  Unix *current;
  Unix *temp_next;

  current = root;
  while (current != NULL){
    temp_next = current->next;
    /*if this child has children, recursive call to make
      this child = root param*/
    if (current->head_child != NULL){
      rmfs_helper(current->head_child);
      /*finished freeing sub files, so now free current dir*/
      free(current->name);
      free(current);
    }
    /*we are at a leaf, so free this leaf*/
    else {
      free(current->name);
      free(current); 
    }
    /*traverse*/
    current = temp_next;
  }

  /*exit recursive call*/

  return;
}



/*Removes and frees individual file or dir. If removing a dir,
all files/dirs below the dir must be freed as well. Freeing all below dir
uses recursive call of rmfs_helper, since rmfs helper frees 
all within a dir.*/
int rm(Unix *filesystem, const char arg[]){
  Unix *current;
  Unix *temp;
  char *arg_copy;

  /*null check*/
  if (filesystem == NULL)
    return 0;

  /*any of these as an arg are also error*/
  if (strcmp(arg, ".") == 0 || strcmp(arg,"..") == 0
   || strcmp(arg,"/") == 0 || strlen(arg) == 0)
    return 0;

  /*if contains a "/"" and isnt a single "/"*/
  if ((strlen(arg) > 1) && strchr(arg, '/') != NULL)
    return 0; 

  /*makes copy of arg name, appends "/" to
  mark as dir*/
  arg_copy = malloc(strlen(arg) + 2);
  if (arg_copy == NULL)
    return 0;

  strcpy(arg_copy, arg);
  strcat(arg_copy, "/");

  /*empty dir means arg isnt present*/
  if (filesystem->current_dir->head_child == NULL)
    return 0;

  /*start current at head of current dir, since thats
    what we're searching*/
  current = filesystem->current_dir->head_child;
  /*if arg is the head, remove the head and reassign head*/
  if (strcmp(current->name, arg) == 0 
    || strcmp(current->name,arg_copy) == 0 ){
    if (current->is_dir == 0){ 
      filesystem->current_dir->head_child 
          = filesystem->current_dir->head_child->next;
      free(current->name);
      free(current);
    }
    /*else it is a dir*/
    else {
      /*reassigns head*/
      filesystem->current_dir->head_child 
          = filesystem->current_dir->head_child->next;
      /*recursively free and remove all within dir*/
      rmfs_helper(current->head_child);
      free(current->name);
      free(current);
    }
    free(arg_copy);
    return 1;
  }


  /*now searching for file/dir within the list, before head case 
  already checked*/
  while (current->next != NULL){
    /*if we find a file of arg name, remove it and return 1*/
    if (strcmp(current->next->name, arg) == 0 
        || strcmp(current->next->name, arg_copy) == 0){
      if (current->is_dir == 0){ 
        /*save current->next to be freed later*/
        temp = current->next;
        /*fix next pointer*/
        current->next = current->next->next;
        free(temp->name);
        free(temp);
      }
      /*else it is a dir*/
      else {
        /*save current->next to be freed later*/
        temp = current->next;
        /*recursive call re*/
        rmfs_helper(current->next->head_child);
        /*fix next pointer*/
        current->next = current->next->next;
        free(temp->name);
        free(temp);
      }
      free(arg_copy);
      return 1;
    }
    current = current->next;
  }
  /*arg wasnt found in directory, so error case*/
  free(arg_copy);
  return 0;
}