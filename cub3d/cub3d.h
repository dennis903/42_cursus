#ifndef CUB3D_H
# define CUB3D_H
# define ERROR					-1
# define SUCCESS				1
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./mlx_dylib/mlx.h"

typedef struct			s_game
{
	void				*mlx;
	void				*win;
	char				**map;
}						t_game;

typedef struct			s_color
{
	int					red;
	int					green;
	int					blue;
}						t_color;

typedef struct			s_map_data
{
	int					width;
	int					height;
	char				*north;
	char				*south;
	char				*east;
	char				*west;
	char				*sprite;
	struct s_color		*f;
	struct s_color		*c;
}						t_map_data;

t_game					game;
t_map_data				md;
int						g_idx_width;
int						g_idx_height;
//parse_cub.c
int						parse_cub(int fd);
//parse_utils.c
int						set_base_data(char **splits);
int						count_splits(char **splits);
//save.c
int						save_r(char **splits);
int						save_texture(char **splits);
int						save_color(char **splits);
//utils1.c
int						make_color(char *splits, t_color **color);
//free.c
void					free_arrs(char **splits);
//parse_map.c
void					parse_map(int fd, t_list **map_list);
char					**fill_map_data(t_list *map_list);
int						get_map_width(t_list *map_list);
int						get_map_height(t_list *map_list);
//map_utils.c
void					copy_map_data(char **map, t_list *map_list);
int						map_valid_check(char **map);
#endif