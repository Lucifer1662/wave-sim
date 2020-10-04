#include <SFML/Graphics.hpp>



const int WIDTH = 800;
const int HEIGHT = 400;
const float c = 1;

const float step = 5;
const int numVertex = WIDTH / 5;


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 400), "SFML works!");
	
	float dx[numVertex];
	float dt[numVertex];
	float old_dt[numVertex];

	sf::Vertex line[numVertex];
	float x = 0;
	for (int i = 0; i < numVertex; i++,x+=step) {
		line[i] = { { x, HEIGHT / 2.0f } };
		old_dt[i] = sin(3.141f* ((float)i)/numVertex * 2) * HEIGHT/4.0f;
	}

	dx[0] = dx[numVertex - 1] = 0;
	
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		

		
		for (int i = 1; i < numVertex - 1; i++)
			dx[i] = line[i+1].position.y - line[i-1].position.y;

		
	
		for (int i = 2; i < numVertex-2; i++) {
			float dxdx = dx[i + 1] - dx[i - 1];
			float dtdt = c * c * dxdx;
			//dtdt = dt - old_dt;
			dt[i] = dtdt + old_dt[i];
			old_dt[i] = dt[i];
			line[i].position.y += dt[i] * 0.001f;
		}

	
		


		window.clear();
		window.draw(line, numVertex, sf::PrimitiveType::LinesStrip);
		window.display();
	}

	return 0;
}