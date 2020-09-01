/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 21:25:31 by fernando          #+#    #+#             */
/*   Updated: 2020/09/01 13:36:12 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main()
{
    ssize_t		ret;
	int			fd;	
	char		buf[1];

    char	str1[100] = "Adios";
	char	str2[100] = "Hola";
	char	str3[100] = "Tintin se fue a la guerra\n";

    printf("%s#######################STRLEN#################################\n", YELLOW);

    printf("%sPRUEBA DE FT_STRLEN: \n", YELLOW);
    printf("%zu\n", ft_strlen(str1));
   
    printf("%sPRUEBA DE STRLEN REAL: \n", YELLOW);
    printf("%zu\n", strlen(str1));
    printf("\n=================================\n");

    printf("%s#######################STRCPY#################################\n", BGREEN);

    printf("%sPRUEBA DE FT_STRCPY: \n", BGREEN);
    printf("%s\n", ft_strcpy(str1, str3));
    
    printf("%sPRUEBA DE STRCPY REAL:  \n", BGREEN);
    printf("%s\n", strcpy(str1, str3));
    printf("\n=================================\n");

    printf("%s#######################STRCMP#################################\n", MAGENTA);

    printf("%sPRUEBA DE FT_STRCMP: \n", MAGENTA);
    printf("%d\n", ft_strcmp("", str2));
    
    printf("%sPRUEBA DE STRCMP REAL: \n", MAGENTA);
    printf("%d\n", strcmp("", str2));
    printf("\n=================================\n");

    printf("%s#######################WRITE#################################\n", ROJO);

    fd = 0;
    int ret1;
    char *str0 = "Aquí me meto";

    printf("%sPRUEBA DE FT_WRITE OPEN FD : \n", ROJO);
    fd = open("./test_ftwrite", O_WRONLY);
    ret1 = ft_write(fd, str0, ft_strlen(str0));
    printf("\nReturn FT_WRITE : %d\n", ret1);
    printf("\nERROR: %s\n", strerror(errno));
    close(fd);
    printf("\n");
    
    printf("%sPRUEBA DE WRITE REAL OPEN FD : \n", ROJO);
    fd = open("./test_write", O_WRONLY);
    ret1 = write(fd, str0, strlen(str0));
    printf("\nReturn WRITE REAL : %d\n", ret1);
    printf("\nERROR: %s\n", strerror(errno));
    close(fd);
    printf("\n=================================\n");

    printf("%sPRUEBA DE FT_WRITE FD = 1: \n", ROJO);
    ret1 = ft_write(1, str3, ft_strlen(str3));
    printf("\nReturn FT_WRITE : %d\n", ret1);
    printf("\nERROR: %s\n", strerror(errno));
    printf("\n");
    
    printf("%sPRUEBA DE WRITE REAL FD = 1 : \n", ROJO);
    ret1 = ft_write(1, str3, ft_strlen(str3));
    printf("\nReturn WRITE REAL : %d\n", ret1);
    printf("\nERROR: %s\n", strerror(errno));
    printf("\n=================================\n");

    printf("%sPRUEBA DE FT_WRITE FD = -1 : \n", ROJO);
    ret1 = ft_write(-1, str3, ft_strlen(str3));
    printf("\nReturn FT_WRITE : %d\n", ret1);
    printf("\nERROR: %s\n", strerror(errno));
    printf("\n");
    
    printf("%sPRUEBA DE WRITE REAL FD = -1 : \n", ROJO);
    ret1 = ft_write(-1, str3, ft_strlen(str3));
    printf("\nReturn WRITE REAL : %d\n", ret1);
    printf("\nERROR: %s\n", strerror(errno));
    printf("\n=================================\n");

    printf("%s#######################READ#################################\n", PURPLE);

    fd = 0;
    int ret2;
    char *str6 = malloc(sizeof(char) * 100);
    
    printf("%sPRUEBA DE FT_READ: \n", PURPLE);
    fd = open("./test_read", O_RDONLY);
    ret = ft_read(fd, buf, 81);
    buf[ret] = '\0';
    printf("%s\n\nreturn : [%zd]\n\n", buf, ret);
    printf("ERROR: %s\n", strerror(errno));
    close(fd);
    printf("\n");

    printf("%sPRUEBA DE READ REAL:	\n", PURPLE);
    fd = open("./test_read", O_RDONLY);
    ret = read(fd, buf, 81);
    buf[ret] = '\0';
    printf("%s\n\nreturn : [%zd]\n\n", buf, ret);
    printf("ERROR: %s\n", strerror(errno));
    close(fd);
	printf("\n=================================\n");

    /*printf("%sPRUEBA DE FT_READ fd = 0 : \n", PURPLE);
    fd = 0;
    ret2 = ft_read(fd, str6, 100);
    printf("%s\n\nreturn : [%d]\n\n", str6, ret2);
    printf("ERROR: %s\n", strerror(errno));
    printf("\n");

    printf("%sPRUEBA DE READ REAL fd = 0 :	\n", PURPLE);
    fd = 0;
    printf("%s\n\nreturn : [%d]\n\n", str6, ret2);
    printf("ERROR: %s\n", strerror(errno));
    free(str6);
	printf("\n=================================\n");*/

    printf("%sPRUEBA DE FT_READ fd = -1 : \n", PURPLE);
    fd = -1;
    ret2 = ft_read(fd, str6, 100);
    printf("%s\n\nreturn : [%d]\n\n", str6, ret2);
    printf("ERROR: %s\n", strerror(errno));
    printf("\n");

    printf("%sPRUEBA DE READ REAL fd = -1 :	\n", PURPLE);
    fd = -1;
    printf("%s\n\nreturn : [%d]\n\n", str6, ret2);
    printf("ERROR: %s\n", strerror(errno));
    free(str6);
	printf("\n=================================\n");

    printf("%s#######################STRDUP#################################\n", WHITE);

    char	*str4 = ft_strdup("Adios");
	char	*str5 = strdup("Adios");

    printf("%sPRUEBA DE FT_STRDUP:	\n", WHITE);
    printf("%s", str4);
    printf("\n\n");

    printf("%sPRUEBA DE STRDUP REAL: \n", WHITE);
    printf("%s", str5);
    printf("\n=================================\n");

    free(str4);
    free(str5);

    return (0);
}