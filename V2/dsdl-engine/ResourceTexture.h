#ifndef _RESOURCETEXTURE_
#define _RESOURCETEXTURE_

#include "EngineDefines.h"

namespace DsdlEngine{

	class ResourceTexture
	{
	public:
		ResourceTexture();
		~ResourceTexture();

		ResourceTexture loadTexture(std::string texturePath, SDL_Renderer* r);

		bool loadFromFile(std::string texturePath, SDL_Renderer* r);
		bool loadTTF(std::string text, SDL_Color color, TTF_Font* myFont, SDL_Renderer* r);
		void render(Vec2 p, Vec2 s, SDL_Renderer* r, SDL_Rect* clip = NULL);

		void setBlendMode(SDL_BlendMode blending);
		void setAlpha(Uint8 alpha);

		void destroy();
	private:

		SDL_Texture* m_Texture;
		std::map<std::string,SDL_Texture*> m_TextureMap;

		int m_iWidth;
		int m_iHeight;
	};
}

#endif
