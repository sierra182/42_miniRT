# include "se_mini_struct_bonus.h"
# include "x_matrix_bonus.h"
#include "libft.h"
void	video_rotate_cogs(t_cylinder *cyl, int	i, int cyl_nbr);
void	rotate_pendulum(t_sphere *sphere, int i);
void	video_move_cam(t_cam *cam);
void	video_move_light(t_spotlight *light);
void	make_rt_file(t_data *data);

int	generate_video_frames(t_data *data, char **envp)
{
	int	i;

	data->is_gen_vid = 0;
	i = 0;
	while (envp[i])
	{
		// printf("envp[%i] = %s\n", i, envp[i]);
		if (ft_strncmp(envp[i], "VIDEO_GEN=true", 20) == 0)
		{
			data->is_gen_vid = 1;
			break ;
		}
		i++;
	}
	if (data->is_gen_vid == 0)
		return (0);
	i = 0;
	while(i < 32)
	{
		// printf("i = %d\n", i);
		// i = 0;
		// while (i < data->cy_nbr)
		// {
		// 	video_rotate_cogs(&data->cylinders[i], i, data->cy_nbr);
		// 	i++;
		// }
		// rotate_pendulum(&data->spheres[0] , j);
		// video_move_cam(&data->cam);
		// video_move_light(&data->spotlight);
		// make_rt_file(data);
		// j++;
		i++;
	}
	return (1);
}

/**========================================================================
 *                           IS_IT_A_TEST
 *========================================================================**/
void	is_it_a_test(t_data *data, char **envp)
{
	int	i;

	data->is_test = 0;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "AUTOMATED_TEST=true", 20) == 0)
		{
			data->is_test = 1;
			break ;
		}
		if (ft_strncmp(envp[i], "TESTING=true", 13) == 0)
		{
			data->is_test = 2;
			break ;
		}
		i++;
	}
}
