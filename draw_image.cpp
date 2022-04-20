#include <SFML/Graphics.hpp>
int main() {
	sf::Texture texture;
	if (!texture.loadFromFile("lena.ppm"))
	{
		// erreur...
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	// Création de la fenêtre
	sf::Vector2u sz = texture.getSize();
	sf::RenderWindow window(sf::VideoMode(sz.y, sz.x), "image");
		// Boucle principale
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event)) {
				// Demande de fermeture de la fenêtre
				if (event.type == sf::Event::Closed)
					window.close();
			}
			// On efface la fenêtre (en blanc)
			window.clear(sf::Color::White);
			// Affichage du sprite
			window.draw(sprite);
			// Mise à jour de la fenêtre
			window.display();
		}
	return 0;
}