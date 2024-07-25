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
        void    *img;
        int     img_width;
        int     img_height;
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

int     mouse_hook(int  button, int x, int y, t_data *data)
{
        printf("X: %d \t Y: %d..\n", x, y);
        return (0);
}

int     main()
{
        t_data  data;
        
        data.mlx = mlx_init();
        data.window = mlx_new_window(data.mlx, 500, 500, "Fractal");
        
        data.img = mlx_xpm_file_to_image(data.mlx, "img.xpm", &data.img_width, &data.img_height);
        
         // Exibir a imagem na janela
        mlx_put_image_to_window(data.mlx, data.window, data.img, 0, 0);
        
        mlx_key_hook(data.window, key_hook, &data); // Chama a funcao key_hook quando o user digitar um teclado 
        mlx_mouse_hook(data.window, mouse_hook, &data); // Chama a funcao mouse_hook quando o usuário clicar na tela
        mlx_loop(data.mlx);
}
