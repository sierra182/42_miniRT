#ifndef SE_GEOMETRY_BONUS_H
# define SE_GEOMETRY_BONUS_H

typedef enum e_cyl_or_discs
{
	cylinder,
	discs
}	t_cyl_or_discs;

typedef struct s_sphere
{
	int				bump_map_nbr;
	int				checkerboard;
	char			*bump_map_path;
	t_matrix_vector	origin_vect;
	double			diameter;
	double			radius;
	double			square_radius;
	t_color			color;
	int				which_t;
	double			t1;
	double			t2;
	double			rotation_angle_x;
	double			rotation_angle_y;
	t_matrix_vector	*vector;
}	t_sphere;

typedef struct s_cylinder
{
	int				checkerboard;
	double			proj;
	t_matrix_vector	origin_vect;
	t_matrix_vector	axis_vect;
	double			diameter;
	double			radius;
	double			square_radius;
	double			height;
	t_color			color;
	int				which_t;	
	t_cyl_or_discs	cyl_or_discs;
	t_ray_vector	intersec_point;
	t_ray_vector	origin_proj;
	double			t1;
	double			t2;
}	t_cylinder;

typedef struct s_plane
{
	int				bump_map_nbr;
	char			*bump_map_path;
	int				checkerboard;
	t_matrix_vector	origin_vect;
	t_matrix_vector	norm_vect;
	t_color			color;

}	t_plane;

typedef struct s_triangle
{
	t_matrix_vector	point_a;
	t_matrix_vector	point_b;
	t_matrix_vector	point_c;	
	t_color			color;
	t_ray_vector	e1;
	t_ray_vector	e2;
}	t_triangle;

#endif