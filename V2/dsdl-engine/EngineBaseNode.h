#ifndef _ENGINEBASENODE_
#define _ENGINEBASENODE_

/**
* Engine Base node root for all elements
*/
#include "EngineDefines.h"
#include "ResourceTexture.h"
#include "CollisionShape.h"


namespace DsdlEngine {

	class EngineBaseNode{
	public:

		///Constructor
		EngineBaseNode();

		///Virtual Deconstructor
		virtual ~EngineBaseNode();

		///Virtual destroy
		virtual void destroy();

		///Load Node
		bool load(SDL_Renderer* r);


		/*
		*Render Node
		*/
		void render(SDL_Renderer* r);
		///Render Node as animation of frames
		void renderAnimation(SDL_Renderer* r);
		///Render box2d collision shape
		void renderCollisionShape(SDL_Renderer* r, CollisionShape* shape);
		
		///Set position of node
		void setPosition(const Vec2& pos) { m_position.x_ = pos.x_, m_position.y_ = pos.y_; };
		void setPositionX(int x) { m_position.x_ = x; }
		void setPositionY(int y) { m_position.y_ = y; }

		const Vec2 getPosition() const { return m_position; }

		//Content Size
		void setSize(Size si) { m_size.x_ = si.w_; m_size.y_ = si.h_; }
		void setWidth(int w) { m_size.x_ = w; };
		void setHeight(int h) { m_size.y_ = h; };

		const Vec2 getContentSize() const { return m_size; }

		//Rotate Node
		//TODO

		//Scale Node
		//TODO
		void scaleWidth(float scale) { m_size.x_ =m_size.x_ * scale; }
		void scaleHeight(float scale) { m_size.y_ = m_size.y_ * scale; }


		//Get Assets Path
		void setAssetPath(std::string path) { m_assetPath = path; }
		std::string getAssetsPath() { return m_assetPath; }


		//Get And Set Node Type
		NodeType getNodeType() { return nodeType; }
		void setEngineNodeType(NodeType type) { nodeType = type; }


		//Set Opacity of texture 0 - 255
		void setOpacity(int opacity);
		
		//Get Node texture
		ResourceTexture* getEngineTexture() { return m_engineTexture; }

		//Update LabelText
		void updateLabelText(std::string text);


		//Get Node Bounding box
		SDL_Rect* getBoundingBox() { return m_objectBoundingBox; }
		void setBoundingBox(Vec2 pos, Vec2 size) { m_objectBoundingBox->x = pos.x_; m_objectBoundingBox->y = pos.y_; m_objectBoundingBox->w = size.x_; m_objectBoundingBox->h = size.y_; }
	
	
	protected:

		std::string m_assetPath;

		EngineBaseNode* m_node;

		NodeType nodeType = NodeType::BASENODE;

		ResourceTexture* m_engineTexture;
		SDL_Rect* m_objectBoundingBox;

		//nodes position Vec2
		Vec2 m_position;
		Vec2 m_size;

		int m_numFrames, m_frame, m_opacity;


		SDL_Rect m_gSpriteClips[14];	//frames for animation
		SDL_Rect* m_currentFrame;		//current animation frame


		// For labels
		std::string m_labelText;
		int m_textSize;
		SDL_Color m_textColor;

		SDL_Color m_buttonbg;
		SDL_Surface* m_btnbg;
		SDL_Rect m_rect;

		TTF_Font* m_font;
		std::map<std::string, TTF_Font*> m_FontMap;

		CollisionShape* m_CollisionShape;
	};
}

#endif