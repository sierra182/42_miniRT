/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:53:05 by svidot            #+#    #+#             */
/*   Updated: 2024/06/26 12:53:06 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADOWS_H
# define SHADOWS_H

# include "se_mini_struct.h"
# include "x_linear_algebra.h"

void	get_local_intersect_point(t_ray *ray, double t, t_ray_vector *inter_pt);
double	is_intersect_plane(t_ray *ray, void *input_plane, t_ray_vector *i);
double	is_intersect_cylinder(t_ray *ray, t_cylinder *cylinder,
			t_ray_vector *i);
double	is_intersect_sphere(t_ray *ray, void *input_sphere, t_ray_vector *i);
int		is_in_cylinder(t_ray_vector *normal, t_cylinder *cyl, double mesh[]);
void	get_intersect_point(t_ray *ray, double t, t_ray_vector *inter_pt);

#endif