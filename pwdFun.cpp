#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void pwdFun() {
  char cwd[PATH_MAX+1];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("Directory is: %s\n", cwd);
  }
  else {
    perror("Error Message");
  }
}
