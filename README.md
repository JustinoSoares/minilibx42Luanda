## Minilibx 
MiniLibX é uma pequena biblioteca gráfica que permite fazer as coisas mais básicas para renderizar algo em telas sem nenhum conhecimento de X-Window e Cocoa. Ele fornece a chamada criação simples de janelas, uma ferramenta de desenho questionável, funções de imagem meia-boca e um estranho sistema de gerenciamento de eventos. 
Criada pela escola 42 para que os seus alunos possam aprender sobre computação gráfica,e muito mais.

### Oque você vai aprender aqui?

- As ferramentas básicas para abrir uma Janela
- Criar imagens
- Lidar com eventos de teclado e mouse

  ### Como usar?
  - Baixe a biblioteca minilibx-linux caso esteja a usar o sistema operacional linux
  - Navegue até ao directorio dê um make no terminal
  - Crie um arquivo .c e compile com as seguinte flag
 <br>
  
  
  ```
  
   cc arquivo.c -Wall -Wextra -Werror -Lminilibx-linux -lmlx_Linux -lX11 -lXext

  ```

  ## Código para abrir a uma Janela e colocar um texto simples
  Com a biblioteca minilibX é possível colocar abrir uma tela semelhando ao do terminal ou qualquer outros programa desktop e colocar texto de uma forma muito simples, exemplo:

  ```c
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
        
        
        mlx_connection = mlx_init(); // inicializando a biblioteca
        mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Tema do projecto"); // criando uma janela
        
        mlx_string_put(mlx_connection, mlx_window, 200, 250, 0xffffff, "Sejam bem vindos"); // colocando um texto na tela
        mlx_loop(mlx_connection); // criando um loop para que a tela fique aberta até receber uma ordem de fechamento
}
  ```
## Agora vamos lidar com eventos de teclado e de mouse
Vamos fazer o mesmo que fizemos no código passado mas aumentando algumas funcionalidade, que iram depender de eventos
nesse caso quando o user clicar em qualquer tecla ele vai apresentar o seu valor ascii no terminal *e caso ele click na tecla ESC do teclado ele vai fechar a tela* , e se ele clicar na tela ele deverá apresentar as suas cordenadas exatas

```c

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
        
        if (keycode == 65307) // ESC
        {
                mlx_destroy_window(data->mlx, data->window); // Funcao nativa da biblioteca para fechar o tela
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
        data.window = mlx_new_window(data.mlx, 800, 500, "Fractal");
        
        mlx_key_hook(data.window, key_hook, &data); // Chama a funcao key_hook quando o user digitar um teclado 
        mlx_mouse_hook(data.window, mouse_hook, &data); // Chama a funcao mouse_hook quando o usuário clicar na tela
        mlx_loop(data.mlx);
}

```

<strong>OBS</strong>: isso é apenas um exemplo de uso você como programador tem a liberdade de ajustar o teu projecto segundo a tua necessídade, por exemplo se por um acaso você decide que agora que quando o usuário precionar a tecla delete fecha a tela e não mais a ESC , basta saber  o valor do delete em ascii, você é livre

