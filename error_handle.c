/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:43:18 by mohamoha          #+#    #+#             */
/*   Updated: 2025/01/15 21:13:02 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

void	error_handle(void)
{
	putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int		check_empty(char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i][0] == '\0')
			return 0;
		i++;
	}
	return (1);
}

void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
