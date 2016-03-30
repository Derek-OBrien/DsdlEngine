#ifndef _RESOURCETEXTURE_
#define _RESOURCETEXTURE_

#include "EngineDefines.h"

/*
	FIle : ResourcTexture
	Author: Derek O Brien
	Description: Load & Render Image and TTf media into Sdl Texture
*/
namespace DsdlEngine{

	class ResourceTexture{
	public:
		ResourceTexture();
		~ResourceTexture();

		//Load image texture
		bool loadTexture(std::string texturePath, SDL_Renderer* r);

		//Load Ttf As Texture
		bool loadTTF(std::string text, SDL_Color color, TTF_Font* myFont, SDL_Renderer* r);

		//Render texture to window
		void render(Vec2 p, Vec2 s, SDL_Renderer* r, SDL_Rect* clip = NULL);

		//Set Texture blend mode
		void setBlendMode(SDL_BlendMode blending);

		//Set Texture Alpha
		void setAlpha(Uint8 alpha);

		//Destroy Texture
		void destroy();
	private:

		//Sdl Texture
		SDL_Texture* m_Texture;
		//Texture cache map
		std::map<std::string, SDL_Texture*> m_TextureMap;

		int m_iWidth, m_iHeight;
	};
}

#endif // !_RESOURCETEXTURE_
