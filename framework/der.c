//
// Created by MagicBook on 23.08.2024.
//
#include "der.h"

char * typer(int dert){
    switch (dert) {
        case DER_INT:
            return "INTEGER";
        case DER_BITS:
            return "BIT STRING";
        case DER_OBJ:
            return "OBJECT IDENTIFIER";
        case DER_SEQ:
            return "SEQUENCE";
        case DER_SET:
            return "SET";
        case DER_TIME:
            return "GeneralizedTime";
        case DER_UTC:
            return "UTCTime";
        case DER_UTF8:
            return "UTF8String";
        case DER_NULL:
        default:
            return "NULL";
    }
}