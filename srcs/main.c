# include "../includes/minirt.h"

int main() 
{
    int image_width;
    int image_height;

    image_width = 256;
    image_height = 256; 
    void *mlx_ptr = mlx_init();
    if (!mlx_ptr) {
        fprintf(stderr, "Failed to initialize MinilibX\n");
        return EXIT_FAILURE;
    }

    // Create a new window
    void *win_ptr = mlx_new_window(mlx_ptr, image_width, image_height, "Image");

    // Create a new image
    void *img_ptr = mlx_new_image(mlx_ptr, image_width, image_height);

    // Get the address of the image data
    int bits_per_pixel;
    int size_line;
    int endian;
    char *data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

    // Set pixel values
    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            double r = (double)i / (image_width - 1);
            double g = (double)j / (image_height - 1);
            double b = 0.25;

            int ir = (int)(255.999 * r);
            int ig = (int)(255.999 * g);
            int ib = (int)(255.999 * b);

            int index = 4 * (i + j * image_width);
            data[index] = (char)ib;
            data[index + 1] = (char)ig;
            data[index + 2] = (char)ir;
            data[index + 3] = (char)0;
        }
    }

    // Put the image on the window
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);

    // Start the event loop
    mlx_loop(mlx_ptr);

    return (0);
}
 