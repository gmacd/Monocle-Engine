#pragma once

#include <map>
#include <string>

#include "Editor.h"
#include "Input.h"


namespace Monocle
{
    class Text;
    class Tileset;
    
    
    class TilemapEditorCursor: public Entity
    {
    public:
        TilemapEditorCursor();
        
        void Update();
        void Render();

        void SetTileset(Tileset* tileset) { this->tileset = tileset; }
        
        void NextTile();
        void PrevTile();

    protected:
        Tileset* tileset;
        int tileID;
    };
    
    
    class TilemapLevelEditor: public Editor
    {
    public:
        TilemapLevelEditor();
        
        void Enable();
        void Disable();
        
        void Update();
        void Render();
        
        void SetScene(Scene* scene) { this->scene = scene; }
        void SetTileset(Tileset* tileset) { cursor->SetTileset(tileset); }
                
    protected:
        Scene* scene;
        
        typedef std::map<std::string, KeyCode> KeyMappingsType;
        KeyMappingsType keyMappings;
        
        Text* text;
        TilemapEditorCursor* cursor;
        
        void UpdateInput();
    };
}