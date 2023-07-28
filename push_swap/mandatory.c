/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:48:38 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/20 21:45:00 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parsing/parsing.h"
#include "sort/sort.h"

int	main(int argc, char *argv[])
{
	t_table		*table;
	int			*arr;

	if (argc == 1)
		return (0);
	arr = parsing(argc, argv);
	if (!arr)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	table = set_table(arr);
	a_to_b(table, table->num - 1);
	cmd_print(table);
	free_table(table);
	return (0);
}
