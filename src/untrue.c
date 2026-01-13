#include "stdio.h"
#include "../include/parser.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		// Parse config file & store data
		// Check if db exist create new one if not
		// Check folder specified in config file.
		// Compare hash
		// create report
		parser(av[1]);
	}

	return (0);
}
