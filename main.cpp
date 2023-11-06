/* 
    ***********************
    CODE STYLE DESCRIPTION
    ***********************
*/ 

// - Pascal Case For Class
// - Pascal Case For Functions
// - Camel Case For Var
// - Add _type after normal var (facultatif for not important type)
// - Add type_ before class member var (facultatif for not important type)
// - Don't need specifiy _ or type with with args var
// - Multiple Line commentary for Functions or Methods decription, like : ( /* - Commentary - */ )
// - One line commentary for one line Operation, next to the line, like : ( // $Commentary )
// - To Think commentary : TOTHINK - $
// - To Do commentary : TODO - $

/*
    CODE STYLE DESCRIPTION
*/

#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");

    //Création d'un cercle de radius 100
    sf::CircleShape oCircle(100.f);
    //A la position 0, 0
    oCircle.setPosition(0.f, 0.f);
    //Et de couleur verte
    oCircle.setFillColor(sf::Color::Green);


    //Création d'un rectangle de taille 50, 50
    sf::RectangleShape oRectangle(sf::Vector2f(50.f, 50.f));
    //A la position 100, 100
    oCircle.setPosition(100.f, 100.f);
    //Et de couleur rouge
    oRectangle.setFillColor(sf::Color::Red);

    //GameLoop
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }

        //UPDATE

        //DRAW
        oWindow.clear();

        oWindow.draw(oCircle);
        oWindow.draw(oRectangle);

        oWindow.display();
    }

    return 0;
}
