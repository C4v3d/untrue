#include <stdio.h>
#include <stdlib.h>
#include "../../include/ext.h"
#include "../../include/io_check.h"

#define	MAX_LENGTH 256

static FILE	*get_config_file(const char *file)
{
	FILE	*r_file;
	if (extcmp(file, EXT_CONFIG) != 0)
		return (fprintf(stderr, "Wrong file extension"), NULL);
	r_file = fopen(file, "r");
	return (r_file);
}



int	parser(char *in_file)
{
	FILE	*conf;

	conf = get_config_file(in_file);
	if (!conf)
		return (1);
	fetch_data();
	return (0);
}
