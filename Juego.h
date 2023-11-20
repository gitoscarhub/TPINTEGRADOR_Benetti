//#pragma once : es una directiva del preprocesador en los lenguajes de C y C++ que se utiliza
//para asegurarse de que un archivo de encabezado se incluya una sola vez en un programa. (Introducción a la programacion)
#pragma once
#include "stdafx.h"

using namespace sf;


class Juego
{
private:
	RenderWindow *_wnd;
	mira *_disparo;
	enemigo *_enemigo;
	inocente *_inocente;
	fondo   *_fondo;
	saliendo *_saliendo;
	reiniciando *_reiniciando;
	Text _puntaje;
	Font _fuente;
	int _puntos, derrotas, inocentes;
	Sprite derrotado1;
	Sprite derrotado2;
	Sprite derrotado3;
	Texture _derrotado1;
	Texture _derrotado2;
	Texture _derrotado3;
	Sprite inocente1;
	Sprite inocente2;
	Sprite inocente3;
	Texture _inocente1;
	Texture _inocente2;
	Texture _inocente3;
	Sprite inicio;
	Texture _inicio;

	Clock _reloj;
	Time dt;
	int disparo;
	bool Entrar;
	

	void _actualizarPuntaje() {
		char pts[100];
		_itoa_s((_puntos * 10), pts, 10);
		_puntaje.setString(pts);

	};


public:

	Juego() {
		_wnd = new RenderWindow(VideoMode(800, 600), "Wanted Benetti");

		_disparo = new mira();
		_enemigo = new enemigo;
		_inocente = new inocente;
		_fondo = new fondo;
		_saliendo = new saliendo;
		_reiniciando = new reiniciando;
	
		_puntos = 0;
		inocentes = 0;
		derrotas = 0;
		_actualizarPuntaje();
		_fuente.loadFromFile("arial.ttf");
		_puntaje.setFont(_fuente);
		_puntaje.setPosition(0.0f, 0.0f);
		_puntaje.setCharacterSize(50.0f);
		_puntaje.setFillColor(Color::Blue);
		
		_inicio.loadFromFile("fondoinicio.png");
		inicio.setTexture(_inicio);
		_derrotado1.loadFromFile("derrotado.png");
		derrotado1.setTexture(_derrotado1);
		derrotado1.setPosition(400, 500);
		_derrotado2.loadFromFile("derrotado2.png");
		derrotado2.setTexture(_derrotado2);
		derrotado2.setPosition(400, 500);
		
		_inocente1.loadFromFile("inocente.png");
		inocente1.setTexture(_inocente1);
		inocente1.setPosition(400, 450);
		_inocente2.loadFromFile("inocente2.png");
		inocente2.setTexture(_inocente2);
		inocente2.setPosition(400, 450);
		Vector2i mousePosition = Mouse::getPosition(*_wnd);
		_disparo->Posicionar(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	}

	void Loop() {

		while (_wnd->isOpen()) {
			_wnd->clear();
			ProcesarEventos();
			Actualizar();
			Dibujar();
		}

	}
	void ProcesarEventos() {
		Event evt;
		
		
		while (_wnd->pollEvent(evt)) {
			switch (evt.type) {
			case Event::Closed:
				_wnd->close();
				break;

			case Event::MouseMoved:
				_disparo->Posicionar(evt.mouseMove.x, evt.mouseMove.y);
				break;

			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Button::Left)
					dt = _reloj.getElapsedTime();
					Disparar(); 

				break;
			}
		}
		
	}


	int dibu() {
		srand(time(0));
		int saltar;
		saltar = (rand() % 2);
		return(saltar);
	}
	void Actualizar() {
		
		for (size_t i = 0; i < 1; i++) {
			_fondo[i].ActualizarF(_wnd);
			if (dibu()==0) {
				_enemigo[i].ActualizarE(_wnd);
	
			}else
					_inocente[i].ActualizarI(_wnd);
		}
	}



	void Disparar() {
		
		//chequeamos colisiones con el disparo
		Vector2f playerPos = _disparo->ObtenerPosicion();
		Juego jugando;
		for (int i = 0; i < 1; i++) {
			
			if (_saliendo[i].EstaEncima(playerPos.x, playerPos.y)) { exit(1); }
			if (_reiniciando[i].EstaEncima(playerPos.x, playerPos.y)) { jugando.Loop(); }
		}
		disparo =5;
		for (int i = 0; i < 1; i++) {
		
			if (_enemigo[i].EstaActivo()) {
				if (_enemigo[i].EstaEncima(playerPos.x, playerPos.y)) {
					if (disparo < dt.asSeconds()) {
						_puntos++;
					}else derrotas++;
					}}

			if (_inocente[i].EstaActivo()) {

				if (_inocente[i].EstaEncima(playerPos.x, playerPos.y)) {
					inocentes++;
					_puntos--;
				}
			}
			_actualizarPuntaje();
			_reloj.restart();
		}
	}


	void Dibujar() {

		_wnd->clear();
		_wnd->draw(inicio);
		

		for (int i = 0; i < 1; i++) {


			if (_enemigo[i].EstaActivo()) {
				_enemigo[i].Dibujar(_wnd);
			}


			if (_inocente[i].EstaActivo()) {
				_inocente[i].Dibujar(_wnd);
			}

			if (_fondo[i].EstaActivo()) {
				_fondo[i].Dibujar(_wnd);
			}

		}


		for (int i = 0; i < 1; i++) {

			if (derrotas == 1) {
				_wnd->draw(derrotado1);
			}
			else
				if (derrotas == 2) {
					_wnd->draw(derrotado2);
				}
				else
					if (derrotas == 3) {						
						_fondo->Dibujar(_wnd);
						_wnd->setTitle("PERDISTE TRES VIDAS: Fin de Juego. Este es tu puntaje");
						_wnd->draw(_puntaje);
					}
			for (int i = 0; i < 1; i++) {
				if (inocentes == 1) {
					_wnd->draw(inocente1);
				}
				else
					if (inocentes == 2) {
						_wnd->draw(inocente2);
					}
					else
						if (inocentes == 3) {
							_fondo->Dibujar(_wnd);	
							_wnd->setTitle("MATASTE TRES INOCENTES: Fin de Juego. Este es tu puntaje");
							_wnd->draw(_puntaje);
						}
			}
			_saliendo->Dibujar(_wnd);
			_reiniciando->Dibujar(_wnd);
		}
	



		_disparo->Dibujar(_wnd);
		_wnd->draw(_puntaje);
		_wnd->display();

	}



	~Juego() {
		delete _wnd;
		delete _disparo;
		delete _enemigo;
		delete _inocente;
		delete _fondo;
	}

};

