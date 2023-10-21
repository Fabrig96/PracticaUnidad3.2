//MAVI - Unidad 3 - Ejercicio 2
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

Texture texture_cw;
Texture texture_cb;

int main() {

	sf::RenderWindow App(sf::VideoMode(800, 800, 32), "Tablero de Ajedrez");

	texture_cw.loadFromFile("Unidad3_Assets/chessw.png");
	texture_cb.loadFromFile("Unidad3_Assets/chessb.png");

	sf::Sprite sprite_cw(texture_cw);  //Sprite casilla blanca
	sf::Sprite sprite_cb(texture_cb);  //Sprite casilla negra

	std::vector<sf::Sprite> spritesCw; // Vector que almacena sprites de casillas blancas
	std::vector<sf::Sprite> spritesCb; // Vector que almacena sprites de casillas negras

	//Recorridos para crear sprites de casillas blancas y negras

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			sprite_cw.setScale(100.0f / 128.0f, 100.0f / 128.0f);
			if ((i + j) % 2 == 0) {
				sprite_cw.setPosition(i * 100.0f, j * 100.0f);
				spritesCw.push_back(sprite_cw);
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			sprite_cb.setScale(100.0f / 128.0f, 100.0f / 128.0f);
			if ((i + j) % 2 != 0) {
				sprite_cb.setPosition(i * 100.0f, j * 100.0f);
				spritesCb.push_back(sprite_cb);
			}
		}
	}

	while (App.isOpen())
	{
		sf::Event event;
		while (App.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				App.close();
		}

		App.clear();

		//Iteraciones para dibujar las casillas almacenadas
		for (const auto& sprite : spritesCw) {
			App.draw(sprite);
		}
		for (const auto& sprite : spritesCb) {
			App.draw(sprite);
		}

		App.display();
	}

	return 0;
}
