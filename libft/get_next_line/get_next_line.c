/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:53:08 by gude-cas          #+#    #+#             */
/*   Updated: 2023/06/16 15:19:43 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content = update_content(content, fd);
	if (!content)
		return (NULL);
	line = extract_line(content);
	content = new_content(content);
	return (line);
}

char	*update_content(char *content, int fd)
{
	char	*temp;
	int		size;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	size = 1;
	while (!ft_strchr(content, '\n') && size)
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (size == -1)
		{
			free(temp);
			free(content);
			return (NULL);
		}
		temp[size] = '\0';
		content = ft_strjoin(content, temp);
	}
	free(temp);
	return (content);
}

char	*extract_line(char *content)
{
	char	*line;
	int		i;

	if (!ft_strlen(content))
		return (NULL);
	i = 0;
	while (content[i] != '\n' && content[i])
		i++;
	if (content[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i-- != '\0')
		line[i] = content[i];
	return (line);
}

char	*new_content(char *content)
{
	char	*new_content;
	int		i;
	int		j;

	if (!content)
		return (NULL);
	i = 0;
	while (content[i] != '\n' && content[i])
		i++;
	if (content[i] == '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (NULL);
	}
	new_content = malloc((ft_strlen(content) - i) + 1);
	if (!new_content)
		return (NULL);
	j = 0;
	while (content[i])
		new_content[j++] = content[i++];
	new_content[j] = '\0';
	free(content);
	return (new_content);
}
