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
		void render(int x, int y, SDL_Renderer* r, SDL_Rect* clip = NULL);

		void setBlendMode(SDL_BlendMode blending);
		void setAlpha(Uint8 alpha);

		void destroy();
	private:

		SDL_Texture* m_Texture;
		std::map<std::string,SDL_Texture*> m_TextureMap;

		int m_iWidth = 0;
		int m_iHeight = 0;
	};
}

#endif
