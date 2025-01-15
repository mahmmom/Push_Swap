/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:34:56 by mohamoha          #+#    #+#             */
/*   Updated: 2023/10/31 19:33:15 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joint;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	joint = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joint)
		return (NULL);
	while (s1[i] != '\0')
	{
		joint[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		joint[j++] = s2[i++];
	}
	joint[j] = '\0';
	return (joint);
}
