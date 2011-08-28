#pragma once

namespace Monocle
{
    class Graphic;
    class FileNode;
    
    
    class GraphicFactory
    {
    public:
        static Graphic* Create(FileNode* node);
    };
}
