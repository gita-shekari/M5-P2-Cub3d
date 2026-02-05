#include <MLX42/MLX42.h>
#include "try.h"

uint32_t	color(mlx_texture_t *tex, int x, int y)
{
	int	tex_i;

	tex_i = (y * tex->width + x) * 4;
	return (
		((uint32_t)tex->pixels[tex_i + 0] << 24) |
		((uint32_t)tex->pixels[tex_i + 1] << 16) |
		((uint32_t)tex->pixels[tex_i + 2] << 8) |
		((uint32_t)tex->pixels[tex_i + 3])
	);
}

static uint32_t	colorof(int type)
{
	return (
		((uint32_t)type << 24) |
		((uint32_t)type << 16) |
		((uint32_t)type << 8) |
		((uint32_t)type)
	);
}

void	tmp_put_color(t_env *env, int x, int y, char part)
{
	if (part == 'c')
		mlx_put_pixel(env->img, (uint32_t)x, (uint32_t)y, colorof(CEILING));
	if (part == 't')
		mlx_put_pixel(env->img, (uint32_t)x, (uint32_t)y, colorof(WALL));
	if (part == 'f')
		mlx_put_pixel(env->img, (uint32_t)x, (uint32_t)y, colorof(FLOOR));
}
/** t = texture dir 0-N, 1-S, 2-E, 3-W */
//void	draw_texture(t_env *env, t_pos *pos, t_dir t)
//{
//	uint32_t	c;
//	mlx_texture_t	*tex;
//	t_pos *mapped_pos;

//	tex = &(env->xpm[t]->texture);
//	mapped_pos = mapping_pos(pos);
//	c = color(tex, mapped_pos->x, mapped_pos->y);
//	mlx_put_pixel(env->img, pos->x, pos->y, c);
//	//while (y < (int)tex->height)
//	//{
//	//	x = 0;
//	//	while (x < (int)tex->width)
//	//	{
//	//		c = color(tex, x, y);
//	//		mlx_put_pixel(env->img, pos->x + x, pos->y + y, c);
//	//		x++;
//	//	}
//	//	y++;
//	//}
//}

/** TO CHECK how to render the wall with texture
 * Rendering a wall pixel-by-pixel using a texture involves mapping a 2D texture image onto a vertical slice of a scene, a technique foundational to raycasting engines (like DOOM or Wolfenstein 3D) and custom 2D rendering engines. The process requires calculating which texel (texture pixel) corresponds to each pixel on the screen and handling potential distortions like perspective. Core Principles Texture Mapping: Mapping screen coordinates \((x,y)\) to texture coordinates \((u,v)\).Vertical Slice: In 2D raycasting, a wall is rendered one vertical column of pixels at a time.Nearest-Neighbor: To keep a "pixel-art" look, disable interpolation (linear filtering) and use "closest" (nearest-neighbor) filtering. Step-by-Step Implementation Approach 1. Pre-processing Texture Preparation: Use a seamless texture (e.g., \(64\times 64\) pixels). Ensure it is loaded into memory.Pixel Art Settings: If using a modern engine like Unity or Blender, set texture interpolation to "Nearest" to prevent blurring. 2. Determining the Texture Column (U coordinate) When a ray hits a wall, determine where on that wall the collision occurred to know which vertical slice of the texture to use. Calculate Impact Position: Determine the exact point on the wall \((x,y)\) where the collision happened.Calculate \(U\): Find the fractional distance across the wall segment (e.g., if the hit is exactly in the middle of a grid square, \(U=0.5\)).Map to Texture: Multiply \(U\) by the width of the texture (e.g., \(U\times 64\)) to get the pixel column index. 3. Calculating the Vertical Slice (V coordinate) The height of the wall on the screen depends on the distance from the camera. Calculate Height: Screen Wall Height = \((\text{Texture\ Height}\times \text{Vertical\ Resolution})/\text{Distance}\).Calculate V Step: Calculate how much to move through the texture per screen pixel: step = TextureHeight / ScreenWallHeight. 4. Drawing Pixel-by-Pixel (The Loop) Iterate through the screen pixels from top to bottom for the vertical slice: pseudofor (int y = wallTop; y < wallBottom; y++) {
    // Calculate the corresponding texel V coordinate
    int texV = (int)((y - wallTop) * step);
    
    // Get color from texture at (texU, texV)
    Color pixelColor = Texture.GetPixel(texU, texV);
    
    // Draw pixel to screen at (columnX, y)
    DrawPixel(columnX, y, pixelColor);
}
Performance Optimization Techniques Avoid SetPixels: In engines like Unity, SetPixels is slow. Use RenderTexture as a canvas and Graphics.DrawTexture to draw on it, or a pixel shader for maximum efficiency.Use SetPixels32: If manually manipulating raw byte arrays, SetPixels32 is faster than SetPixels.Pixel Shader: The fastest method is placing all rendering logic inside a pixel shader, which can achieve multi-thousand FPS.Pre-calculate Scaling: Pre-calculate the \(V\)-step and screen positions to avoid division in the inner pixel loop. Handling Perspective and Distortions If the wall is not directly facing the camera, use perspective correct mapping or ensure the raycasting approach naturally handles this by calculating the distance to the wall based on the ray's angle relative to the wall normal. For 3D, ensure you use 1/z for interpolation to avoid texture warping. How to TEXTURE MAP Walls | Raycasting in Scratch E713 May 2022 — hello fellow scratchers. when I began this simple raycasting. series I intended it to be no more than two episodes i was very clea...YouTube·griffpatch2mCreating a Low Poly Pixel Texture 3D Asset in Blender 2.8+17 Jun 2020 — uh this should be a really fun one um we're going to look at painting pixelated textures the kind you might find in a game like Mi...YouTube·Louis du Mont19:50What is the fastest way to draw pixels on to the screen? - Reddit10 May 2022 — The fastest method is putting all your drawing code inside a pixel shader and rendering to a texture/FBO, then rendering that text...RedditHow to render pixel art correctly? - Handmade Hero3 Dec 2021 — if the pixel is inside the texel then don't do the bilinear filter, if not then do it? That is exactly what is. You understand it ...Handmade NetworkRenderTexture and Graphics to perform 2D drawing on texture23 Feb 2012 — Instead of SetPixels which (it has been mentioned several times) is prohibitively slow (due to the final Apply() call) I consider ...Unity Discussions
 */