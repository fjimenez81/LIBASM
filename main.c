/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 21:25:31 by fernando          #+#    #+#             */
/*   Updated: 2020/03/18 13:58:59 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main()
{
    char	str1[] = "Adios";
	char	str2[] = "Hola";
	char	str3[] = "Tintin se fue a la guerra\n";
	//char	str4[] = "libasm is for the ";
	//char	str5[] = "petit";
	//char	str6[] = "grand";
	//char	str7[] = "";

    printf("%sPRUEBA DE FT_STRLEN:	\n", YELLOW);

    printf("%zu\n", ft_strlen(str1));
    printf("%zu\n", strlen(str1));
    printf("\n");

    printf("%sPRUEBA DE FT_STRCPY:	\n", BGREEN);

    printf("%s\n", ft_strcpy(str1, str2));
    printf("%s\n", strcpy(str1, str2));
    printf("\n");

    printf("%sPRUEBA DE FT_STRCMP:	\n", MAGENTA);

    printf("%d\n", ft_strcmp(str1, str3));
    printf("%d\n", strcmp(str1, str3));
    printf("\n");

    printf("%sPRUEBA DE FT_WRITE:	\n", COLOR);

    ft_write(1, str3, ft_strlen(str3));
    write(1, str3, strlen(str3));
    printf("\n");

    return (0);
}