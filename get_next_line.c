/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:14:26 by adben-mc          #+#    #+#             */
/*   Updated: 2021/12/08 00:45:19 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Fonction qui met Buffer size dans ma chaine de 
caractere jusqu'a qu'il trouve 
un \n ou la fin de la phrase.
Et me retourne cette chaine de caractere.
*/

char	*ft_fill_str(int fd, char *str)
{
	char	*temp;
	int		statut;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	statut = 1;
	if (!ft_strchr(str, '\n') && statut)
	{
		statut = read(fd, temp, BUFFER_SIZE);
		temp[statut] = '\0';
		ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

/*
Fonction qui return ce qui est avant le \n et alloue dans la variable 
static le reste de la chaine de caractere
*/

char 	*find_line(char *save)
{
	char	*str;
	size_t	i;

	if (!save[0])
		return (NULL);
	i = ft_strchr(save, '\n');
	if (i == 0)
	{
		while
	}
	if (!str)
		return (NULL);
}

/*
Fonction qui va clear une chaine de caractere .
*/

char	*get_next_line(int fd)
{
	static char	*save;
	char *str;

	if (fd < 0 || write(fd, NULL, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	save = ft_fill_str(fd, save);
	if (!str)
		return (NULL);
	str = find_line(save);
	return (str);
}
