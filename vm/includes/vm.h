/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:01:09 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/11/27 17:38:39 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "ft_printf.h"

typedef struct		s_carr
{
	int				id;
	int				player_id;
	bool			carry;
	int				opcode;
	int				lastlive_cycle;
	int				cycles_to_exec;
	int				pos;
	int				step_to_next_op;
	int				reg[REG_NUMBER];
	bool			dead;
	struct s_carr	*next;
}					t_carr;

typedef struct		s_player
{
	int				id;
	char			*name;
	char			*comment;
	int				code_size;
	char			*bytecode;
	t_carr			*carr;
}					t_player;

typedef struct		s_major
{
	int				pl_nb;
	int				dump;
	char			arena[MEM_SIZE];
	t_player		*lastlive;
	int				cycles_from_start;
	int				live_count;
	int				cycles_to_die;
	int				check_count;
	t_carr			*carr;
}					t_major;

typedef enum		e_type
{
	Magic_header = 1,
	Name,
	Champ_code_size,
	Comment,
	End,
	Bytecode
}					t_type;

int					isplayer(char *str);
t_player			*validation(int argc, char **argv, int nb);
int					check_bytecode(char *argv, t_player *player, int nb, int j);
char				*rev_bytes(char *str, int size);
char				*read_from_fd(int fd, int size, int type, char *argv);
void				modify_players_id(t_player *player, char **argv, int argc, int nb);
void				delete_player(t_player *player, int nb);
void				vm(t_player *player, t_major *major);
void				announce_players(t_player *player, int nb);

#endif
