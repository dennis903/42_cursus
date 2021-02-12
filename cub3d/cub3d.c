#include "cub3d.h"

int				main(int argc, char *argv[])
{
	int			fd;

	if (argc != 2)
		return (ERROR);
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		printf("file open error\n");
		return (ERROR);
	}
	if (parse_cub(fd) == ERROR)
	{
		printf("cub parse error\n");
		return (ERROR);
	}
	printf("width : %d\n height : %d\nnorth : %s\nsouth : %s\neast : %s\nwest : %s\nsprite : %s\nred : %d\ngreen : %d\nblue : %d", md.width, md.height, md.north, md.south, md.east, md.west, md.sprite, md.f->red, md.f->green, md.f->blue);
	return (0);
}