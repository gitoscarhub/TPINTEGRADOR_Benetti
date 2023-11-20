
#include "stdafx.h"

using namespace sf;

class saliendo {
	Texture _salir;
	Sprite salir;
public:
	saliendo() {
		_salir.loadFromFile("salir.png");
		salir.setTexture(_salir);
		salir.setPosition(50, 500);
	}
Vector2f ObtenerPosicion() {
		return salir.getPosition();
	}
void Dibujar(RenderWindow *wnd) {

	wnd->draw(salir);
}
bool EstaEncima(float x, float y) {
	FloatRect bounds = salir.getGlobalBounds();

	return bounds.contains(x, y);
}
};
