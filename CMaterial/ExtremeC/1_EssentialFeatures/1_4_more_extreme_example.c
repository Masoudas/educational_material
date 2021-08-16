/**
 * Consider the following example. Note that # before the name of a macro puts the argument into quotation (we don't 
 * have a "${}" here :D.) 
 * 
 * Moreover, ## is a concatenation argument. It will attach anything that's before and after it.
 * 
 * As such, the final preprocessed code is as follows":
...
... content of stdio.h ...
...
... content of string.h ...
...
int main(int argc, char** argv) {
  char copy_cmd[256] = ""; strcpy(copy_cmd, "copy");
  char paste_cmd[256] = ""; strcpy(paste_cmd, "paste");
  char cut_cmd[256] = ""; strcpy(cut_cmd, "cut");
  char cmd[256];
  scanf("%s", cmd);
  if (strcmp(cmd, copy_cmd) == 0) {
  }
  if (strcmp(cmd, paste_cmd) == 0) {
  }
  if (strcmp(cmd, cut_cmd) == 0) {
  }
  return 0;
}

 */


#include <stdio.h>
#include <string.h>
#define CMD(NAME) \
  char NAME ## _cmd[256]  = ""; \
  strcpy(NAME ## _cmd, #NAME);
int main(int argc, char** argv) {
  CMD(copy)
  CMD(paste)
  CMD(cut)
  char cmd[256];
  scanf("%s", cmd);
  if (strcmp(cmd, copy_cmd) == 0) {
    // ...
  }
  if (strcmp(cmd, paste_cmd) == 0) {
    // ...
  }
  if (strcmp(cmd, cut_cmd) == 0) {
    // ...
  }
  return 0;
}