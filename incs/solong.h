#ifndef SOLONG_H
# define SOLONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define FAILURE 1
# define SUCCESS 0

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			w;
	int			h;
	int			bpp;
	int			line;
	int			endian;
}				t_img;

typedef struct s_long
{
	char		**map;
	
}				t_long;

void	sl_check_ber(int ac, char **av);
void	sl_error(char *msg);

#endif

