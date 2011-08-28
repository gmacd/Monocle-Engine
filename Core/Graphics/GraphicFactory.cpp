#include "GraphicFactory.h"

#include "FileNode.h"
#include "Sprite.h"


namespace Monocle
{
    Graphic* GraphicFactory::Create(FileNode* node)
    {
        std::string type;
        node->Read("type", type);
        
        if (type == "sprite")
        {
            return new Sprite(node);
        }
        
        return NULL;        
    }
}
