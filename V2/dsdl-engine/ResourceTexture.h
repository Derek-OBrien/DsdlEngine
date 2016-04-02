#ifndef _RESOURCETEXTURE_
#define _RESOURCETEXTURE_

#include "EngineDefines.h"

/**
*	@author Derek O Brien
*/
namespace DsdlEngine{

	/**
	*	ResourceTexture is responsible for loading and rendering all textures in the game.
	*	it is the base class for all textures.
	*/
	class ResourceTexture{
	public:
		/**
		*	Constructor
		*/
		ResourceTexture();

		/**
		*	Deconstructor
		*/
		~ResourceTexture();

		/**
		*	LoadTexture loads in sprite texture from the giving asset path.
		*	@parma texturePath, std::string to the asset.
		*	@parma r, the Renderer to use in loading
		*	@return bool
		*/
		bool loadTexture(std::string texturePath, SDL_Renderer* r);

		/**
		*	LoadTTF loads in a texture created from a TTF font file.
		*	@parma text, text to display onthe texture
		*	@parma color, the SDL_COlor to use for the texture.
		*	@parma myFont, the TTF_Font to use.
		*	@parma r, the SDL_Renderer to use.
		*	@return bool.
		*/
		bool loadTTF(std::string text, SDL_Color color, TTF_Font* myFont, SDL_Renderer* r);

		/**
		*	Render a texture to the window
		*	@parma p, Vec2 postion to render too.
		*	@parma s, Vec2 size of texture to render.
		*	@parma r, SDL_Renderer to use.
		*	@parma clip, the Sprite texture clip frame to use.
		*/
		void render(Vec2 p, Vec2 s, SDL_Renderer* r, SDL_Rect* clip = NULL);

		/**
		*	Set the blend mode of the texture.
		*	@parma blending. Blendmode to use.
		*/
		void setBlendMode(SDL_BlendMode blending);

		/**
		*	Set the Alpha for a texture
		*	@parma alpha, UNit8 value of Alpha to use.
		*/
		void setAlpha(Uint8 alpha);

		/**
		*	Destroy the texture 
		*/
		void destroy();
	private:

		SDL_Texture* m_Texture;									/**< The SDL_Texture to use when loading and rendering*/
		std::map<std::string, SDL_Texture*> m_TextureMap;		/**< std::Map to cache the textures*/

		int m_iWidth, m_iHeight;								/**< widht and height of the SDL_Texture*/
	};
}

#endif // !_RESOURCETEXTURE_
