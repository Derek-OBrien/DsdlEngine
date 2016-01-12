#ifndef _RESOURCETEXTURE_
#define _RESOURCETEXTURE_

#include <SDL.h>

#include <string>

namespace DsdlEngine{

	class ResourceTexture
	{
	public:
		ResourceTexture();
		~ResourceTexture();

		ResourceTexture loadTexture(std::string texturePath, SDL_Renderer* r);
		bool loadFromFile(std::string texturePath, SDL_Renderer* r);
		void render(int x, int y, SDL_Rect* clip, SDL_Renderer* r);

	private:
	
		SDL_Texture* m_Texture = NULL;

		int m_iWidth = 0;
		int m_iHeight = 0;
	};
}

#endif
