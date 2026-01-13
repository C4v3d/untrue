#include "../../include/io_check.h"
#include <string.h>

int	extcmp(const char *file, const char *ext)
{
	char *file_ext = strrchr(file, '.');
	if (!file_ext)
		return (-1);
	return (strcmp(file_ext, ext));
}
