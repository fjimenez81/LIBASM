/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 21:25:31 by fernando          #+#    #+#             */
/*   Updated: 2020/08/31 17:51:42 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main()
{
    ssize_t		ret;
	int			fd;	
	char		buf[100];

    char	str1[100] = "Adios";
	char	str2[100] = "Hola";
	char	str3[100] = "Tintin se fue a la guerra\n";

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
    printf("%d\n", ft_strcmp("hola", "torrefacto"));
    
    printf("%sPRUEBA DE STRCMP REAL: \n", MAGENTA);
    printf("%d\n", strcmp("hola", "torrefacto"));
    printf("\n");

    printf("%sPRUEBA DE FT_WRITE: \n", ROJO);
    ft_write(1, str3, ft_strlen(str3));
    
    printf("%sPRUEBA DE WRITE REAL : \n", ROJO);
    write(1, str3, strlen(str3));
    printf("\n");

    printf("%sPRUEBA DE FT_READ: \n", PURPLE);
    fd = open("test.txt", O_RDONLY);
    ret = ft_read(fd, buf, 42);
    buf[ret] = '\0';
    printf("%s\nreturn : [%zd]\n\n", buf, ret);
    close(fd);

    printf("%sPRUEBA DE READ REAL:	\n", GREEN_INT);
    fd = open("test.txt", O_RDONLY);
    ret = read(fd, buf, 42);
    buf[ret] = '\0';
    printf("%s\nreturn : [%zd]\n\n", buf, ret);
    close(fd);
	printf("\n");

    printf("%sPRUEBA DE FT_STRDUP:	\n", WHITE);
    printf("%s", ft_strdup(str2));
    printf("\n");

    printf("%sPRUEBA DE STRDUP REAL: \n", WHITE);
    printf("%s", strdup(str2));
    printf("\n");

    return (0);
}