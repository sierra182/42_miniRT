#include "check_file.h"

/**========================================================================
 *                           is_rt_file
 *========================================================================**/
int	is_rt_file(char *map_path)
{
	while (*map_path)
	{
		if (ft_strncmp(map_path, ".rt", 4) == 0)
			return (1);
		map_path++;
	}
	return (0);
}

/**========================================================================
 *                           file_exists
 *========================================================================**/
int	file_exists(char *map_path)
{
	int		map_fd;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (0);
	close(map_fd);
	return (1);
}