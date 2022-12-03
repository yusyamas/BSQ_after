/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:55:50 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/03 14:36:49 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	init_state(t_grid *panel, t_answer *ans)
{
	ans->place = panel->x * panel->y;
	ans->length = 0;
	panel->flag = 0;
	panel->rule = malloc(sizeof(char) * 4);
}

void	error_run(void)
{
	write(1, "map error\n", 10);
}

void	input_one(void)
{
	char		*buff;
	t_grid		panel;
	t_answer	ans;

	init_state(&panel, &ans);
	buff = str_read(0);
	if (!set_head(&panel, buff))
		error_run();
	free(buff);
	if (panel.flag && square_format_check(&panel))
	{
		panel.grid = init_grid(&panel);
		square_search(&panel, &ans);
		print_grid(&panel, &ans);
	}
	else if (panel.flag)
		error_run();
	free_state(&panel, 0, 1);
}

void	input_two(int argc, char **argv)
{
	int			i;
	t_grid		panel;
	t_answer	ans;

	i = 1;
	while (i < argc)
	{
		init_state(&panel, &ans);
		if (input_map(&panel, argv[i]) && square_format_check(&panel))
		{
			panel.grid = init_grid(&panel);
			square_search(&panel, &ans);
			print_grid(&panel, &ans);
		}
		else
			error_run();
		free_state(&panel, i, argc);
		i++;
	}
}

// int	main(int argc, char *argv[])
// {
// 	if (argc == 1)
// 		input_one();
// 	else if (argc >= 2)
// 		input_two(argc, argv);
// 	check();
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	if (argc == 1)
		input_one();
	else if (argc >= 2)
		input_two(argc, argv);
	return (0);
}
