//
// Created by MagicBook on 23.08.2024.
//
#include "certificate.h"

///
///      String Content's comparison
///
/// Returns 0 (FALSE)
/// If ANY char in two strings not equal char
/// with same index in another string.
/// Length of two Strings MUST be same.
///
/// Returns -1 (NULL result)
/// If length of two strings ARE NOT the same.
///
/// Returns +1 (TRUE)
/// If ANY char in str1 equal the char in str2.
///
int strccmp(const char str1[], const char str2[]) {
    if (strlen(str1) != strlen(str2)) {
        printf("\nLEFT: %llu\nRIGHT: %llu\n", strlen(str1), strlen(str2));
        printf("%s\n%s\n", str1, str2);
        return -1;
    }

    for (size_t i = 0; i < strlen(str1); ++i)
        if (str1[i] != str2[i]) return 0;

    return +1;
}

///
///      Certificate structure Initialize
///
/// Opens object with "read binary" attributes.
/// Use "cfree" for close all file handles
///
/// Returns initialized structure
///
FILE * cinit(char path[]) {
    cert = fopen(path, "rb");
    printf("Opened file: %s\nAllocated: %x\n",
           path,
           cert->_cnt);

    return cert;
}

///
///      Certificate structure free
///
/// Drop initialized structures and pointers
/// from memory. Use it in the end of all operations.
///
void cfree(void) {
    printn("Memory wants to break free.");
    fclose(cert);
    cert = NULL;
}

///
///      Is PEM signature detected ?
///
/// Checking Enchaned mail signature.
/// Returns 1, If PEM signature detected
/// Returns 0, If nothing same not been detected.
///
// LEFT: 27     (bstr[])
// RIGHT: 30    (buff[])
// -----BEGIN CERTIFICATE-----
// Ў----BEGIN CERTIFICATE-----
// FAIL
// strccmp returned 0xffffffff (-1)
int ispem(void) {
    printf("Searching Privacy Enchaned Mail sign...");
    char bstr[28] = "-----BEGIN CERTIFICATE-----";
    char buff[28];


    // 0x2d
    // Разница до сих пор существует.
    // Почему в строке из 28 байт есть 30 байт?
    //
    fseek(cert, 0, 0);
    fread(&buff, sizeof(unsigned char), 28, cert);
    int result = strccmp(bstr, buff);

    if (result == 1) {
        printf("OK. \nstrccmp returned 0x%x (%d)\n", result, result);
        return +1;
    }

    printf("FAIL\nstrccmp returned 0x%x (%d)\n", result, result);
    return 0;
}

///
///      Is Distinguished Encoding rules used?
///
/// Returns 1, If Cannonical/Distinguished-encoding rules
/// been detected inside object.
///
int isbin(void) {
    //      Если я правильно понимаю, сертификаты безопасности,
    // зашифрованные таким образом, должны начинаться с
    // основной последовательности элементов.
    // seq(x counts) {
    //     utf8 "data"
    //     ... etc
    // }
    //

    printf("Searching Distinguished Encoding rules...");

    int result = 0; // hex view of first sequence's object
    fseek(cert, 0, 0);
    fread(&result, sizeof(unsigned char), 1, cert);

    if (result == DER_SEQ) {
        printn("OK");
        return +1;
    }
    printn("FAIL");
    return 0;
}

///
/// Certifiate Print Hex-view
///
void cprinth(void) {
    cprinthc(64);
}

///
///      Certificate Print HEX-view by Columns\n
///
/// Prints table of certificate's content using implict
/// count of columns.
/// Columns limit = 255.
/// Default columns limit (in cprinth) = 64.
///
void cprinthc(int clim) {
    clim > 80 ? clim = 80 : clim;
    clim--;

    int buffer;
    int colc = 0;
    while (1) {
        buffer = fgetc(cert);

        if (feof(cert)) {
            break;
        }
        if (colc == clim) {
            colc = 0;
            printn(""); // new line
        }
        printf("%02x ", buffer);
        colc++;
    }
}

///
///     Certificate Print syntax Tree
///
/// My main task is builder of Abstract Syntax tree
/// Don't know, how many file and time it costs, but i do it.
///
void cprintt(void) {
    // Если правильно понял, надо проверить
    // 1) Длинну структуры + 1
    // 2) Тип данных
    int len = 0; // Счетчик длины
    int type = 0; // Счетчик типа

    // Первый байт = Тип данных

    while (1) {
        if (feof(cert)) break;

    }
}
