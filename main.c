#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("example.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	return (0);
}

