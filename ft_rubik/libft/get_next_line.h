#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H



# define BUFF_SIZE 9000



# include <sys/types.h>

# include <sys/uio.h>

# include <unistd.h>

# include <stdlib.h>

# include "libft.h"



int        get_next_line(int const fd, char **line);



#endif