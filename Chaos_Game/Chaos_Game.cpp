#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game

	RenderWindow window(vm, "Sierpinski Triangle!!", Style::Default);
	RectangleShape rect(Vector2f{ 3,3 });

	vector<Vector2f> vertices;   ///push_back stuff into us!
	vector<Vector2f> points;

	Vector2f clicked;

	// Draw text
	Text titleText;
	Text firstInstruction;
	// Choose font
	Font font;
	font.loadFromFile("fonts/specialagent.ttf");
	// Set font to text
	titleText.setFont(font);
	firstInstruction.setFont(font);
	// Assign message
	titleText.setString("Chaos Game!");
	firstInstruction.setString("Click three points in the shape of a triangle to start!");
	// Increase size of characters
	titleText.setCharacterSize(75);
	firstInstruction.setCharacterSize(50);
	// Assign a color
	titleText.setFillColor(Color::White);
	firstInstruction.setFillColor(Color::White);

	// Position text
	FloatRect textRect1 = titleText.getLocalBounds();
	titleText.setOrigin(textRect1.left +
		textRect1.width / 2.0f,
		textRect1.top +
		textRect1.height / 2.0f);
	FloatRect textRect2 = firstInstruction.getLocalBounds();
	firstInstruction.setOrigin(textRect2.left +
		textRect2.width / 2.0f,
		textRect2.top +
		textRect2.height / 2.0f);
	titleText.setPosition(1920 / 2.0f, 1080 / 20.0f);
	firstInstruction.setPosition(1920 / 2.0f, 1080 / 10.0f);

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					clicked.x = event.mouseButton.x;
					clicked.y = event.mouseButton.y;
				}
			}

		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*
		****************************************
		Update the scene
		****************************************
		*/
		rect.setPosition(clicked.x, clicked.y);
		rect.setFillColor(Color::White);
		/*
		****************************************
		Draw the scene
		****************************************
		*/

		///loop through vectors and draw each coordinate
		// Clear everything from the last run frame
		window.clear();

		// Draw Text
		window.draw(titleText);
		window.draw(firstInstruction);

		// Draw our game scene here
		window.draw(rect);
		window.display();


	}
	return 0;
}