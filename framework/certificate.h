//
// Created by MagicBook on 23.08.2024.
// New Certificate's structure
//
#ifndef CERT_ARGS_H

#include "co.h"
#include "der.h"

static FILE * cert = NULL;

///
/// Ejected data from file
///
struct CERTIFICATE {
    char * c_author;
    char * c_limit;

};

FILE * cinit(char path[]);
int strccmp(
        const char str1[],
        const char str2[]);

void cfree(void);
int  ispem(void);
int  isbin(void);
void cprintt(void);
void cfprintf(void);
void cprinth(void);
void cprinthc(int clim);

#endif //CERT_ARGS_H

