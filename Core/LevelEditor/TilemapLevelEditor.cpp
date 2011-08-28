#include "TilemapLevelEditor.h"

#include "Level.h"
#include "Text.h"


namespace Monocle
{
    TilemapEditorCursor::TilemapEditorCursor():
        Entity(),
        tileset(NULL),
        tileID(0)
    {
        SetLayer(-50);
    }
    
    void TilemapEditorCursor::Update()
    {
        Entity::Update();
        
        if (tileset)
        {
            position = Input::GetWorldMousePosition();
        }
    }
    
    void TilemapEditorCursor::Render()
    {
        Entity::Render();
        
        if (tileset)
        {
            Graphics::PushMatrix();

            // Border
            Graphics::Translate(position);
            Graphics::BindTexture(NULL);
            Graphics::SetColor(Color::orange);
            Graphics::RenderLineRect(0, 0, 18, 18);

            tileset->RenderTile(tileID, Vector2(1, 1));

            Graphics::PopMatrix();
        }
    }

    void TilemapEditorCursor::NextTile()
    {
        tileID++;
        if (tileID >= 2)
            tileID = 0;
    }
    
    void TilemapEditorCursor::PrevTile()
    {
        tileID--;
        if (tileID < 0)
            tileID = 1;
    }

    
    //////////////////////////////////////////////////////////////////////////

    
    TilemapLevelEditor::TilemapLevelEditor():
        Editor(),
        scene(NULL)
    {
        // Tab to toggle editor on/off is always active
        Input::DefineMaskKey("toggleEditor", KEY_TAB);

        // Key bindings
        keyMappings.insert(std::make_pair("prevTile", KEY_COMMA));
        keyMappings.insert(std::make_pair("nextTile", KEY_PERIOD));
        
        // Info
        const FontAsset* font = Level::GetFont("default15");
        text = new Text(font);
        text->color = Color::black;
        text->position = Vector2(Graphics::GetVirtualWidth() - 5, 15);
        text->SetAlignment(TEXTALIGN_RIGHT);
        AddChild(text);
        
        // Cursor
        cursor = new TilemapEditorCursor();
        AddChild(cursor);
    }
    
    
    void TilemapLevelEditor::Enable()
    {
        Editor::Enable();
        
        // Enable all bindings
        KeyMappingsType::const_iterator iter = keyMappings.begin();
        KeyMappingsType::const_iterator end = keyMappings.end();
        for (; iter != end; ++iter)
        {
            const std::string& label = (*iter).first;
            KeyCode keyCode = (*iter).second;
            Input::DefineMaskKey(label, keyCode);
        }
        
        text->SetText("Editor active");
    }
    
    void TilemapLevelEditor::Disable()
    {
        Editor::Disable();
        
        // Disable all bindings
        KeyMappingsType::const_iterator iter = keyMappings.begin();
        KeyMappingsType::const_iterator end = keyMappings.end();
        for (; iter != end; ++iter)
        {
            const std::string& label = (*iter).first;
            KeyCode keyCode = (*iter).second;
            Input::UndefineMaskKey(label, keyCode);
        }
        
        text->SetText("Editor inactive");
    }
    
    void TilemapLevelEditor::Update()
    {
        Editor::Update();
        
        UpdateInput();
    }
    
    void TilemapLevelEditor::UpdateInput()
    {
        if (Input::IsKeyMaskReleased("toggleEditor"))
            ToggleEnabled();
        
        if (Input::IsKeyMaskReleased("nextTile"))
            cursor->NextTile();
        if (Input::IsKeyMaskReleased("prevTile"))
            cursor->PrevTile();
    }
    
    void TilemapLevelEditor::Render()
    {
        Editor::Render();
    }
}
