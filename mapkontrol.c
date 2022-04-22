#include "so_long.h"

void	ft_map_error(char *error_msg)
/* will print the error message end exit the process */
{
	printf("%s", error_msg);
	exit(0);
}
int	ft_line_length(int fd)
/* bu fonksiyon bir dosyadaki ilk satırın uzunluğunu bulur */
{
	char	buffer[0];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}