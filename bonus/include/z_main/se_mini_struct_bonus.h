/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_mini_struct_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:40:22 by svidot            #+#    #+#             */
/*   Updated: 2024/06/29 16:30:56 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**========================================================================
 *                             SETTINGS
 * change BUMP_SCALE value for texturization "intensity"
 * modify WIDTH and/or Height resolution
 * other values should better be let untouched...
 *========================================================================**/
#ifndef SE_MINI_STRUCT_BONUS_H
# define SE_MINI_STRUCT_BONUS_H

# define BUMP_SCALE 0.001
# define WIDTH 1200
# define HEIGHT 900
# define AXIS 3
# define MTX 4
# define BIG_VALUE 100000000
# define XPM_SIZE 7000

# include <stdio.h>
# include "se_color_image_bonus.h"
# include "se_ray_vector_bonus.h"
# include "se_camera_bonus.h"
# include "se_geometry_bonus.h"
# include "se_general_bonus.h"
# include "se_lighting_bonus.h"
# include "se_events_bonus.h"
# include "se_exit_bonus.h"
# include "se_funcs_params_bonus.h"

typedef struct s_data
{
	int				is_gen_vid;
	int				is_test;
	int				refresh;
	int				sp_nbr;
	int				pl_nbr;
	int				cy_nbr;
	int				sl_nbr;
	int				tr_nbr;
	t_event			event;
	t_cam			cam;
	t_sphere		*spheres;
	t_cylinder		*cylinders;
	t_plane			*planes;
	t_triangle		*triangles;
	t_spotlight		*spotlights;
	t_ambiant_light	ambiant_light;
	struct s_data	*data_cpy;
	char			img_ref[20];
	char			*bump_map_paths[100];
	double			***bump_maps;
}	t_data;

#endif