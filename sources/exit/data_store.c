/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:35:28 by seblin            #+#    #+#             */
/*   Updated: 2024/04/26 17:04:51 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_store.h"

void	store_and_free_mlx(t_exit *exit, void *mlx)
{
	if (exit && mlx)
		exit->mlx = (t_mlx *) mlx;
	else if (exit && exit->mlx)
	{
		mlx_destroy_window(exit->mlx->connect, exit->mlx->window);
		mlx_destroy_display(exit->mlx->connect);
		free(exit->mlx->connect);
		exit->mlx = NULL;
	}
}

t_mlx	*get_mlx(void)
{
	return (get_exit_struct()->mlx);
}
