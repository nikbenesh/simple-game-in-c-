#include <SFML/Graphics.hpp>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include <time.h>

int main(int argc, char *argv[]) {
	char string[100], buffer[100], title[100], string2[100];

	int x, y, apples=0, taken = 0, time_left = 60, lost = 0, answer = 0, 
	stage = 1;

	struct timeval current_time, last_time, last_time2;

	int used_apple_sprites[5] = {0, 0, 0, 0, 0};

	if (argc == 2) 
		strcpy(string, argv[1]);

	srand(time(0));
	
	sf::RenderWindow window(sf::VideoMode(1000, 1000), " ");

	sf::ContextSettings sets = window.getSettings();
	sprintf(title, "scale: %u", sets.depthBits);

	sf::Vector2u size = window.getSize();

	sf::Image icon;
	icon.loadFromFile("img/Saturn.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	sf::Font font;
	font.loadFromFile("font.ttf");

	sf::Text text(string, font, 40);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);
	text.setPosition(200, 200);

	sf::Text text2(string, font, 40);
	text2.setStyle(sf::Text::Bold);
	text2.setFillColor(sf::Color::Red);
	text2.setPosition(200, 230);

	sf::RectangleShape final_button2;
	sf::RectangleShape final_button;

	sf::Texture texture;
	texture.loadFromFile("img/Sun.png");

	sf::Sprite sprite;                                 // hero sprite
	sprite.setTexture(texture);
	sprite.setPosition(600, 800);


	sf::Texture texture2;
	texture2.loadFromFile("img/Uranus.png");

	sf::Sprite sprite2;                                // uranus apple sprite
	sprite2.setTexture(texture2);
	sprite2.setPosition(
		rand() % (size.x - size.x/10) + size.x/10,
		rand() % (size.y - size.y/10) + size.y/10);


	sf::Texture texture1;
	texture1.loadFromFile("img/Jupiter.png");

	sf::Sprite sprite1;                                // jupiter apple sprite
	sprite1.setTexture(texture1);
	sprite1.setPosition(
		rand() % (size.x - size.x/10) + size.x/10,
		rand() % (size.y - size.y/10) + size.y/10);


	sf::Texture texture3;
	texture3.loadFromFile("img/Venus.png");

	sf::Sprite sprite3;                                // venus apple sprite
	sprite3.setTexture(texture3);
	sprite3.setPosition(
		rand() % (size.x - size.x/10) + size.x/10,
		rand() % (size.y - size.y/10) + size.y/10);


	sf::Texture texture4;
	texture4.loadFromFile("img/Neptune.png");

	sf::Sprite sprite4;                                // neptune apple sprite
	sprite4.setTexture(texture4);
	sprite4.setPosition(
		rand() % (size.x - size.x/10) + size.x/10,
		rand() % (size.y - size.y/10) + size.y/10);


	sf::Texture texture5;
	texture5.loadFromFile("img/Mars.png");

	sf::Sprite sprite5;                                // mars apple sprite
	sprite5.setTexture(texture5);
	sprite5.setPosition(
		rand() % (size.x - size.x/10) + size.x/10,
		rand() % (size.y - size.y/10) + size.y/10);



	sf::Sprite apple_sprite0;
	sf::Sprite apple_sprite1;
	sf::Sprite apple_sprite2; 

	sf::Sprite apple_sprites[5] = {sprite1, sprite2, sprite3, sprite4, sprite5};


	sf::Vector2f position  = sprite.getPosition();
	sf::Vector2f position2 = sprite2.getPosition();
	sf::Vector2u sprite2_size = sprite2.getTexture()->getSize();
	sf::Vector2f apple_pos0 = apple_sprite0.getPosition();
	sf::Vector2f apple_pos1 = apple_sprite1.getPosition();
	sf::Vector2f apple_pos2 = apple_sprite2.getPosition();

	gettimeofday(&last_time, NULL);
	gettimeofday(&last_time2, NULL);
	

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();

        if (event.type == sf::Event::Resized) {
		sf::Vector2u new_window_size;

		new_window_size.x = event.size.width;
		new_window_size.y = event.size.height;

		window.setSize(new_window_size);
	}

	}


		if (taken == 0) {
			apple_sprite0 = apple_sprites[rand()%5];
			apple_sprite1 = apple_sprites[rand()%5];
			apple_sprite2 = apple_sprites[rand()%5];

			apple_pos0 = apple_sprite0.getPosition();
			apple_pos1 = apple_sprite1.getPosition();
			apple_pos2 = apple_sprite2.getPosition();
			taken = 1;

			text.setString("stage 1");
			text.setPosition(400, 400);
			window.clear(sf::Color::Black);
			window.draw(text);
			window.display();
			sleep(sf::seconds(3.0));
		}

		
		
		x=0; y=0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) x--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D)) x++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) y++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)   || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) y--;

		if (position.x < -193) 	  sprite.setPosition(size.x, position.y);
		if (position.x > size.x)  sprite.setPosition(-193, position.y);
		if (position.y < -231) 	  sprite.setPosition(position.x, size.y);
		if (position.y > size.y)  sprite.setPosition(position.x, -230);

		position  = sprite.getPosition();

		apple_pos0 = apple_sprite0.getPosition();
		apple_pos1 = apple_sprite1.getPosition();
		apple_pos2 = apple_sprite2.getPosition();


		if (sprite.getGlobalBounds().contains( apple_pos0 )) {
			apples++;
			apple_sprite0.setPosition(
			rand() % (size.x - size.x/10) + size.x/10,
			rand() % (size.y - size.y/10) + size.y/10);
			apple_pos0 = apple_sprite0.getPosition();
			taken = 1;
		}

		if (sprite.getGlobalBounds().contains( apple_pos1 )) {
			apples++;
			apple_sprite1.setPosition(
			rand() % (size.x - size.x/10) + size.x/10,
			rand() % (size.y - size.y/10) + size.y/10);
			apple_pos1 = apple_sprite1.getPosition();
			taken = 1;
		}

		if (sprite.getGlobalBounds().contains( apple_pos2 )) {
			apples++;
			apple_sprite2.setPosition(
			rand() % (size.x - size.x/10) + size.x/10,
			rand() % (size.y - size.y/10) + size.y/10);
			apple_pos2 = apple_sprite2.getPosition();
			taken = 1;
		}

		gettimeofday(&current_time, NULL);
	
		if ((last_time2.tv_sec+1) <= current_time.tv_sec) {
			time_left -= (current_time.tv_sec - last_time2.tv_sec);
			gettimeofday(&last_time2, NULL);
		}


		if (apple_pos0.x + apple_sprite0.getTexture()->getSize().x >= size.x ||
			apple_pos0.y + apple_sprite0.getTexture()->getSize().y >= size.y ||
			apple_pos0.x - apple_sprite0.getTexture()->getSize().x <= 0 ||
			apple_pos0.y - apple_sprite0.getTexture()->getSize().y <= 0) {
			apple_sprite0.setPosition(
			rand() % (size.x - size.x/10) + size.x/10,
			rand() % (size.y - size.y/10) + size.y/10);
			apple_pos0 = apple_sprite0.getPosition();
		}
			

		if (apple_pos1.x + apple_sprite1.getTexture()->getSize().x >= size.x ||
			apple_pos1.y + apple_sprite1.getTexture()->getSize().y >= size.y ||
			apple_pos1.x - apple_sprite1.getTexture()->getSize().x <= 0 ||
			apple_pos1.y - apple_sprite1.getTexture()->getSize().y <= 0) {
			apple_sprite1.setPosition(
			rand() % (size.x - size.x/10) + size.x/10,
			rand() % (size.y - size.y/10) + size.y/10);
			apple_pos1 = apple_sprite1.getPosition();
		}
			

		if (apple_pos2.x + apple_sprite2.getTexture()->getSize().x >= size.x ||
			apple_pos2.y + apple_sprite2.getTexture()->getSize().y >= size.y ||
			apple_pos2.x - apple_sprite2.getTexture()->getSize().x <= 0 ||
			apple_pos2.y - apple_sprite2.getTexture()->getSize().y <= 0) {
			apple_sprite2.setPosition(
			rand() % (size.x - size.x/10) + size.x/10,
			rand() % (size.y - size.y/10) + size.y/10);
			apple_pos2 = apple_sprite2.getPosition();
		}
			


		if (time_left == 0) {
			sleep(sf::seconds(2.0));
			if (stage == 1) {
				if (apples < 30)
					lost = 1;
				else {
					stage++;
					text.setString("stage 2");
					text.setPosition(400, 400);
					window.clear(sf::Color::Black);
					window.draw(text);
					window.display();
					sleep(sf::seconds(3.0));
					time_left = 60;
				}
			}
			
			else if (stage == 2) {
				if (apples < 70)
					lost = 1;
				else {
					stage++;
					text.setString("stage 3");
					text.setPosition(400, 400);
					window.clear(sf::Color::Black);
					window.draw(text);
					window.display();
					sleep(sf::seconds(3.0));
					time_left = 60;
				}
			}

			else if (stage == 3) {
				if (apples < 120)
					lost = 1;
				else {
					strcpy(string, "you win");
					text.setString(string);
					window.clear(sf::Color::Black);
					window.draw(text);
					window.display();
					sleep(sf::seconds(5.0));
					window.close();
				}
			}
		}
		


		if (!lost) {
		sprintf(string, "score: %d     time left: %d", apples, time_left);
		text.setString(string);

		sprite.move(x, y);
		window.clear(sf::Color::Black);
		window.draw(text);
		window.draw(sprite);
		window.draw(apple_sprite2);
		window.draw(apple_sprite1);
		window.draw(apple_sprite0);
		window.setTitle(title);
		window.display();
		} else {
			strcpy(string, "you lose");
			text.setString(string);
			window.clear(sf::Color::Black);
			window.draw(text);
			window.display();
			sleep(sf::seconds(5.0));
			window.close();
		}
	}
}
