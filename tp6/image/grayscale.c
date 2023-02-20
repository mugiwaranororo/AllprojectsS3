#include <err.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// Initial width and height of the window.
const int INIT_WIDTH = 640;
const int INIT_HEIGHT = 400;

// Updates the display.
//
// renderer: Renderer to draw on.
// texture: Texture that contains the image.
void draw(SDL_Renderer* renderer, SDL_Texture* texture)
{
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

// Event loop that calls the relevant event handler.
//
// renderer: Renderer to draw on.
// colored: Texture that contains the colored image.
// grayscale: Texture that contains the grayscale image.
void event_loop(SDL_Renderer* renderer, SDL_Texture* colored, SDL_Texture* grayscale)
{
    SDL_Event event;
    SDL_Texture* t = colored;

    while (1)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                return;
            
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                    draw(renderer, t);
                break;
            
            case SDL_KEYDOWN:
                if (event.key.keysym.sym) {
                    if (t == colored)
                        t = grayscale;
                    else
                        t = colored;
                    draw(renderer, t);
                }
                break;
        }
    }
}

// Loads an image in a surface.
// The format of the surface is SDL_PIXELFORMAT_RGB888.
//
// path: Path of the image.
SDL_Surface* load_image(const char* path)
{
    // Loads the image in a surface.
    SDL_Surface* surface = IMG_Load(path);
    if (surface == NULL)
        return NULL;

    // Converts the surface into the RGB format.
    SDL_Surface* rgb_surface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGB888, 0);
    if (rgb_surface == NULL)
        return NULL;

    // Frees the original surface.
    SDL_FreeSurface(surface);

    return rgb_surface;
}

// Converts a colored pixel into grayscale.
//
// pixel_color: Color of the pixel to convert in the RGB format.
// format: Format of the pixel used by the surface.
Uint32 pixel_to_grayscale(Uint32 pixel_color, SDL_PixelFormat* format)
{
    Uint8 r, g, b;
    SDL_GetRGB(pixel_color, format, &r, &g, &b);
    Uint32 color = SDL_MapRGB(format, r, g, b);
    color = 0.3 * r + 0.59 * g + 0.11 * b;
    r = color;
    g = color;
    b = color;
    return color;
}

void surface_to_grayscale(SDL_Surface* surface)
{
    Uint32* pixels = surface->pixels;
    int len = surface->w * surface->h;
    SDL_PixelFormat* format = surface->format;
    SDL_LockSurface(surface);
    for (int i = 0; i < len; i++)
        pixels[i] = pixel_to_grayscale(pixels[i], format);
    SDL_UnlockSurface(surface);
}

int main(int argc, char** argv)
{
    // Checks the number of arguments.
    if (argc != 2)
        errx(EXIT_FAILURE, "Usage: image-file");

    // TODO:
    // - Initialize the SDL.
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    // - Create a window.
    SDL_Window* window = SDL_CreateWindow("Image SDL", 0, 0, INIT_WIDTH, INIT_HEIGHT,
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    // - Create a renderer.
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());
    
    // - Create a surface from the colored image.
    SDL_Surface* colored = load_image(argv[1]);
    if (colored == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());
    
    // - Resize the window according to the size of the image.
    SDL_SetWindowSize(window, colored->w, colored->h);

    // - Create a texture from the colored surface.
    SDL_Texture* colored_texture = SDL_CreateTextureFromSurface(renderer, colored);
    if (colored_texture == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    // - Convert the surface into grayscale.
    surface_to_grayscale(colored);

    // - Create a new texture from the grayscale surface.
    SDL_Texture* grayscale_texture = SDL_CreateTextureFromSurface(renderer, colored);
    if (grayscale_texture == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    // - Free the surface.
    SDL_FreeSurface(colored);

    // - Dispatch the events.
    event_loop(renderer, colored_texture, grayscale_texture);

    // - Destroy the objects.
    SDL_DestroyTexture(grayscale_texture);
    SDL_DestroyTexture(colored_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}