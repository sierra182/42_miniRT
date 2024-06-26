/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:32:06 by svidot            #+#    #+#             */
/*   Updated: 2024/06/26 13:32:07 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUMP_MAPPING_BONUS_H
# define BUMP_MAPPING_BONUS_H

# include "se_mini_struct_bonus.h"
# include "x_linear_algebra_bonus.h"

double	get_bump_coef(t_sphere *sphere, double **bump_map, double u, double v);
void	calculate_tangent(t_ray_vector *normal, t_ray_vector *t);
void	calculate_bitangent(t_ray_vector *n, t_ray_vector *t, t_ray_vector *b);
void	calculate_bump_derivatives(t_calculate_bump_derivatives_params *p);

#endif