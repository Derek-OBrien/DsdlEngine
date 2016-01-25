#ifndef _ENGINEBASENODE_
#define _ENGINEBASENODE_

#include "EngineDefines.h"
#include "ResourceTexture.h"


namespace DsdlEngine{

	enum class NodeType{
		BASENODE,
		SPRITE,
		LABEL,
		BUTTON
	};


	class EngineBaseNode
	{
	public:
		EngineBaseNode();
		~EngineBaseNode();
		
		void create(int width, int height, std::string path);
		//Render Node
		void render(SDL_Renderer* r);
		bool load(SDL_Renderer * r);


		//Set position of node
		void setPosition(const Vec2& pos){ position.x_ = pos.x_, position.y_ = pos.y_; };
		void setPositionX(int x){ position.x_ = x; }
		void setPositionY(int y){ position.y_ = y; }


		//Get Assets Path
		void setAssetPath(std::string path){ m_assetPath = path; }
		std::string getAssetsPath(){ return m_assetPath; }

		NodeType getNodeType(){ return nodeType; }
		void setEngineNodeType(NodeType type){ nodeType = type; }


	protected:

		NodeType nodeType = NodeType::BASENODE;

		ResourceTexture* engineTexture ;
		SDL_Rect objectBoundingBox;

		//nodes position Vec2
		Vec2 position;
		int width, height;

		SDL_Rect m_gSpriteClips[30];	//frames for animation
		SDL_Rect* m_currentFrame;		//current animation frame


		// For labels
		TTF_Font* font;


		std::map<std::string, TTF_Font*> m_FontMap;
		std::string labelText;
		std::string fontPath;
		int textSize;
		SDL_Color textColor;


	private:

		std::string m_assetPath;
	};
}

#endif