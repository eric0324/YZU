/**
 * This program demonstrates invocation of the rename
 * system call (128) using the syscall function.
 */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h> /* For SYS_xxx definitions */

int main(int argc, char *argv[]) {

    syscall (136, argv[1], argv[2] );

}

