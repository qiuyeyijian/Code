#include <stdio.h>

typedef struct Link {
  char ID[30];
  char IP[30];
  int metric;
  struct Link *next;
} Link;

typedef struct Net {
  char prefix[30];
  int metric;
  struct Net *next;
} Net;

typedef struct LSI {
  char RouterID[30];
  Link *nextLink;
  Net *nextNet;
  struct LSI *nextLSI;
} LSI;
