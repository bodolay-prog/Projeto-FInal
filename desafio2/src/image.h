#ifndef IMAGE_H
#define IMAGE_H

void filePath(const char *, char *, char *);
unsigned char* readPGM(const char *, unsigned *, unsigned *);
void writeSave(const char *, unsigned char *, unsigned, unsigned);

#endif