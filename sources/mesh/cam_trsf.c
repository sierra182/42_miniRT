#include "se_mini_struct.h"
#include "x_matrix.h"
#include "x_linear_algebra.h"

void	trsl_mesh(t_cam *cam, t_matrix_vector *vect, double values[]);

static void	cast_matrix_cam(t_cam *cam, t_matrix_vector mult_matrix[MTX])
{
	int	i;

	i = -1;
	while (++i < MTX)
		*cam->cam_matrix[i] = mult_matrix[i];
}

void	rotate_cam(t_cam *cam, double angle, int axe[])
{
	t_matrix_vector	mult_matrix[MTX];
	t_matrix_vector	trsf_matrix[MTX];

	init_matrix(trsf_matrix);
	set_matrix_rotation(trsf_matrix, angle, axe);
	multiply_matrix(trsf_matrix, *cam->cam_matrix, mult_matrix);
	cast_matrix_cam(cam, mult_matrix);
}

void	trsl_cam(t_cam *cam, t_matrix_vector *vect, double values[])
{
	t_matrix_vector	scaled_vect;
	double			value;

	if (values[1])
		return (trsl_mesh(NULL, &cam->origin_vect, values));
	if (values[0])
		scale_vector(cam->right_vect.axis, values[0], scaled_vect.axis);
	else if (values[2])
		scale_vector(cam->forward_vect.axis, values[2], scaled_vect.axis);
	add_vector(scaled_vect.axis, cam->origin_vect.axis, cam->origin_vect.axis);
}

void	trsl_about_cam(t_cam *cam, t_matrix_vector *vect, double values[])
{
	t_matrix_vector	scaled_vect;
	double			value;

	if (values[1])
		return (trsl_mesh(NULL, vect, values));
	if (values[0])
		scale_vector(cam->right_vect.axis, values[0], scaled_vect.axis);
	else if (values[2])
		scale_vector(cam->forward_vect.axis, values[2], scaled_vect.axis);
	add_vector(scaled_vect.axis, vect->axis, vect->axis);
}
