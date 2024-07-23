/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 00:15:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/24 00:24:38 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
long long int	ft_atoll(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);

#endif