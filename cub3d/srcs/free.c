#include "../cub3d.h"

void			free_arrs(char **splits)
{
	int			i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
}