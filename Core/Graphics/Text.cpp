#include "Text.h"

#include "Graphics.h"
#include "FontAsset.h"


namespace Monocle
{
	Text::Text(const FontAsset* font):
        Entity(),
        font(font),
        text(""),
        alignment(TEXTALIGN_LEFT)
	{
	}
    
	Text::Text(const FontAsset* font, const std::string& text):
        Entity(),
        font(font),
        text(text),
        alignment(TEXTALIGN_LEFT)
	{
	}

    
	void Text::Render()
	{
        Entity::Render();
        
		Graphics::PushMatrix();
        
		Graphics::Translate(position);
		Graphics::SetBlend(BLEND_ALPHA);
		Graphics::SetColor(color);
		Graphics::BindFont(font);
        
		Graphics::RenderText(*font, text, 0, 0, alignment);
        
		Graphics::PopMatrix();
	}
}
