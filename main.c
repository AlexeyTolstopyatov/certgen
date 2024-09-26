#include "framework/certificate.h"
#include "framework/base64.h"

//
// Prints help page
//
void help(void) {
    // TODO: Support of ASN "--asn1" parameter
    // TODO: Support of toFile "--file" parameter
    // TODO: "--word" parameter for generate special comments

    printn("Use this secondary arguments for working");
    printn("\t--w\tInsert special comments in file");
    printn("\t--a\tCreate ASN 1 structure of certificate");
    printn("\t--f\tWrite information to file");
    printn("\t--x\tPrints HEX view of certificate");
    nprintn("Primary argument - current certificate's path");
    printn(">> ./cert myc.crt\t# Prints properties");
    printn(">> ./cert myc.crt --w\t# Prints properties and 'cert' comments");
    printn(">> ./cert myc.crt --a\t# Prints ASN v1 structure of certificate");
    printn(">> ./cert myc.crt --f\t# Prints and writes data to 'myc.txt'");
    printn("");
    exit(0);
}

//
// DER Certificate processing logic
//
void bin(char * args[]) {
    // Parsing "--hex" flag
    // If columns implictly setted, build table
    cinit(args[1]);
    if (strcmp(args[2], "--hex") == 0) {
        if (args[3] == NULL) cprinth();
        else cprinthc(atoi(args[3]));
    }
    // Parsing "--asn" flag
    if (strcmp(args[2], "--asn") == 0) cprintt();

}

//
// PEM Certificate processing logic
//
void base64(char *args[]) {

}
//
// Cуществуют следующие типы кодировки сертификатов:
// PEM — использует кодировку Base64 ASCII.
// PKCS#7 — использует кодировку Base64 ASCII с расширением .p7b или .p7c.
// DER — содержит сертификаты в двоичной форме, в формате .der или .cer.
// PKCS#12 — содержит сертификаты в двоичной форме, в формате .pfx или .p12.
//
int main(int argc, char * argv[]) {
    nprintn("Open Certificate parsing tool");
    printn("Made by Alexey Tolstopyatov 2024. \n");

    if (argc <= 2 || argv[2] == NULL)
        help();

    if (cinit(argv[1]) == NULL) {
        cfree();
        printf("Unable to open %s", argv[1]);
        return 1;
    }

    if (ispem()) {
        base64(argv);
    }
    if (isbin()) {
        bin(argv);
    }

    cfree(); // Close all handles.
    printn("");
    return 0;
}
