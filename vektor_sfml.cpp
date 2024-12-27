#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(1920, 1080), "Grafik Fungsi");

    float xMin, xMax, dot;
    xMin = -5.0f;
    xMax = 5.0f;
    dot = 0.1f;

    VertexArray xAxis(Lines, 2);
    xAxis[0].position = Vector2f(0, 540);
    xAxis[1].position = Vector2f(1920, 540);
    xAxis[0].color = Color::Red;
    xAxis[1].color = Color::Red;

    VertexArray yAxis(Lines, 2);
    yAxis[0].position = Vector2f(960, 0);
    yAxis[1].position = Vector2f(960, 1080);
    yAxis[0].color = Color::Blue;
    yAxis[1].color = Color::Blue;

    std::vector<Vector2f> curvePoints; // Vektor untuk menyimpan titik-titik kurva

    int numPoints;
    std::cout << "Masukkan jumlah titik kurva: ";
    std::cin >> numPoints;

    for (int i = 0; i < numPoints; ++i) {
        Vector2f p;
        std::cout << "Masukkan koordinat x untuk titik ke-" << i + 1 << ": ";
        std::cin >> p.x;
        std::cout << "Masukkan koordinat y untuk titik ke-" << i + 1 << ": ";
        std::cin >> p.y;
        curvePoints.push_back(p);
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(xAxis);
        window.draw(yAxis);

        // Membuat ConvexShape untuk mengisi warna di dalam daerah yang diapit oleh garis-garis vektor
        ConvexShape shape;
        shape.setFillColor(Color(0, 255, 0, 50)); // Warna hijau dengan alpha (transparansi) 50
        shape.setOutlineThickness(2);
        shape.setOutlineColor(Color::Green);

        for (const auto& point : curvePoints) {
            float xPixel = 960 + point.x * 80;
            float yPixel = 540 - point.y * 80;
            shape.setPointCount(shape.getPointCount() + 1);
            shape.setPoint(shape.getPointCount() - 1, Vector2f(xPixel, yPixel));
        }

        window.draw(shape);
        window.display();
    }

    return 0;
}
