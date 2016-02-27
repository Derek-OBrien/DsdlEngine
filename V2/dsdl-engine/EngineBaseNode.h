#ifndef _ENGINEBASENODE_
#define _ENGINEBASENODE_

#include "EngineDefines.h"
#include "ResourceTexture.h"


namespace DsdlEngine {

	class EngineBaseNode{
	public:
		EngineBaseNode();
		virtual ~EngineBaseNode();

	
		//Render Node
		void render(SDL_Renderer* r);
		void renderAnimation(SDL_Renderer* r);

		bool load(SDL_Renderer* r);

		//Set position of node
		void setPosition(const Vec2& pos) { position.x_ = pos.x_, position.y_ = pos.y_; };
		void setPositionX(int x) { position.x_ = x; }
		void setPositionY(int y) { position.y_ = y; }

		Vec2 getPosition() { return position; }

		//Rotate Node
		//TODO

		//Scale Node
		//TODO

		//Get Assets Path
		void setAssetPath(std::string path) { m_assetPath = path; }
		std::string getAssetsPath() { return m_assetPath; }


		//Get And Set Node Type
		NodeType getNodeType() { return nodeType; }
		void setEngineNodeType(NodeType type) { nodeType = type; }


		//Set Dimensions
		//Content Size
		void setSize(Size si) { size.w_ = si.w_; size.h_ = si.h_; }
		void setWidth(int w) { size.w_ = w; };
		void setHeight(int h) { size.h_ = h; };

		Size getContentSize() { return size; }

		virtual void destroy();

	protected:

		NodeType nodeType = NodeType::BASENODE;

		ResourceTexture* engineTexture;
		SDL_Rect objectBoundingBox;

		//nodes position Vec2
		Vec2 position;
		Size size;

		int m_numFrames, m_frame;


		SDL_Rect m_gSpriteClips[14];	//frames for animation
		SDL_Rect* m_currentFrame;		//current animation frame


		// For labels
		std::string labelText;
		int textSize;
		SDL_Color textColor;

		SDL_Surface* btnbg;
		SDL_Rect rect;
		SDL_Rect labelBorder;

		SDL_Color buttonbg;


	private:

		std::string m_assetPath;
		TTF_Font* font;
		std::map<std::string, TTF_Font*> m_FontMap;
	};
}

#endif