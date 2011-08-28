#include "Tileset.h"

#include "Assets.h"
#include "Graphics.h"


namespace Monocle
{
	Tileset::Tileset(const std::string &name, const std::string &filename, float tileWidth, float tileHeight)
		: texture(NULL), tileWidth(tileWidth), tileHeight(tileHeight), name(name)
	{
		texture = Assets::RequestTexture(filename, FILTER_NONE);
	}

    
    void Tileset::RenderTile(int tileID, const Vector2& position)
    {
        Graphics::BindTexture(texture);
        
        int tilesPerRow = texture->width / tileWidth;
        
        //printf("%d, %d = %d", tx, ty, tileID);
        if (tileID != -1)
        {
            //printf("%d, %d = %d", tx, ty, tileID);
            
            // get x/y coords of tile in tileset
            int tileX = (tileID % tilesPerRow) * tileWidth;
            int tileY = (tileID / tilesPerRow) * tileHeight;
            
            Vector2 texOffset = Vector2(tileX / (float)texture->width, tileY / (float)texture->height);
            Vector2 texScale = Vector2(tileWidth / (float)texture->width, tileHeight / (float)texture->height);

            // render quad with texture coords set
            Graphics::RenderQuad(tileWidth, tileHeight, texOffset, texScale, position);
        }
    }
}