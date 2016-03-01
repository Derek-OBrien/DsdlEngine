#ifndef _LAYER_
#define _LAYER_

#include "EngineBaseNode.h"
#include "ResourceTexture.h"

namespace DsdlEngine{
	class Layer : public EngineBaseNode
	{
	public:
		Layer ();
		virtual ~Layer ();

	
		void destroy();

		void loadNodes(SDL_Renderer* r);
		void drawNodes(SDL_Renderer* r);
		void drawBox2dNodes(SDL_Renderer* r);

		std::vector<EngineBaseNode*> layerNodes;
		void addNodeToLayer(EngineBaseNode* node);

		std::vector<b2Body*> box2dNodes;
		void addBox2dNodes(b2Body* body);
		
	private:

		SDL_Rect box2dRect;

		ResourceTexture m_LayerTexture;


		b2Vec2 lowerVertex;
		b2Vec2 heigherVertex;
		int bodyWidth;
		int bodyHeight;

	};
}
#endif