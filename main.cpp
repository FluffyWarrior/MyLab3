#include <SFML/Graphics.hpp>
#include <ctime>



class Circle
{
    float m_r, m_x, m_y, m_v;
    sf::CircleShape m_shapeC;

public:
    Circle(float x, float y, float r, float v)
    {
        m_x = x;
        m_y = y;
        m_r = r;
        m_v = v;

        m_shapeC.setOrigin(m_r, m_r);
        m_shapeC.setRadius(m_r);
        m_shapeC.setPosition(m_x, m_y);

        int color_r = rand() % 256;
        int color_g = rand() % 256;
        int color_b = rand() % 256;

        
        m_shapeC.setFillColor(sf::Color::Color(255, 0, 0, 255));
    }
    sf::CircleShape GetC()
    {
        return m_shapeC;
    }

    void MoveC(float dt, int rx, int ry, int r)
    {
        m_y += m_v * dt;

        if (m_y <= m_r)
        {
            float tmp;
            tmp = m_v;
            m_v = 0;
            srand(time(0));

            int color_r = rand() % 256;
            int color_g = rand() % 256;
            int color_b = rand() % 256;

            m_shapeC.setFillColor(sf::Color::Color(color_r, color_g, color_b, 255));
            m_v = tmp;

        }
        else
            m_shapeC.setPosition(m_x, m_y);
    }
};
class Other
{
    int m_p;
    float m_x, m_y, m_v, m_r;
    sf::CircleShape m_shapeO;

public:
    Other(float x, float y, float r, int p, float v)
    {
        m_x = x;
        m_y = y;
        m_r = r;
        m_v = v;
        m_p = p;

        m_shapeO.setOrigin(m_r, m_r);
        m_shapeO.setRadius(m_r);
        m_shapeO.setPointCount(m_p);
        m_shapeO.setPosition(m_x, m_y);

        int color_r = rand() % 256;
        int color_g = rand() % 256;
        int color_b = rand() % 256;

        
        m_shapeO.setFillColor(sf::Color::Color(0, 255, 0, 255));
    }
    sf::CircleShape GetO()
    {
        return m_shapeO;
    }

    void MoveO(float dt)
    {
        m_y += m_v * dt;

        if (m_y <= m_r)
        {

            m_v = 0;

            srand(time(0));

            int color_r = rand() % 256;
            int color_g = rand() % 256;
            int color_b = rand() % 256;

            m_shapeO.setFillColor(sf::Color::Color(color_r, color_g, color_b, 255));
        }
        else
            m_shapeO.setPosition(m_x, m_y);
    }
};

void timer(int ms) {

    int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;

    clock_t end_time = clock() + ms * CLOCKS_PER_MSEC;

    while (clock() < end_time) {}
}

int main()
{
    int rx = 1000;
    int ry = 800;
    int r = 50;
    sf::RenderWindow window(sf::VideoMode(rx, ry), "It's alive! Alive!");

    srand(time(0));

    float a = (rand() % 200 + 50) * -1;

    float b = (rand() % 200 + 50) * -1;

    float d = (rand() % 200 + 50) * -1;

    Circle c(810, 750, r, a);

    Other c1(500, 760, 50, 5, b);

    Other c2(110, 720, 80, 6, d);

    sf::Clock clock;
    int i = 0;
    
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        float dt = clock.getElapsedTime().asSeconds();
        clock.restart();
        window.draw(c.GetC());
        window.draw(c1.GetO());
        window.draw(c2.GetO());
        window.display();
        if (i == 0)
        {
            timer(5000);
        }
        if (i > 1)
        {
            c.MoveC(dt, rx, ry, r);
            c1.MoveO(dt);
            c2.MoveO(dt);
        }
        i++;

    }
    return 0;
}