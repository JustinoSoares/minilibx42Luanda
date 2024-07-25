/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:54:38 by jsoares           #+#    #+#             */
/*   Updated: 2024/07/23 17:54:39 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

# define HEIGHT 500
# define WIDTH 800

int     main()
{
        void    *mlx_connection;
        void    *mlx_window;
        int     y = HEIGHT * 0.1;
        int     x = WIDTH * 0.1;
        
        
        mlx_connection = mlx_init();
        mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Terminal");

        mlx_string_put(mlx_connection, mlx_window, WIDTH * 0.798, HEIGHT * 0.93, 0xffff00, "Justino Soares");
        mlx_loop(mlx_connection);
}
