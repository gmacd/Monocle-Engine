#pragma once

#include <string>

#include "Entity.h"
#include "Graphics.h"


namespace Monocle
{
    class FontAsset;
    
    // Basic text class
    class Text: public Entity
	{
	public:
		Text(const FontAsset* font);
		Text(const FontAsset* font, const std::string& text);
        
		void Render();
        
		void SetFont(const FontAsset* font) { this->font = font; }
		void SetText(const std::string& text) { this->text = text; }
        void SetAlignment(TextAlign alignment) { this->alignment = alignment; }
        
	protected:
		const FontAsset* font;
		std::string text;
        TextAlign alignment;
	};
}
