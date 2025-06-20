#ifndef OPS_H
#define OPS_H

int* generation(unsigned, unsigned);
void saveMatrix(const char *, int *, unsigned, unsigned);
int* loadMatrix(const char *, int *, unsigned *, unsigned *);
int* getLBP(int *, unsigned, unsigned);
void writeMatrix(const char *, int *, unsigned, unsigned);

#endif
