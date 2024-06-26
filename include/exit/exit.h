/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:48:43 by svidot            #+#    #+#             */
/*   Updated: 2024/06/26 12:48:44 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <stdlib.h>
# include "se_mini_struct.h"

typedef void	(*t_getsaf)(t_exit *, void *);
void			store_and_free_mlx(t_exit *exit, void *mlx);
void			store_and_free_spheres(t_exit *exit, void *spheres);
void			store_and_free_cylinders(t_exit *exit, void *cylinders);
void			store_and_free_planes(t_exit *exit, void *planes);
void			store_and_free_data_copy(t_exit *exit, void *data_cpy);

#endif