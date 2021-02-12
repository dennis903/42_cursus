#include "../cub3d.h"

int				make_color(char *splits, t_color **color)
{
	int			split_length;
	char		**sub_split;
	t_color		*temp;

	sub_split = ft_split(splits, ',');
	split_length = count_split(sub_split);
	if (split_length != 3)
		return (ERROR);
	if (!(temp = (t_color *)malloc(sizeof(t_color))))
		return (ERROR);
	*color = temp;
	(*color)->red = ft_atoi(sub_split[0]);
	(*color)->green = ft_atoi(sub_split[1]);
	(*color)->blue = ft_atoi(sub_split[2]);
	return (0);
}
