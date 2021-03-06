/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:35:05 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/06 14:59:22 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void free_ids(t_cub3d *cub)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (cub->ids[i].id)
			if (cub->ids[i].line)
				free(cub->ids[i].line);
		i++;
	}
	free(cub->ids);
}

static void free_tex_path(t_cub3d *cub)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (cub->tex_path[i])
			free(cub->tex_path[i]);
		i++;
	}
}

void		free_cub(t_cub3d *cub)
{
	free_ids(cub);
	free_tex_path(cub);
	free(cub);
}
