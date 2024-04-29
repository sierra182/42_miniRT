#include "all_necessary_elements_are_present.h"

/**========================================================================
 *                           all_necessary_elements_are_present
 *========================================================================**/
int	all_necessary_elements_are_present(char file_content[])
{
	if (element_is_present(file_content, "A") != 1)
		return (0);
	if (element_is_present(file_content, "C") != 1)
		return (0);
	if (element_is_present(file_content, "L") != 1)
		return (0);
	if (!element_is_present(file_content, "sp"))
		return (0);
	if (!element_is_present(file_content, "cy"))
		return (0);
	if (!element_is_present(file_content, "pl"))
		return (0);
	return (1);
}

/**========================================================================
 *                           element_is_present
 *========================================================================**/
int	element_is_present(char file_content[], char *el)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (file_content[i])
	{
		if (!ft_strncmp(&file_content[i], el, ft_strlen(el))
			&& (!file_content[i + ft_strlen(el)] || ft_isspace(file_content
					[i + ft_strlen(el)])) && (!file_content[i - 1]
				|| ft_isspace(file_content[i - 1])))
			n++;
		i++;
	}
	return (n);
}