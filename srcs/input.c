/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:47:48 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/02 19:28:55 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	set_head(t_grid *panel, char *buff)
{
	unsigned int	len;
	unsigned int	i;

	if (format_check_newline(buff) < 2)
		return (0);
	len = my_strlen_line(buff);
	panel->buff_head = malloc(sizeof(char) * (len + 1));
	if (panel->buff_head == NULL)
		return (0);
	i = my_strlcpy(panel->buff_head, buff, len + 1);
	buff += len + 1;
	len = my_strlen(buff);
	panel->buff_map = malloc(sizeof(char) * (len + 1));
	if (panel->buff_map == NULL)
		return (0);
	i = my_strlcpy(panel->buff_map, buff, len + 1);
	(void)i;
	panel->flag = 1;
	return (1);
}

int	input_map(t_grid *panel, char *filename)
{
	char	*buff;

	buff = input_str(filename);
	if (buff == NULL)
		return (0);
	if (!set_head(panel, buff))
	{
		free(buff);
		return (0);
	}
	free(buff);
	return (1);
}
