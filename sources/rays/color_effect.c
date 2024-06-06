#include "se_mini_struct.h"
#include "x_linear_algebra.h"

double	calculate_light_attenuation(t_ray *light_ray, double intensity)
{
	double			light_mag;
	const double	kc = 0.5;
	const double	kl = 45e-4;
	const double	kq = 75e-25;

	light_mag = get_vector_magnitude(light_ray->dir_vect.axis);
	return (intensity / (kc + kl * light_mag + kq * light_mag * light_mag));
}

// double	calculate_light_attenuation2(t_ray *light_ray, double intensity)
// {
// 	double			light_mag;
// 	const double	kc = 0.5;
// 	const double	kl = 45e-4;
// 	const double	kq = 75e-25;


// 	light_mag = get_vector_magnitude(light_ray->dir_vect.axis);
// 	// printf("cylinder intensity: %f\n", intensity);
// 	return (intensity / (kc + kl * light_mag + kq * light_mag * light_mag));
// }
// void	add_self_shadowing(double light_coef, double light_attenuation,
// 	t_color *color) //! supp if unsused
// {
// 	t_color	scaled_color;

// 	scale_color(color, 1 - light_attenuation, &scaled_color);
// 	subtract_color(color, &scaled_color, color);
// }

// void	add_shading2( t_ray *ray, t_ray_vector *normal,
// 	t_color *color, t_color *res_color)
// {
// 	double	light_coef;
// 	t_color	scaled_color;

// 	light_coef = scalar_product(ray->dir_vect.axis, normal->axis);
	
// 	normalize_zero_one(&light_coef, 1);
// 	scale_color(color, light_coef, &scaled_color);
// 	subtract_color(color, &scaled_color, res_color);
// }
void	add_shading( t_ray *ray, t_ray_vector *normal,
	t_color *color, t_color *res_color)
{
	double	light_coef;
	t_color	scaled_color;

	light_coef = scalar_product(ray->dir_vect.axis, normal->axis);	
	normalize_zero_one(&light_coef, 0);
	scale_color(color, light_coef, &scaled_color);
	subtract_color(color, &scaled_color, res_color);
}
double aces_tonemap(double x);
void	apply_aces_to_color(t_color *color);

void	add_lightening(t_add_lightening_params *params) 
{	
	t_color	subt_color;
	t_color	scaled_color;
	t_ray	light_ray_cpy;

	light_ray_cpy = *params->light_ray;
	normalize_vector(light_ray_cpy.dir_vect.axis); //!opt
	*params->light_coef = scalar_product(light_ray_cpy.dir_vect.axis,
			params->normal->axis);
	normalize_zero_one(params->light_coef, 1);
	
	// *params->light_coef = aces_tonemap(*params->light_coef);
	// printf("sphere lightray : %f, %f, %f\n", params->light_ray->dir_vect.axis[0], params->light_ray->dir_vect.axis[1], params->light_ray->dir_vect.axis[2]);
	*params->light_attenuat = calculate_light_attenuation(params->light_ray,
			*params->light_coef * params->spotlight->intensity);
	//  *params->light_attenuat = aces_tonemap(*params->light_attenuat);
	// printf("sphere light_attenuat: %f\n", *params->light_attenuat);
	subtract_color(&(t_color){.rgb[0] = 255, .rgb[1] = 255, .rgb[2] = 255},
		params->color, &subt_color);
	//scale_color(params->color, *params->light_attenuat * 1, params->res_color);
	scale_color(&subt_color, *params->light_attenuat * 0.00000125, &scaled_color);
	//add_color(&scaled_color, params->color, params->res_color);
	// apply_aces_to_color(params->res_color);
	
}
double	calculate_light_attenuation2(t_ray *light_ray, double intensity);

// void	add_lightening2(t_add_lightening_params *params) 
// {	
// 	t_color	subt_color;
// 	t_color	scaled_color;
// 	t_ray	light_ray_cpy;

// 	light_ray_cpy = *params->light_ray;
// 	normalize_vector(light_ray_cpy.dir_vect.axis); //!opt
// 	*params->light_coef = scalar_product(light_ray_cpy.dir_vect.axis,
// 			params->normal->axis);
// 	normalize_zero_one(params->light_coef, 1);
// 	*params->light_coef = aces_tonemap(*params->light_coef);
// 	// printf("cylinder lightray : %f, %f, %f\n",  params->light_ray->dir_vect.axis[0], params->light_ray->dir_vect.axis[1], params->light_ray->dir_vect.axis[2]);
// 	*params->light_attenuat = calculate_light_attenuation2(params->light_ray,
// 			*params->light_coef * params->spotlight->intensity);
// 	if (*params->light_attenuat > 1)
// 		printf("cyl light_attenuat: %f\n", *params->light_attenuat);

// 	subtract_color(&(t_color){.rgb[0] = 255, .rgb[1] = 255, .rgb[2] = 255},
// 		params->color, &subt_color);
// 	scale_color(&subt_color, *params->light_attenuat * 0.825, &scaled_color);
// 	add_color(&scaled_color, params->color, params->res_color);
// }
// void	add_lightening(t_add_lightening_params *params) good
// {
// 	t_ray	light_ray_sav;
// 	t_color	subt_color;
// 	t_color	scaled_color;

// 	light_ray_sav = *params->light_ray;
// 	// normalize_vector(params->light_ray->dir_vect.axis);
// 	*params->light_coef = scalar_product(params->light_ray->dir_vect.axis,
// 			params->normal->axis);
// 	normalize_zero_one(params->light_coef);
// 	subtract_color(&(t_color){.rgb[0] = 255, .rgb[1] = 255, .rgb[2] = 255},
// 		params->color, &subt_color);
// 	// *params->light_attenuat = calculate_light_attenuation(&light_ray_sav,
// 	// 		*params->light_coef * params->spotlight->intensity);
// 	scale_color(&subt_color, *params->light_attenuat, &scaled_color);
// 	add_color(&scaled_color, params->color, params->res_color);
// }
void clamp_color(t_color *color, int min, int max) {
    int i;
    for (i = 0; i < AXIS; ++i) {
        if (color->rgb[i] < min) color->rgb[i] = min;
        if (color->rgb[i] > max) color->rgb[i] = max;
    }
}

void multiply_colors(t_color *color1, t_color *color2, t_color *result) {
    int i;
    for (i = 0; i < AXIS; ++i) {
        result->rgb[i] = color1->rgb[i] + color2->rgb[i];
    }
	clamping_255(result);
    // clamp_color(result, 0.0, 1.0);
}
// void	color_with_light(t_color *mesh_color,
// 	t_color *light_color, double intensity, t_color *new_color)
// {
// 	t_color	scaled_color;

// 	scale_color(light_color, intensity,
// 		&scaled_color);
// 	multiply_colors(mesh_color, &scaled_color, new_color);
// }

void	color_with_light(t_color *mesh_color,
	t_color *light_color, double intensity, t_color *new_color)
{
	t_color	scaled_color;

	scale_color(light_color, intensity,
		&scaled_color);
	get_average_color(&scaled_color, mesh_color, new_color);
	scale_color(new_color, intensity, new_color);
}
