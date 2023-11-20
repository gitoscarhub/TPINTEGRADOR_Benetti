#pragma once
#include "stdafx.h"
using namespace sf;
class mira{
	Texture _crossTex;
	Sprite _crossSprite;

public:

	mira(){

		_crossTex.loadFromFile("crooshair.png");
		_crossSprite.setTexture(_crossTex);
		_crossSprite.setScale(0.05f, 0.05f);
		Vector2u size = _crossTex.getSize();
		_crossSprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	
	}

	void Dibujar(RenderWindow *wnd){
		//Cambiar el puntero del mouse->problemas con eso!
		Vector2i mousePosition = Mouse::getPosition(*wnd);
		_crossSprite.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
		wnd->draw(_crossSprite);
		
	}

	void Posicionar(float x, float y){
		
		_crossSprite.setPosition(x, y);

	}

	Vector2f ObtenerPosicion(){
		return _crossSprite.getPosition();
	}
};