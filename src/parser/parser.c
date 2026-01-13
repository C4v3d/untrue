#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/untrue.h"
#include "../../include/ext.h"
#include "../../include/io_check.h"

#define	MAX_LENGTH 256

void	process_line(t_data *data, char *line)
{
	(void)data;
	char	*type = strtok(line, " ");
	line += strlen(type);
	printf("%s\n", line);
	printf("%s\n", type);
}

void	fetch_data(t_data *data, FILE *file)
{
	char	*line = (char*)malloc(MAX_LENGTH);

	(void)data;
	if (!line)
		return ;
	while (fgets(line, MAX_LENGTH, file))
		process_line(data, line);
	free(line);
}

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
	t_data	data;
	FILE	*conf;

	conf = get_config_file(in_file);
	if (!conf)
		return (1);
	fetch_data(&data, conf);
	fclose(conf);
	return (0);
}
