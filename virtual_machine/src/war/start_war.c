/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_war.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:50:41 by hfrankly          #+#    #+#             */
/*   Updated: 2019/12/05 16:04:46 by hfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				announce_winner(t_corewar *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n", vm->winner->id,
					vm->winner->name);
}

void				start_war(t_corewar *vm)
{
	t_carriage		*tmp;

	tmp = vm->start_carriage;
	if (vm->visual)
	{
		vis_corewar(vm);
		stringColor(vm->sdl->ren, SZX - 250, SZY - 56,
										vm->winner->name, vm->winner->color);
		SDL_RenderPresent(vm->sdl->ren);
	}
	while (vm->start_carriage)
	{
		if (vm->dumps == (int32_t)(vm->current_cycles + vm->total_cycles))
		{
			display_array(vm->arena, 64, 64);
			free_corewar(vm);
			exit(0);
		}
		execute_carriages(&vm);
		if ((int32_t)(vm->current_cycles) == vm->cycles_to_die
					|| vm->cycles_to_die <= 0)
			check(&vm);
	}
	announce_winner(vm);
}
