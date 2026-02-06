/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:51:28 by msedeno-          #+#    #+#             */
/*   Updated: 2025/06/12 19:58:47 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open ("file.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free (line);
	}
	free (line);
	close(fd);
	return (0);
}


// int main (void)
// {
// 	int	fd1 = open ("file.txt", O_RDONLY);
// 	int	fd2 = open ("get_next_line.c", O_RDONLY);
// 	int	fd3 = open ("fget_next_line.h", O_RDONLY);
// }
