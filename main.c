/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 21:25:31 by fernando          #+#    #+#             */
/*   Updated: 2020/04/13 00:56:26 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main()
{
    ssize_t		ret;
	int			fd;	
	char		buf[100];

    char	str1[] = "Adios";
	char	str2[] = "Hola";
	char	str3[] = "Tintin se fue a la guerra\n";

    printf("%sPRUEBA DE FT_STRLEN: \n", YELLOW);
    printf("%zu\n", ft_strlen(str1));
   
    printf("%sPRUEBA DE STRLEN REAL: \n", YELLOW);
    printf("%zu\n", strlen(str1));
    printf("\n");

    printf("%sPRUEBA DE FT_STRCPY: \n", BGREEN);
    printf("%s\n", ft_strcpy(str1, str2));
    
    printf("%sPRUEBA DE STRCPY REAL:  \n", BGREEN);
    printf("%s\n", strcpy(str1, str2));
    printf("\n");

    printf("%sPRUEBA DE FT_STRCMP: \n", MAGENTA);
    printf("%d\n", ft_strcmp(str1, str3));
    
    printf("%sPRUEBA DE STRCMP REAL: \n", MAGENTA);
    printf("%d\n", strcmp(str1, str3));
    printf("\n");

    printf("%sPRUEBA DE FT_WRITE: \n", ROJO);
    ft_write(1, str3, ft_strlen(str3));
    
    printf("%sPRUEBA DE WRITE REAL : \n", ROJO);
    write(1, str3, strlen(str3));
    printf("\n");

    printf("%sPRUEBA DE FT_READ: \n", PURPLE);
    fd = open("ft_write.s", O_RDONLY);
    ret = ft_read(0, buf, 42);
    buf[ret] = '\0';
    printf("%s\nreturn : [%zd]\n\n", buf, ret);
    close(fd);

    printf("%sPRUEBA DE READ REAL:	\n", GREEN_INT);
    fd = open("ft_write.s", O_RDONLY);
    ret = read(0, buf, 42);
    buf[ret] = '\0';
    printf("%s\nreturn : [%zd]\n\n", buf, ret);
    close(fd);
	printf("\n");

    printf("%sPRUEBA DE FT_STRDUP:	\n", WHITE);
    printf("%s", ft_strdup(str3));

    printf("%sPRUEBA DE STRDUP REAL: \n", WHITE);
    printf("%s", strdup(str3));
    printf("\n");

    return (0);
}