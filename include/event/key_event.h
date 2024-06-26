/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:48:16 by svidot            #+#    #+#             */
/*   Updated: 2024/06/26 13:45:56 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_EVENT_H
# define KEY_EVENT_H

# include "mlx.h"
# include "se_mini_struct.h"

void	reset(t_data *data);
void	reset_cam(t_data *data);
void	trsl_cam(t_cam *cam, t_matrix_vector *vect, double values[]);
void	actual_mesh_handle(t_data *data, t_obj *mesh,
			t_matrix_vector **origin_vect, t_matrix_vector **dir_vect);
void	trsl_about_cam(t_cam *cam, t_matrix_vector *vect, double values[]);
void	chang_mesh_size(t_data *data, int keycode);
void	event_intensity(int keycode, double *intensity);
void	cam_event_rotate(int keycode, t_cam *cam);
void	event_rotate(int keycode, t_matrix_vector *vector);
void	event_translate(int keycode,
			void (*trsl_mesh)(t_cam *cam, t_matrix_vector *vect,
				double values[]), t_cam *cam, t_matrix_vector *vect);
void	meta_keycode(int keycode, t_data *data, t_mlx *mlx);

#endif