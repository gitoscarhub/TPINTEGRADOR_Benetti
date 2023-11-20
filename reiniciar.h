
#include "stdafx.h"

using namespace sf;

class reiniciando {
	Texture _reiniciar;
	Sprite reiniciar;
public:
	reiniciando() {
		_reiniciar.loadFromFile("reiniciar.png");
		reiniciar.setTexture(_reiniciar);
		reiniciar.setPosition(50, 550);
	}
	Vector2f ObtenerPosicion() {
		return reiniciar.getPosition();
	}
	void Dibujar(RenderWindow *wnd) {
		wnd->draw(reiniciar);
	}
	bool EstaEncima(float x, float y) {
		FloatRect bounds = reiniciar.getGlobalBounds();
		return bounds.contains(x, y);
	}
};
