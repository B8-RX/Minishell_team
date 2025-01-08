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

	line = malloc(5 * sizeof(char) + 1);
	if (!line)
	{
		fprintf(stderr, "Erreur : Échec de l'allocation mémoire.\n");
		return (1);
	}
	ft_strlcpy(line, "Hello", 6);
	free(line);
	printf("\e[0;33mHello, ceci est un main temporaire!\n");
	printf("Pour tester la compilation et les hooks pre-push.\n");
	printf("Le main.c final est en construction...\n");
	printf("\e[0m");
	return (0);
}
