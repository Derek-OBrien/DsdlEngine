
#include "ResourceTexture.h"
#include <string>
#include <iostream>

#include "EngineError.h"
#include <SDL_image.h>


namespace DsdlEngine{

	ResourceTexture::ResourceTexture(){}
	ResourceTexture::~ResourceTexture(){}


	ResourceTexture ResourceTexture::loadTexture(std::string texturePath, SDL_Renderer* r){
		ResourceTexture texture;
		if (!texture.loadFromFile(texturePath, r))
			dsdl_error("Texture load failed");

		return texture;
	}


	bool ResourceTexture::loadFromFile(std::string texturePath, SDL_Renderer* r){

		const char* path = texturePath.c_str();

		if (m_Texture != NULL){
			SDL_DestroyTexture(m_Texture);
			m_Texture = NULL;
			m_iWidth = 0;
			m_iHeight = 0;
		}

		SDL_Texture* newTexture = NULL;

		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load(texturePath.c_str());
		if (loadedSurface == NULL)
			std::cout << "Unable to load image " << path << "\n SDL_image Error : " << IMG_GetError() << std::endl;
		else{
			std::cout << "Flie loaded" << std::endl;
			//Color key image
			//SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(r, loadedSurface);
			if (newTexture == NULL){
				std::cout << "\nUnable to create texture from %s!\n SDL Error: %s" << path << SDL_GetError() << std::endl;
			}
			else{
				//Get image dimensions
				m_iWidth = loadedSurface->w;
				m_iHeight = loadedSurface->h;
			}
			//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);
		}

		//Return success
		m_Texture = newTexture;
		return newTexture != NULL;
	}


	void ResourceTexture::render(int x, int y, SDL_Rect* clip, SDL_Renderer* r){
		//Set rendering space and render to screen
		SDL_Rect renderQuad = { x, y, m_iWidth, m_iHeight };

		//Set clip rendering dimensions
		if (clip != NULL){
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}

		//Render to screen
		SDL_RenderCopy(r, m_Texture, clip, &renderQuad);
	}

}