/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:07:38 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/11/04 15:02:15 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		validation(char *file, t_major *major)
{
	char	*line;
	t_token	*token;

	line = NULL;
	if (!(major->fd = validate_file(file)) ||
		!validate_name_and_comment(&line, major))
		return (0);
	ft_strdel(&line);
	get_next_line(major->fd, &line, 1);
	lseek(major->fd, 0, SEEK_SET);
	token = tokenization(&line, major);
	return (1);
}
