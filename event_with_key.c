/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paratice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 00:25:20 by jsoares           #+#    #+#             */
/*   Updated: 2024/07/25 00:25:21 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct t_data
{
        void    *mlx;
        void    *window;
}       t_data;

int     key_hook(int keycode, t_data *data)
{
        printf("techado precionado: %d\n", keycode);
        
        if (keycode == 65307)
        {
                mlx_destroy_window(data->mlx, data->window);
                exit(0);
        }
        return (0);
}

int     mouse_hook(int button, int x, int y, t_data *data)
{
        printf("evento de mouse %d %d", x, y);
        return (0);
}
int     main()
{
        t_data  data;
        
        data.mlx = mlx_init();
        data.window = mlx_new_window(data.mlx, 800, 500, "Fractal");
        
        mlx_key_hook(data.window, key_hook, &data);  
        mlx_mouse_hook(data.window, mouse_hook, &data);   
        mlx_loop(data.mlx);
}
