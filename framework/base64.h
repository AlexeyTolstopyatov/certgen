//
// Created by MagicBook on 24.08.2024.
// Taken from StackOverFlow
//

#ifndef CERT_BASE64_H
#define CERT_BASE64_H

#include <stdint.h>
#include "co.h"

char * benc(
        const unsigned char *data,
        size_t input_length,
        size_t *output_length);

unsigned char * bdec(
        const char *data,
        size_t input_length,
        size_t *output_length);

void bdect(void);
void bfree(void);
void balloc(void);

#endif //CERT_BASE64_H
