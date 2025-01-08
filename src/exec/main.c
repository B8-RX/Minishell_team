/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 06:08:30 by ssghioua          #+#    #+#             */
/*   Updated: 2025/01/08 06:08:32 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(void)
{
	char	*line;

	line = malloc(sizeof(5) + 1);
	line = "Hello";
	line[5] = '\0';
	printf("Hello, ceci est un main temporaire!"
		"Le main.c final est en construction...\n");
	free(line);
	return (0);
}
