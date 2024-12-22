/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:13 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/22 14:10:17 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_char(char **s, int ac)
{
	int	i;
	int	j;

	j = 0;
	while (j < ac - 1)
	{
		i = 0;
		while (s[j][i])
		{
			if ((s[j][i] < '0' || s[j][i] > '9') && s[j][i] != '-')
				return (1);
			i++;
		}
		j++;
	}
	
}

int main(int argc, char const *argv[])
{
	if ()
	return 0;
}
