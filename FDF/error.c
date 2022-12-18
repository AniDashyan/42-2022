#include "fdf.h"

void    error(char  *err_msg)
{
    perror(err_msg);
    exit(1);
}
