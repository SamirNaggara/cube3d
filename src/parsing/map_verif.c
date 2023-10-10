/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:58:47 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/10 14:09:00 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_verif_map(t_data *data)
{
	if (!ft_authorize_char(data))
		return (ft_printf(E_CHAR), 0);
	if (!ft_one_player(data))
		return (ft_printf(E_PLAYER), 0);
	if (!ft_map_open(data))
		return (ft_printf(E_MAP_OPEN), 0);
	return (1);
}
