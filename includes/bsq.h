/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:38 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/03 14:36:18 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

// # include "leak.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
// # define init leak_detect_init
// # define malloc(s) leak_detelc_malloc(s, __FILE__, __LINE__)
// # define free leak_detect_free
// # define check leak_detect_check

typedef struct s_answer
{
	int			place;
	int			length;
}				t_answer;
typedef struct s_grid
{
	int			**grid;
	int			x;
	int			y;
	char		*buff_head;
	char		*buff_map;
	char		*rule;
	int			flag;
}				t_grid;

int				input_map(t_grid *panel, char *filename);
int				square_format_check(t_grid *panel);
int				format_check_newline(char *buff);
char			*input_str(char *filename);
char			*str_read(int fd);
int				set_head(t_grid *panel, char *buff);
unsigned int	my_strlen(char *str);
unsigned int	my_strlen_line(char *str);
unsigned int	my_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	count_digit(int num);
int				my_strncmp(char *s1, char *s2, unsigned int n);
char			*my_to_string(int num, unsigned int len);
int				map_check(t_grid *panel);
void			free_state(t_grid *panel, int i, int argc);
int				**init_grid(t_grid *panel);
void			square_search(t_grid *panel, t_answer *ans);

int				min(int a, int b);
int				max(int a, int b);
int				grid_out_check(t_grid *panel, int i, int j);
int				coo_place(t_grid *panel, int i, int j);
int				biggest_square(t_answer *ans, int length, int place);

int				search_end(t_grid *panel, t_answer *ans, int i, int j);

void			print_grid(t_grid *panel, t_answer *answer);

void			ft_putchar(char c);
void			free_print_grid(t_grid *panel, char **ans);

#endif
