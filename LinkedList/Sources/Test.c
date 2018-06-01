#include "../Headers/Test.h"

void TEST(eError_t retVal, char *fun_name)
{
    switch (retVal)
    {
    case E_OK:
        printf("Function '%s:\n Error: No error     \tPASS\n\n", fun_name);
        break;
    case INVALID_ARG_1:
        printf("Function %s:\n  Error: INVALID_ARG_1 \tFAIL\n\n", fun_name);
        break;
    case INVALID_ARG_2:
        printf("Function %s:\n  Error: INVALID_ARG_1 \tFAIL\n\n", fun_name);
        break;
    case OUT_OF_RANGE:
        printf("Function %s:\n  Error: OUT_OF_RANGE  \tFAIL\n\n", fun_name);
        break;
    case EMPTY_LIST:
        printf("Function %s:\n  Error: EMPTY_LIST    \tFAIL\n\n", fun_name);
        break;
    }
}