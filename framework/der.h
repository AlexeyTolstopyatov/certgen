//
// Created by MagicBook on 23.08.2024.
// Distinguished Encoding Rules file.
//     char * typer(int) -> word of type
//     void tree(x) -> builds ASN from file
//

#ifndef CERT_DER_H
#define CERT_DER_H

//
// Если я помню правильно, "DER" Кодировка
// работает следующим образом:
//  1) Указывается тип данных
//  2) Указывается длинна
//  3) Указываются сами данные в виде последовательности байт
//
// ASN 1 >> INTEGER 8192
// DER   << 02 03 20 00
//

#define DER_INT     0x02 // INTEGER
#define DER_SEQ     0x30 // SEQUENCE
#define DER_OBJ     0x06 // OBJECT IDENTIFIER
#define DER_UTC     0x17 // UTC Time
#define DER_TIME    0x18 // Generalized Time
#define DER_SET     0x31 // SET
#define DER_UTF8    0x0c // UTF-8 String
#define DER_BITS    0x03 // BIT STRING
#define DER_NULL    0x05 // NULL

char * typer(int dert);

#endif //CERT_DER_H
