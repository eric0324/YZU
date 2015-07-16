/**
 * This program demonstrates invocation of the rename
 * system call (128) using the syscall function.
 */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
//#include <sys/syscall.h> /* For SYS_xxx definitions */

int main(int argc, char *argv[]) {
  // I use command-line arguments for the command.
  int result = syscall (128, argv[1], argv[2]);
  //int result = syscall (SYS_rename, argv[1], argv[2]); /* use these constants with sys/syscall.h */

  // A result of -1 means that something did not go as planned.
  // I included <errno.h> to give detailed errors for the syscall.

    if (result == -1) {
      printf("rename: `%s`: %s\n", argv[1], strerror(errno));
  }
}
