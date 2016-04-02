#ifndef _ENGINEBASENODE_
#define _ENGINEBASENODE_

#include "EngineDefines.h"
#include "ResourceTexture.h"
#include "CollisionShape.h"


/**
*	@author Derek O Brien
*/


namespace DsdlEngine {
	/**
	* EngineBaseNode is the root for all elements in the framework
	*/
	class EngineBaseNode {
	public:
		/**
		*	Constructor
		*/
		EngineBaseNode();

		/**
		*	Deconstructor
		*/
		virtual ~EngineBaseNode();

		/**
		* virtual destroy, destorys node when it leaves scope.
		*/
		virtual void destroy();

		/**
		*	virtual cleanup, for cleaning up node if it has to be reoved.
		*/
		virtual void cleanup();
		
		/**
		*	load, load node as SDL_Texture. 
		*	@parma r as SDL_Renderer argument.
		*	@return bool.
		*/
		bool load(SDL_Renderer* r);

		/**
		*	render, Render node to window.
		*	@parma r as SDL_Renderer argument
		*/
		void render(SDL_Renderer* r);

		
		/**
		*	rendereCollisionShape, Render collision shape for node.
		*	@parma r as a SDL_Rendere argumnet.
		*	@parma shape as a CollisionShape pointer argument.
		*/		
		void renderCollisionShape(SDL_Renderer* r, CollisionShape* shape);

		/**
		*	setPosition, Set position of the node.
		*	@parma pos as a const Vec2 argument
		*/
		void setPosition(const Vec2& pos) { m_position.x_ = pos.x_, m_position.y_ = pos.y_; };
		
		/**
		*	setPositionX, Set X position of the node.
		*	@parma x as a const int argument
		*/
		void setPositionX(int x) { m_position.x_ = x; }

		/**
		*	setPositionY, Set Y position of the node.
		*	@parma Y as a const int argument
		*/
		void setPositionY(int y) { m_position.y_ = y; }

		/**
		*	getPosition, get position of the node.
		*	@return const Vec2.
		*/
		const Vec2 getPosition() const { return m_position; }

		/**
		*	setSize, Set size of the node.
		*	@parma si as a const Size argument
		*/
		void setSize(Size si) { m_size.x_ = si.w_; m_size.y_ = si.h_; }

		/**
		*	setWidth, Set width of the node.
		*	@parma w as a const int argument
		*/
		void setWidth(int w) { m_size.x_ = w; };

		/**
		*	setHeight, Set height of the node.
		*	@parma h as a const int argument
		*/
		void setHeight(int h) { m_size.y_ = h; };

		/**
		*	getContentSize, get size of the node.
		*	@return Vec2 size of the node
		*/
		const Vec2 getContentSize() const { return m_size; }

		//Set Anchor Point
		//TODO

		//Rotate Node
		//TODO

		/**
		*	scaleNode, Scale the node size by value passed in.
		*	@parma scale as a float argument
		*/
		void scaleNode(float scale) { m_size.x_ = m_size.x_ * scale; m_size.y_ = m_size.y_ * scale; }

		/**
		*	scaleWidth, Scale the width of the node.
		*	@parma scale as a float argument
		*/
		void scaleWidth(float scale) { m_size.x_ = m_size.x_ * scale; }

		/**
		*	scaleHeight, Scale the height of the node.
		*	@parma scale as a float argument
		*/
		void scaleHeight(float scale) { m_size.y_ = m_size.y_ * scale; }


		/**
		*	setAssetPath, set the path to the asset to be loaded.
		*	@parma path as a std::string argument.
		*/
		void setAssetPath(std::string path) { m_assetPath = path; }

		/**
		*	getAssetsPath, get the path of the asset to be loaded.
		*	@return std::string path to asset.
		*/
		std::string getAssetsPath() { return m_assetPath; }

		/**
		*	getNodeType, get the type of a specific node.
		*	@return NodeType, the type of node.
		*/
		NodeType getNodeType() { return nodeType; }

		/**
		*	setEngineNodeType, set the type for a specific node.
		*	@parma type as a NodeType argument.
		*/
		void setEngineNodeType(NodeType type) { nodeType = type; }

		/**
		*	setOpacity, set the opacity value of a node, defaults to 255 if out of bounds value passed in.
		*	@parma opacity as an int argument between 0 - 255
		*/
		void setOpacity(int opacity);

		/**
		*	getEngineTexture, get the ResourceTexture for the node.
		*	@return ResourceTexture pointer.
		*/
		ResourceTexture* getEngineTexture() { return m_engineTexture; }

		/**
		*	updateLabelText, change the display text of a label.
		*	@parma text as a std::string argument.
		*/
		void updateLabelText(std::string text);

		/**
		*	getBoundingBox, get the nodes SDL bounding box.
		*	@return SDL_Rect pointer.
		*/
		SDL_Rect* getBoundingBox() { return m_objectBoundingBox; }

		/**
		*	setBoundingBox, the the bounding box for the node.
		*	@parma pos as a Vec2 argument.
		*	@parma size as a Vec2 argument.
		*/
		void setBoundingBox(Vec2 pos, Vec2 size);


		/**
		*	setUpdateTextureTrue, control if node texture was changed after initial load.
		*	@parma value as a bool argument.
		*/
		void setUpdateTextureTrue(bool value) { updateTextureInfo = value; }

		/**
		*	isTextureChange, check if the texture was changed.
		*	@return bool.
		*/
		bool isTextureChanged() { return updateTextureInfo; }
	
	protected:

		EngineBaseNode* m_node;								/**< EngineBaseNode node*/
		std::string m_assetPath;							/**< std::string asset path*/
		std::map<std::string, SDL_Texture*> m_TextureMap;	/**< std::map for texture cacheing*/
		NodeType nodeType = NodeType::BASENODE;				/**< NodeType for containing node type*/
		ResourceTexture* m_engineTexture;					/**< ResourceTexture for the node*/
		SDL_Rect* m_objectBoundingBox;						/**< SDL_Rect bounding box for the node*/

		//nodes position Vec2
		Vec2 m_position;									/**< Vec2 Position of the node*/
		Vec2 m_size;										/**< Vec2 Size of the node*/			

		int m_numFrames, m_frame, m_opacity;				/**< int values for frames & opacity*/

		bool updateTextureInfo;								/**< bool for texture control*/

		SDL_Rect m_gSpriteClips[14];						/**< frames rect for animation*/
		SDL_Rect* m_currentFrame;							/**< the current frame rect*/


		// For labels
		TTF_Font* m_font;									/**< the font to use for labels*/
		std::map<std::string, TTF_Font*> m_FontMap;			/**< std::map for caching the font*/

		std::string m_labelText;							/**< std::string to hold label display text*/
		int m_textSize;										/**< int for size of font*/
		SDL_Color m_textColor;								/**< color of the label*/

		//For  Button
		SDL_Color m_buttonbg;								/**< color of button background*/
		SDL_Surface* m_btnbg;								/**< button surface*/
		SDL_Rect m_rect;									/**< button rect*/

		//Node Collision shape
		CollisionShape* m_CollisionShape;					/**< Box2D collision shape of the node*/
	};
}

#endif // !_ENGINEBASENODE_