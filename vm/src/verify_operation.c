/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:13:10 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/11/29 21:41:23 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_args(char my_arg, char orig_arg)
{
	if ((orig_arg & T_REG && my_arg == REG_CODE) ||
		(orig_arg & T_DIR && my_arg == DIR_CODE) ||
		(orig_arg & T_IND && my_arg == IND_CODE))
		return (1);
	return (0);
}

int		check_args_type_code(t_major *major, t_carr *carr)
{
	char	args[3];
	int		i;

	i = 0;
	if (carr->op->args_type_code)
	{
		args[0] = (major->arena[carr->pos + 1] & 0b11000000) >> 6;
		args[1] = (major->arena[carr->pos + 1] & 0b00110000) >> 4;
		args[2] = (major->arena[carr->pos + 1] & 0b00001100) >> 2;
		while (i < carr->op->args_number)
		{
			if (!check_args(args[i], carr->op->args_type[i]))
				return (0);
			++i;
		}
	}
	return (1);
}

void	verify_operation(t_major *major, t_carr *carr)
{
	u_int8_t 	a = g_ops[0].opcode;
	u_int8_t 	b = g_ops[OP_NUMBER - 1].opcode;

	if (carr->opcode >= a && carr->opcode <= b)
	{
		if (check_args_type_code(major, carr))
		{
			// execute_operation(major, carr);
			carr->pos += carr->step_to_next_op;
		}
		// else
		// 	skip_invalid_args(major, carr);
	}
	else
	{
		++carr->pos;
	}
}
