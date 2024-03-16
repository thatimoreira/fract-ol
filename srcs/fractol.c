#include <stdio.h>
#include "../includes/minilibx-linux/mlx.h"

int main(void)
{
    void    *mlx; // connects software and display
    void    *mlx_window;
    void    *img;
    
    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, 1920, 1080, "Thati's screen"); // creates a new window
    (void)mlx_window;
    (void)img;
    img = mlx_new_image(mlx, 1920, 1080);
    mlx_loop(mlx); // keeps the window open
    return (0);
}

// Armazenar todos os pxs em uma imagem pq a pixel_put é lenta
// Depois enviar a imagem para a janela