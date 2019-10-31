/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiant <egiant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:41:08 by egiant            #+#    #+#             */
/*   Updated: 2019/10/31 17:33:53 by egiant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*void		init_arena(t_vm *vm)
{

}*/

void		init_player(t_player *player)
{
	player->number = 0;
	player->name = NULL;
	player->comment = NULL;
	player->exec_code_size = 0;
	player->exec_code = NULL;
	player->next = NULL;
}

t_vm		*init_vm(void)
{
	int 	n;
	t_vm	*vm;

	n = -1;
	vm = (t_vm *)malloc(sizeof(t_vm));
	vm->line_of_players = NULL;
	while (++n < 4)
		vm->players[n] = NULL;
	vm->number_of_players = 0;
	return(vm);
}