/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:14:26 by adben-mc          #+#    #+#             */
/*   Updated: 2021/12/08 04:06:58 by adben-mc         ###   ########.fr       */
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
	while (!ft_strchr(str, '\n') && statut)
	{
		statut = read(fd, temp, BUFFER_SIZE);
		temp[statut] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

/*
Fonction qui return ce qui est avant le \n et alloue dans la variable 
static le reste de la chaine de caractere
*/

char	*find_line(char *save)
{
	char	*str;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
Fonction qui va clear une chaine de caractere .
*/

char	*find_rest_clear(char	*save)
{
	char	*str;
	int		i;
	int		x;

	i = 0;
	while (save[i] != '\n' && ft_strchr(save, '\n'))
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (NULL);
	if (ft_strchr(save, '\n'))
		i++;
	x = 0;
	while (save[i])
		str[x++] = save[i++];
	str[x] = '\0';
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*str;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_fill_str(fd, save);
	if (!save)
		return (NULL);
	str = find_line(save);
	save = find_rest_clear(save);
	return (str);
}
