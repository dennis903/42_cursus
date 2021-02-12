#include "../cub3d.h"

void			copy_map_data(char **map, t_list *map_list)
{
	int			length;
	int			i;
	int			j;

	i = 0;
	while (map_list)
	{
		length = ft_strlen((char *)map_list->content);
		j = 0;
		while (j < length)
		{
			map[i][j] = ((char *)(map_list->content))[j];
			j++;
		}
		i++;
		map_list = map_list->next;
	}
}

int				map_valid_check(char **map)
{
	
}