/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:07:38 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/11/02 14:42:21 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		validation(char *file, t_major *major)
{
	char	*line;

	line = NULL;
	if (!(major->fd = validate_file(file)) ||
		!validate_name_and_comment(&line, major))
	{
		if (major->fd > 0)
			while (get_next_line(major->fd, &line))
				ft_strdel(&line);
		return (0);
	}
	ft_strdel(&line);
	while (get_next_line(major->fd, &line))
		ft_strdel(&line);
	return (1);
}
