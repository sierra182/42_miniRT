/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multy_thrd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:48:41 by svidot            #+#    #+#             */
/*   Updated: 2024/06/27 14:38:37 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multy_thrd_bonus.h"

/**========================================================================
 *                            FREE_DATA_COPY
 *========================================================================**/
static void	free_data_copy(t_data *data_cpy)
{
	free(data_cpy->spheres);
	data_cpy->spheres = NULL;
	free(data_cpy->cylinders);
	data_cpy->cylinders = NULL;
	free(data_cpy->planes);
	data_cpy->planes = NULL;
	free(data_cpy->triangles);
	data_cpy->triangles = NULL;
	free(data_cpy->spotlights);
	data_cpy->spotlights = NULL;
}

/**========================================================================
 *                        CLOSE_MULTY_THRD_LAUNCH_RAYS
 *========================================================================**/
static void	close_multy_thrd_launch_rays(t_mlx *mlx, t_data *data,
	t_launch_rays *lr)
{
	lr->i = -1;
	while (++lr->i < THR)
	{
		pthread_join(lr->tids[lr->i], NULL);
		free_data_copy(&lr->data_copies[lr->i]);
	}
	if (data->event.antia == 1)
	{
		data->event.antia = 2;
		data->refresh = 1;
	}
	else if (data->event.antia == 2)
		data->event.antia = 0;
	if (data->is_test == 1)
		make_bin_file(data, mlx);
}

/**========================================================================
 *                            COPY_DATA
 *========================================================================**/
static void	copy_data(t_data *data, t_data *data_cpy)
{
	*data_cpy = *data;
	data_cpy->spheres = (t_sphere *) ft_calloc(data->sp_nbr,
			sizeof(t_sphere));
	ft_memcpy(data_cpy->spheres, data->spheres, data->sp_nbr
		* sizeof(t_sphere));
	data_cpy->cylinders = (t_cylinder *) ft_calloc(data->cy_nbr,
			sizeof(t_cylinder));
	ft_memcpy(data_cpy->cylinders, data->cylinders, data->cy_nbr
		* sizeof(t_cylinder));
	data_cpy->planes = (t_plane *) ft_calloc(data->pl_nbr,
			sizeof(t_plane));
	ft_memcpy(data_cpy->planes, data->planes, data->pl_nbr
		* sizeof(t_plane));
	data_cpy->triangles = (t_triangle *) ft_calloc(data->tr_nbr,
			sizeof(t_triangle));
	ft_memcpy(data_cpy->triangles, data->triangles, data->tr_nbr
		* sizeof(t_triangle));
	data_cpy->spotlights = (t_spotlight *) ft_calloc(data->sl_nbr,
			sizeof(t_spotlight));
	ft_memcpy(data_cpy->spotlights, data->spotlights, data->sl_nbr
		* sizeof(t_spotlight));
}

/**========================================================================
 *                              GET_MULTIPLE
 *========================================================================**/
static int	get_next_multiple(int nbr)
{
	if (nbr % THR == 0)
		return (nbr);
	else
		return (nbr + (THR - (nbr % THR)));
}

/**========================================================================
 *                          MULTY_THRD_LAUNCH_RAYS
 *========================================================================**/
void	multy_thrd_launch_rays(t_mlx *mlx, t_data *data)
{
	t_launch_rays	lr;

	lr.new_height = get_next_multiple(HEIGHT);
	lr.i = -1;
	while (++lr.i < THR)
	{
		lr.x_stt = -1;
		lr.x_end = WIDTH;
		lr.y_stt = lr.new_height * INV_THR * lr.i - 1;
		lr.y_end = lr.new_height * INV_THR + lr.y_stt + 1;
		copy_data(data, &lr.data_copies[lr.i]);
		lr.multy[lr.i] = (t_multy_threads)
		{
			*mlx, &lr.data_copies[lr.i], lr.x_stt, lr.x_end, lr.y_stt,
			lr.y_end
		};
		pthread_create(&lr.tids[lr.i], NULL, launch_rays,
			&lr.multy[lr.i]);
	}
	close_multy_thrd_launch_rays(mlx, data, &lr);
}
