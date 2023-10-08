/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:59:39 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/08 16:23:33 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_parsing(t_data *data)
{
	if (!ft_open_map(data))
		return (ft_printf(E_MAP), 0);
	//ft_debug_parsing(data);
	if (!ft_fill_map_array(data))
		return (0);
	ft_debug_map(data);
	return (1);
}
