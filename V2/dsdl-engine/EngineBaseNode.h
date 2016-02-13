#ifndef _ENGINEBASENODE_
#define _ENGINEBASENODE_

#include "EngineDefines.h"
#include "ResourceTexture.h"


namespace DsdlEngine{




	class EngineBaseNode
	{
	public:
		EngineBaseNode();
		~EngineBaseNode();
		
		//void create(int width, int height, std::string path);

		//Render Node
		 void render(SDL_Renderer* r);
		 bool load(SDL_Renderer* r);

		 void spriteAnimation(SDL_Renderer* r);

		//Set position of node
		void setPosition(const Vec2& pos){ position.x_ = pos.x_, position.y_ = pos.y_; };
		void setPositionX(int x){ position.x_ = x; }
		void setPositionY(int y){ position.y_ = y; }

		Vec2 getPosition(){ return position; }
		
		//Content Size
		Size getContentSize(){ return Size(width, height); }

		//Get Assets Path
		void setAssetPath(std::string path){ m_assetPath = path; }
		std::string getAssetsPath(){ return m_assetPath; }


		//Get And Set Node Type
		NodeType getNodeType(){ return nodeType; }
		void setEngineNodeType(NodeType type){ nodeType = type; }

		//Set Dimensions
		void setWidth(){};
		void setHeight(){};
		
		virtual void destroy();
	protected:

		NodeType nodeType = NodeType::BASENODE;

		ResourceTexture* engineTexture ;
		SDL_Rect objectBoundingBox;

		//nodes position Vec2
		Vec2 position;
		int width, height;

		int m_numFrames;

		SDL_Rect m_gSpriteClips[14];	//frames for animation
		SDL_Rect* m_currentFrame;		//current animation frame

		int m_frame;


		// For labels
		std::string labelText;
		int textSize;
		SDL_Color textColor;


		SDL_Rect rect;
		SDL_Color buttonbg;
		int m_BtnHeight;
		int m_BtnWidth;

	private:

		std::string m_assetPath;


		TTF_Font* font;

		std::map<std::string, TTF_Font*> m_FontMap;
	};
}

#endif