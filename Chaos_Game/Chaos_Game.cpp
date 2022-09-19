#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game

	RenderWindow window(vm, "Sierpinski Triangle!!", Style::Default);
	RectangleShape rect(Vector2f{ 3,3 });
	RectangleShape dot(Vector2f(1, 1));
	dot.setSize(Vector2f(1, 1));

	vector<Vector2f> vertices;   ///push_back stuff into us!
	vector<Vector2f> points;
	int midPoint_x;
	int midPoint_y;
	int randPoint;
	Vector2f clicked;

	// Draw text
	Text titleText;
	Text firstInstruction;
	Text secondInstruction;
	// Choose font
	Font font;
	font.loadFromFile("fonts/specialagent.ttf");
	// Set font to text
	titleText.setFont(font);
	firstInstruction.setFont(font);
	secondInstruction.setFont(font);
	// Assign message
	titleText.setString("Chaos Game!");
	firstInstruction.setString("Click three points in the shape of a triangle to start!");
	secondInstruction.setString("Now click anywhere inside the three points!");
	// Increase size of characters
	titleText.setCharacterSize(75);
	firstInstruction.setCharacterSize(50);
	secondInstruction.setCharacterSize(50);
	// Assign a color
	titleText.setFillColor(Color::White);
	firstInstruction.setFillColor(Color::White);
	secondInstruction.setFillColor(Color::White);

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
	FloatRect textRect3 = secondInstruction.getLocalBounds();
	secondInstruction.setOrigin(textRect2.left +
		textRect3.width / 2.0f,
		textRect3.top +
		textRect3.height / 2.0f);
	titleText.setPosition(1920 / 2.0f, 1080 / 20.0f);
	firstInstruction.setPosition(1920 / 2.0f, 1080 / 10.0f);
	secondInstruction.setPosition(1920 / 2.0f, 1080 / 10.0f);

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
					// Updates vertices vector with user input's coordinates
					if (vertices.size() < 3)
					{
						vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
						cout << "the left button was pressed" << std::endl;
						cout << "mouse x: " << event.mouseButton.x << std::endl;
						cout << "mouse y: " << event.mouseButton.y << std::endl;

					}

					else if (points.size() == 0)
					{
						points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
						cout << "the left button was pressed" << std::endl;
						cout << "mouse x: " << event.mouseButton.x << std::endl;
						cout << "mouse y: " << event.mouseButton.y << std::endl;
					}

				}
			}


		}

		randPoint = (rand() % 3);


		if (points.size() > 0)
		{
			int length = points.size();

			midPoint_x = (points[points.size() - 1].x + vertices[randPoint].x) / 2;
			midPoint_y = (points[points.size() - 1].y + vertices[randPoint].y) / 2;
			points.push_back(Vector2f(midPoint_x, midPoint_y));
			cout << "points size: " << length << endl;
			cout << "ranPoint: " << randPoint << endl;
			cout << "points[points.size() - 1].x: " << points[length - 1].x << endl;
			cout << "points[points.size() - 1].y: " << points[length - 1].y << endl;
			cout << "vertices[randPoint].x: " << vertices.at(randPoint).x << endl;
			cout << "vertices[randPoint].y: " << vertices.at(randPoint).y << endl;
			cout << "midpoint_x: " << midPoint_x << endl;
			cout << "midpoint_y: " << midPoint_y << endl;
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
		if (vertices.size() < 3)
		{
			window.draw(firstInstruction);
		}

		if (vertices.size() == 3 && vertices.size() < 4)
		{
			window.draw(secondInstruction);
		}

		// Draw our game scene here
		for (int i = 0; i < vertices.size(); i++)
		{
			rect.setPosition(vertices.at(i).x, vertices.at(i).y);
			window.draw(rect);
		}

		if (points.size() > 1)
		{
			window.clear();
			window.draw(titleText);
		}

		// Draw our game scene here
		for (int i = 1; i < points.size(); i++)
		{
			dot.setPosition(points.at(i).x, points.at(i).y);
			window.draw(dot);
		}

		window.display();

	}

	return 0;
}