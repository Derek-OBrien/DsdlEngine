
/*
	Engine Texture
	Handles all the loading for different textures in the engine
	Handles main call to render texture

	Link between ( Engine / Game ) and SDL Textures
*/


#include "ResourceTexture.h"
#include "EngineError.h"
#include "FileIO.h"


namespace DsdlEngine{

	ResourceTexture::ResourceTexture(){
		m_Texture = NULL;
		m_iHeight = 0;
		m_iWidth = 0;
	}
	ResourceTexture::~ResourceTexture(){
		destroy();
	}

	//Load Texture
	ResourceTexture ResourceTexture::loadTexture(std::string texturePath, SDL_Renderer* r){
		ResourceTexture texture;
		if (!texture.loadFromFile(texturePath, r))
			SDL_Log("Texture load failed");

		return texture;
	}


	//Load Sprite from file
	bool ResourceTexture::loadFromFile(std::string texturePath, SDL_Renderer* r){
		std::string temp;


		/*
			if defs here for different platfoms as windows needs to find assets in root folder which i have created
			but android needs to find assets in the jni/assets folder. android is allready set up to go look in this folder 
			there for all that was needed was the name and in the windows platfom i add on path to the assets folder so it just has to look for name of file

			this will need to be done to each asset type loding function eg. audio, fonts, images
		*/

/**
#ifdef __WIN32__
	//	SDL_Log("Loading Assets For Windows Platform");
		temp = "../../assets/" + texturePath;
#endif

#ifdef __ANDROID__
	//	SDL_Log("Loading Assets for Android Platform");
		temp = texturePath;
#endif
*/
		temp = FileIO::getInstance()->getWritablePath() + texturePath;

		auto it = m_TextureMap.find(temp);

		SDL_Texture* newTexture = NULL;
		SDL_Surface* loadedSurface = NULL;

		if (it == m_TextureMap.end()){
			//Load image at specified path
			loadedSurface = IMG_Load(temp.c_str());


			if (loadedSurface == NULL)
				DEBUG_MSG("SDL_image Error : " + std::string(IMG_GetError()));
			else{
				//SDL_Log("Flie loaded");
				//Color key image
				SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

				//Create texture from surface pixels
				newTexture = SDL_CreateTextureFromSurface(r, loadedSurface);
				if (newTexture == NULL){
					DEBUG_MSG("SDL_CreateTextureFromSurface Error : " + std::string(IMG_GetError()));
				}
				else{
					//Get image dimensions
					m_iWidth = loadedSurface->w;
					m_iHeight = loadedSurface->h;
				}
				//Get rid of old loaded surface
				SDL_FreeSurface(loadedSurface);
			}
			 
			m_TextureMap[temp] = newTexture;
		}
		else{
			newTexture = it->second;
		}
		//Return success
		m_Texture = newTexture;
		return newTexture != NULL;
	}


	//Load ttf
	bool ResourceTexture::loadTTF(std::string text, SDL_Color color, TTF_Font* myfont, SDL_Renderer* r){

		destroy();

		SDL_Surface* textSurface = TTF_RenderText_Blended(myfont, text.c_str(), color);

		//m_Texture = nullptr;

		if (textSurface == NULL){
			DEBUG_MSG("TTF_RenderText_Blended Error : " + std::string(TTF_GetError()));
		}
		else{
			m_Texture = SDL_CreateTextureFromSurface(r, textSurface);
			if (m_Texture == NULL){
				DEBUG_MSG("TTF_RenderText_Blended Error : " + std::string(TTF_GetError()));
			}
			else{
				m_iWidth = textSurface->w;
				m_iHeight = textSurface->h;
			}

			SDL_FreeSurface(textSurface);
		}
		//m_Texture = newTexture;

		return m_Texture != NULL;
	}


	//Basic render
	void ResourceTexture::render(Vec2 p, Vec2 s, SDL_Renderer* r, SDL_Rect* clip){
		//Set rendering space and render to screen
		SDL_Rect renderQuad;
		if (s.x_ != NULL && s.y_ != NULL) {//For Sprites
			renderQuad = { p.x_, p.y_, s.x_, s.y_ };

			///SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
			///SDL_RenderDrawRect(r, &renderQuad);
		}
		else {	//For TTf Labels 
			renderQuad = { p.x_, p.y_, m_iWidth, m_iHeight };

			///SDL_SetRenderDrawColor(r, 0, 0, 255, 255);
			///SDL_RenderDrawRect(r, &renderQuad);
		}
		
		//Set clip rendering dimensions
		if (clip != NULL){
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}

		//Render to screen
		SDL_RenderCopy(r, m_Texture, clip, &renderQuad);
	}


	//Clean up 
	void ResourceTexture::destroy(){
		if (m_Texture != NULL){
			SDL_DestroyTexture(m_Texture);
			m_Texture = NULL;
			m_iWidth = 0;
			m_iHeight = 0;
		}
	}
	
	/*
		Set Texture Blend Mode
	*/
	void ResourceTexture::setBlendMode(SDL_BlendMode blend){
		SDL_SetTextureBlendMode(m_Texture, blend);
	}


	/*
		Set Alpha value of texture for transperence
		@parma alpha value of texture alpha 0 to 255
	*/
	void ResourceTexture::setAlpha(Uint8 alpha){
		//Modulate texture alpha
		SDL_SetTextureAlphaMod(m_Texture, alpha);
	}

}