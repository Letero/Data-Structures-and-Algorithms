#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>

typedef enum eError
{
    E_OK = 0,      // no error
    INVALID_ARG_1, // input invalid argument
    INVALID_ARG_2, //
    OUT_OF_RANGE,  //element out of range
    EMPTY_LIST

} eError_t;

#endif // COMMON_H