#! /bin/sh

# we don't use -Werr because I don't bother to use every variable thus we
# create a lot of unused value warnings
gcc --std=c99 -Wall -Wextra horrors.c
