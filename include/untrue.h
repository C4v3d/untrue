#ifndef UNCHANGED_H
# define UNCHANGED_H

#include <linux/limits.h>

// Data to fetch
// FROM Config:
// - POLFILE
// - DBFILE
// - REPORTFILE

typedef struct	s_data
{
	char *path_pol[PATH_MAX];
	char *path_db[PATH_MAX];
	char *path_rep[PATH_MAX];
}		t_data;

#endif
