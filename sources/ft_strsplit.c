/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:56:57 by tfolly            #+#    #+#             */
/*   Updated: 2016/12/06 16:11:26 by thibaultfolly    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		nbr_words(char const *s, char c)
{
	int i;
	int nb;
	int mot;

	i = 0;
	nb = 0;
	mot = 0;
	ft_putendl("nbr_words");
	while (s[i] != '\0')
	{
		if (mot == 0 && s[i] != c)
		{
			mot = 1;
			nb++;
		}
		if (s[i] == c)
		{
			mot = 0;
		}
		i++;
	}
	ft_putendl("fin nbr_words");
	return (nb);
}

static char		*next_word(char const *s, char c)
{
	ft_putendl("next_word");

	while (*s && *s == c)
		s++;
	ft_putendl("fin next_word");
	return ((char*)s);
}

static int		len_word(char const *s, char c)
{
	int len;

	ft_putendl("len_word");
	len = 0;
	while (*s != c)
	{
		s++;
		len++;
	}
	ft_putendl("fin len_word");
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**resp;
	int		nb;
	int		i;

	if (!s)
		return (NULL);
	s = next_word(s, c);
	nb = nbr_words(s, c);
	if (!(resp = malloc(sizeof(char*) * nb + 1)))
		return (NULL);
	i = 0;
	while (i < nb)
	{
		if (!(resp[i] = (char *)malloc(sizeof(char) * len_word(s, c) + 1)))
			return (0);
		resp[i] = ft_memcpy(resp[i], s, len_word(s, c));
		resp[i][len_word(s, c)] = '\0';
		s = s + len_word(s, c);
		s = next_word(s, c);
		i++;
	}
	resp[i] = NULL;
	return (resp);
}
