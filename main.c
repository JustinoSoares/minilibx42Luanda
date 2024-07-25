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
# define WIDTH 500

int     main()
{
        void    *mlx_connection;
        void    *mlx_window;
        
        
        mlx_connection = mlx_init();
        mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Tema do projecto");
        
        mlx_string_put(mlx_connection, mlx_window, 200, 250, 0xffffff, "Sejam bem vindos");
        mlx_loop(mlx_connection);
}
