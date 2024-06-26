/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:58:15 by svidot            #+#    #+#             */
/*   Updated: 2024/06/26 13:58:16 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**========================================================================
 *                           ADD_VECTOR
 *========================================================================**/
void	add_vector(double a[], double b[], double sum_vect[])
{
	int	i;

	i = -1;
	while (++i < AXIS)
		sum_vect[i] = a[i] + b[i];
}

/**========================================================================
 *                           SUBTRACT_VECTOR
 *========================================================================**/
void	subtract_vector(double a[], double b[], double subt_vect[])
{
	int	i;

	i = -1;
	while (++i < AXIS)
		subt_vect[i] = a[i] - b[i];
}

/**========================================================================
 *                           SCALE_VECTOR
 *========================================================================**/
void	scale_vector(double vect[], double scaler, double scaled_vect[])
{
	int	i;

	i = -1;
	while (++i < AXIS)
		scaled_vect[i] = vect[i] * scaler;
}

/**========================================================================
 *                           SCALAR_PRODUCT
 *========================================================================**/
double	scalar_product(double a[], double b[])
{
	double	scalar;	
	int		i;

	scalar = 0.0;
	i = -1;
	while (++i < AXIS)
		scalar += a[i] * b[i];
	return (scalar);
}

/**========================================================================
 *                           CROSS_PRODUCT
 *========================================================================**/
void	cross_product(t_matrix_vector *a, t_matrix_vector *b,
	t_matrix_vector *product_vect)
{
	product_vect->axis[0] = a->axis[1] * b->axis[2] - a->axis[2] * b->axis[1];
	product_vect->axis[1] = a->axis[2] * b->axis[0] - a->axis[0] * b->axis[2];
	product_vect->axis[2] = a->axis[0] * b->axis[1] - a->axis[1] * b->axis[0];
}
