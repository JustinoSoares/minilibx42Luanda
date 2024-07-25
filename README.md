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
        
        
        mlx_connection = mlx_init();
        mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Tema do projecto");
        
        mlx_string_put(mlx_connection, mlx_window, 200, 250, 0xffffff, "Sejam bem vindos");
        mlx_loop(mlx_connection);
}
  ```
