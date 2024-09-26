cmake_minimum_required(VERSION 3.25)
project(cert C)

set(CMAKE_C_STANDARD 99)

add_executable(cert main.c framework/der.h framework/certificate.c framework/certificate.h framework/der.c framework/co.c framework/co.h framework/base64.c framework/base64.h)
