/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:45:59 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/02 13:37:36 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEAK_H
# define LEAK_H

# include <stdio.h>
# include <stdlib.h>

# define N 500
# define MAX_NUM 500

typedef struct s_mem
{
	void			*ptr;
	size_t			size;
	const char		*file;
	unsigned int	line;
}					t_mem;

void				leak_detect_init(void);
void				*leak_detelc_malloc(size_t size, const char *file,
						unsigned int line);
void				leak_detect_free(void *ptr);
void				leak_detect_check(void);

#endif
