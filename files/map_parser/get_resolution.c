/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:26:34 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/28 20:30:40 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		get_size(int i, const char *line)
{
	int size;

	size = 0;
	if (line[i] && ft_isdigit(line[i]))
		while (line[i] && ft_isdigit(line[i]))
			size *= 10 + (line[i++] - '0');
	else
		error_manager(20, NULL);
	return (size);
}

t_window_size	get_resolution(t_list *lst)
{
	t_window_size	window;

	
}