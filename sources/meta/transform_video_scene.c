# include "se_mini_struct.h"
# include "x_matrix.h"

void	rotate_mesh(t_matrix_vector *vect, double angle, int axe[]);
void	trsl_mesh(t_cam *cam, t_matrix_vector *vect, double values[]);
double	*symmetrize_vector(double vect[]);
void	rotate_cam(t_cam *cam, double angle, int axe[]);
void	trsl_cam(t_cam *cam, t_matrix_vector *vect, double values[]);
void	trsl_about_cam(t_cam *cam, t_matrix_vector *vect, double values[]);

void	video_trans_mesh(void *mesh, int mesh_num, int mesh_nbr)
{
	t_cylinder	*cyl;

	cyl = (t_cylinder *)mesh;

	if (mesh_num < 24)
		return ;
	trsl_mesh(NULL, &cyl->origin_vect, (double[3]){0, 0, -1});

}

void	video_rotate_cogs(t_cylinder *cyl, int	i, int cyl_nbr)
{
	int axe[3];
	t_ray_vector point;
	double angle = -3.33;
	static int l = 0;
	static int k = 0;
	static int j = 1;
	if (l == 16 * cyl_nbr)
	{
		l = 0;
		j = -j;
	}

	
	if (i < 24)
	{
		angle = 2;
		axe[0] = 0;
		axe[1] = 1;
		axe[2] = 0;
		rotate_mesh(&cyl->axis_vect, angle, axe);
	}
	else if (i < 40)
	{
		axe[0] = 0;
		axe[1] = 1;
		axe[2] = 0;
		rotate_mesh(&cyl->axis_vect, angle, axe);
	}
	else if (i < 56)
	{
		axe[0] = 0;
		axe[1] = 0;
		axe[2] = 1;
		rotate_mesh(&cyl->axis_vect, angle, axe);
	}
	else if (i < 58)
	{
		angle = 3.1;
		if (j == -1)
			angle = -3.1;

		point.axis[0] = cyl->axis_vect.axis[0];
		point.axis[1] = cyl->axis_vect.axis[1] - 120;	
		point.axis[2] = cyl->axis_vect.axis[2];

		trsl_mesh(NULL, &cyl->origin_vect, point.axis);

		axe[0] = 1;
		axe[1] = 0;
		axe[2] = 0;
		rotate_mesh(&cyl->axis_vect, angle, axe);

		symmetrize_vector(point.axis);
		trsl_mesh(NULL, &cyl->origin_vect, point.axis);
	}

		
	

	
	k++;
	l++;


}


void	rotate_pendulum(t_sphere *sphere, int i)
{
	int axe[3];
	static int j = 0;
	static double angle = 2;

	if (j == 16)
	{
		j = 0;
		angle = -angle;
	}
	t_ray_vector point;

	point.axis[0] = 0;
	point.axis[1] = -60;
	point.axis[2] = 0;


	
	trsl_mesh(NULL, &sphere->origin_vect, point.axis);
	axe[0] = 1;
	axe[1] = 0;
	axe[2] = 0;
	rotate_mesh(&sphere->origin_vect, angle, axe);
	symmetrize_vector(point.axis);
	trsl_mesh(NULL, &sphere->origin_vect, point.axis);

	j++;
}