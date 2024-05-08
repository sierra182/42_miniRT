#include "vector_op.h"

void	normalize_vector(t_ray_vector *vector)
{
	int		i;
	double	magnitude;

	magnitude = sqrt(pow(vector->axis[0], 2) + pow(vector->axis[1], 2)
			+ pow(vector->axis[2], 2));
	if (!magnitude)
		return ;
	i = -1;
	while (++i < AXIS)
		vector->axis[i] /= magnitude;
}

void	add_matrix_vector(t_matrix_vector *a, t_matrix_vector *b, t_matrix_vector *sum_vect)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		sum_vect->axis[i] = a->axis[i] + b->axis[i];
}

void	add_matrix_to_ray_vector(t_matrix_vector *a, t_matrix_vector *b, t_ray_vector *sum_vect)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		sum_vect->axis[i] = a->axis[i] + b->axis[i];
}

void	add_ray_vector(t_ray_vector *a, t_ray_vector *b, t_ray_vector *sum_vect)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		sum_vect->axis[i] = a->axis[i] + b->axis[i];
}

void	add_color(t_color *a, t_color *b, t_color *sum_color)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		sum_color->rgb[i] = a->rgb[i] + b->rgb[i];
}

void	subtract_vector(t_ray_vector *a, t_matrix_vector *b, t_ray_vector *subt_vect)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		subt_vect->axis[i] = a->axis[i] - b->axis[i];
}

void	subtract_vecvec(t_ray_vector *a, t_ray_vector *b, t_ray_vector *subt_vect)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		subt_vect->axis[i] = a->axis[i] - b->axis[i];
}
/**========================================================================
 *                           subtract_torvec
 *!func name to be changed! 
 *========================================================================**/
void	subtract_torvec(t_matrix_vector *b, t_ray_vector *a, t_ray_vector *subt_vect)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		subt_vect->axis[i] = b->axis[i] - a->axis[i];
}

void	subtract_color_vector(t_ray_vector *a, t_matrix_vector *b, t_color *subt_vect)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		subt_vect->rgb[i] = a->axis[i] - b->axis[i];
}

void	subtract_color_color(t_color *a, t_color *b, t_color *subt_color)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		subt_color->rgb[i] = a->rgb[i] - b->rgb[i];
}

void	scale_matrix_vector(t_matrix_vector *vect, double scaler, t_matrix_vector *scaled_vect)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		scaled_vect->axis[i] = vect->axis[i] * scaler;
}

void	scale_matrix_torvec(t_matrix_vector *vect, double scaler, t_ray_vector *scaled_vect)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		scaled_vect->axis[i] = vect->axis[i] * scaler;
}

void	scale_ray_vector(t_ray_vector *vect, double scaler, t_ray_vector *scaled_vect)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		scaled_vect->axis[i] = vect->axis[i] * scaler;
}


void	scale_color(t_color *vect, double scaler, t_ray_vector *scaled_vect)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		scaled_vect->axis[i] = vect->rgb[i] * scaler;
}

double	product_scalar(t_ray_vector *a, t_ray_vector *b)
{
	double scalar;	
	int	i;

	scalar = 0.0;
	i = -1;
	while (++i < AXIS)
		scalar += a->axis[i] * b->axis[i];
	return (scalar);
}

/**========================================================================
 *                           product_scalar_matrix
 *! function name to be changed! 
 *========================================================================**/
double	product_scalar_matrix(t_ray_vector *d, t_matrix_vector *n)
{
	double scalar;	
	int	i;

	scalar = 0.0;
	i = -1;
	while (++i < AXIS)
		scalar += d->axis[i] * n->axis[i];
	return (scalar);
}

double	normalize_scalar_product(double scalar_product)
{
	return ((scalar_product + 1) * 0.5);
}

void	product_vector(t_matrix_vector *a, t_matrix_vector *b, t_matrix_vector *product_vect)
{
	product_vect->axis[0] = a->axis[1] * b->axis[2] - a->axis[2] * b->axis[1];
	product_vect->axis[1] = a->axis[2] * b->axis[0] - a->axis[0] * b->axis[2];
	product_vect->axis[2] = a->axis[0] * b->axis[1] - a->axis[1] * b->axis[0];
}

int	are_collinear_vectors(t_matrix_vector *pdct_vect, double precision)
{
	return (pdct_vect->axis[0] >= -precision && pdct_vect->axis[0] <= precision
		&& pdct_vect->axis[1] >= -precision && pdct_vect->axis[1] <= precision
		&& pdct_vect->axis[2] >= -precision && pdct_vect->axis[2] <= precision);
}

void	cast_vector(t_matrix_vector *matrix_vect, t_ray_vector *ray_vect)
{
	int	i;

	i = -1;
	while (++i < AXIS)
		ray_vect->axis[i] = matrix_vect->axis[i];	
}
void	cast_vector_ray_to_color(t_ray_vector *ray_vect, t_color *color)
{
	int i;
	
	i = -1;
	while (++i < AXIS)	
		color->rgb[i] = (ray_vect->axis[i]);
}

void	cast_vector_to_color(t_ray_vector *ray_vect, t_color *color)
{
	int i;
	
	i = -1;
	while (++i < AXIS)	
		color->rgb[i] = (ray_vect->axis[i] + 1) * 0.5 * 255;
}