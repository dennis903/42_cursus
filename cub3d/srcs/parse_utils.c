#include "../cub3d.h"

int				count_splits(char **splits)
{
	int			count;

	count = 0;
	while (splits[count])
		count++;
	return (count);
}

int				set_base_data(char **splits)
{
	int			split_length;

	split_length = count_splits(splits);
	if (split_length != 2)
		return (ERROR);
	if (ft_strcmp(splits[0], "R") == 0)
		return (save_r(splits));
	else if (ft_strcmp(splits[0], "NO") == 0)
		return (save_texture(splits));
	else if (ft_strcmp(splits[0], "SO") == 0)
		return (save_texture(splits));
	else if (ft_strcmp(splits[0], "EA") == 0)
		return (save_texture(splits));
	else if (ft_strcmp(splits[0], "WE") == 0)
		return (save_texture(splits));
	else if (ft_strcmp(splits[0], "S") == 0)
		return (save_texture(splits));
	else if (ft_strcmp(splits[0], "F") == 0)
		return (save_color(splits));
	else if (ft_strcmp(splits[0], "c") == 0)
		return (save_color(splits));
	return (0);
}