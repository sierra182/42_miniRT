/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:38:40 by svidot            #+#    #+#             */
/*   Updated: 2024/06/26 13:38:41 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include "se_mini_struct_bonus.h"

int		init_data(char *map_path, t_data *data);
int		key_event(int keycode, void *param);
int		mouse_event(int button, int x, int y, void *param);
void	display_error(char *error);
int		parse(char *map_path);
void	multy_thrd_launch_rays(t_mlx *mlx, t_data *data);
int		key_up_event(int keycode, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		generate_video_frames(t_data *data, char **envp);
void	is_it_a_test(t_data *data, char **envp);
int		init_mlx(t_mlx *mlx);
void	launch_mlx_loop(t_mlx *mlx, t_data *data);
void	init_img_item(t_mlx *mlx, t_img *img, char *str, int color);
int		frame(void *param);
void	free_paths(t_data *data);

#endif