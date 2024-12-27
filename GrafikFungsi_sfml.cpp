#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Grafik Fungsi y = ax^2 + bx + c");

    float a, b, c, xMin, xMax, yMin, yMax, dot;

    std::cout << "Masukkan koefisien a, b, dan c: ";
    std::cin >> a >> b >> c;

    xMin = -10.0f;
    xMax = 10.0f;
    yMin = -100.0f;
    yMax = 100.0f;
    dot = 0.1f;

    VertexArray xAxis(Lines, 2);
    xAxis[0].position = Vector2f(0, 300);
    xAxis[1].position = Vector2f(800, 300);
    xAxis[0].color = Color::Red;
    xAxis[1].color = Color::Red;

    VertexArray yAxis(Lines, 2);
    yAxis[0].position = Vector2f(400, 0);
    yAxis[1].position = Vector2f(400, 600);
    yAxis[0].color = Color::Blue;
    yAxis[1].color = Color::Blue;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(xAxis);
        window.draw(yAxis);

        VertexArray graph(LineStrip);

        for (float x = xMin; x <= xMax; x += dot) {
            float y = a * x * x + b * x + c;
            float xPixel = 400 + x * 40;
            float yPixel = 300 - y * 4;
            graph.append(Vertex(Vector2f(xPixel, yPixel), Color::Green));
        }

        window.draw(graph);
        window.display();
    }

    return 0;
}
