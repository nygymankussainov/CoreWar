/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:51:28 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/11/30 14:02:53 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	set_opcode(t_major *major, t_carr *carr)
{
	int32_t		i;

	if (major->arena[carr->pos] >= major->first_op
		&& major->arena[carr->pos] <= major->last_op)
	{
		i = (int32_t)major->arena[carr->pos];
		carr->op = &g_ops[i - 1];
		carr->cycles_to_exec = g_ops[i - 1].cycles;
	}
	else
	{
		carr->cycles_to_exec = 0;
		carr->op = NULL;
	}
	carr->opcode = major->arena[carr->pos];
}
