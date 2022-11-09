/***************************************************************************************************************
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/ * Programmer: Yusuf Halim                                                                                  / *
/ * Date: 10/24/2022                                                                                         / *
/ * Name: main.cpp                                                                                           / *
/ * Description: Contains code for the basics of Bejeweled game with modified features: Timer, Score count,  / *
                  and a sound effect for when gems match.
/ * Extra features added: More sound effect for when gems are clicked, when gems don't match, and a song at
                          the start of the game, A welcome screen was also added                             / *
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
***************************************************************************************************************/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <SFML/Audio.hpp>
#include <string>

using namespace sf;
using namespace std;



int ts = 54; //tile size

// constructing a 2d vector for the games graphics
Vector2i offset(48, 24);

// The piece class that will hold the gems position, gems type and when they match.
class Piece {

private:
    int x, y, col, row, kind, match, alpha;

public:

    // default constructor for class Piece
    Piece() {
        match = 0;
        alpha = 255;
    }

    // Getter for the columns, returns col's value
    int getCol() const {
        return col;
    }

    // Setter for columns, sets the value of col
    void setCol(int cols) {
        Piece::col = cols;
    }

    // Getter for rows, returns the value of row
    int getRow() const {
        return row;
    }

    // Setter for rows, sets the value for row
    void setRow(int rows) {
        Piece::row = rows;
    }

    // Getter for X, returns x's value
    int getX() const {
        return x;
    }

    // Setter for X, sets the value for x
    void setX(int x) {
        Piece::x = x;
    }

    // Getter for y, returns the value of y
    int getY() const {
        return y;
    }

    // Setter for y, sets the value for y
    void setY(int y) {
        Piece::y = y;
    }

    // Getter for kind, returns the value of kind
    int getKind() const {
        return kind;
    }

    // Setter for kind, sets the value of kind
    void setKind(int kind) {
        Piece::kind = kind;
    }

    // Getter for match, returns the value of match
    int getMatch() const {
        return match;
    }

    // Setter for match, sets the value for match
    void setMatch(int match) {
        Piece::match = match;
    }

    // getter for alpha, returns alpha's value
    int getAlpha() const {
        return alpha;
    }

    // Setter for alpha, sets a value for alpha
    void setAlpha(int alpha) {
        Piece::alpha = alpha;
    }

};

Piece grid[10][10];

// Description: swap two pieces in the game grid
// Input: p1 and p2 are Piece objects pass-by-value to swap
// Output: updated grid of pieces

void swap(Piece p1, Piece p2) {
    int tmp = p1.getCol();
    p1.setCol(p2.getCol());
    p2.setCol(tmp);

    tmp = p1.getRow();
    p1.setRow(p2.getRow());
    p2.setRow(tmp);

    grid[p1.getRow()][p1.getCol()] = p1;
    grid[p2.getRow()][p2.getCol()] = p2;
}


int main() {
    // gerating random numbers with respect to time
    srand(time(0));

    // constructing the pop-up window that will hold the game graphics and animation
    RenderWindow app(VideoMode(740, 480), "Match-3 Game!");
    app.setFramerateLimit(60); // setting the window frame limit

    // Importing the font that will be used in the game text
    Font font;
    if (!font.loadFromFile("fonts/font.ttf"))
    {
        cout << "couldn't load font.ogg font file" << endl;
        return EXIT_FAILURE;
    }

    // Importing all sound effects that will be used in the game
    SoundBuffer match, clicker, error, music;
    if (!match.loadFromFile("sound/match.ogg")){
        cout << "couldn't load match.ogg audio file" << endl;
        return EXIT_FAILURE;
    }
    if (!clicker.loadFromFile("sound/click.ogg")){
        cout << "couldn't load click.ogg audio file" << endl;
        return EXIT_FAILURE;
    }
    if (!error.loadFromFile("sound/error.ogg")){
        cout << "couldn't load error.ogg audio file" << endl;
        return EXIT_FAILURE;
    }
    if (!music.loadFromFile("sound/music.ogg")){
        cout << "couldn't load music.ogg audio file" << endl;
        return EXIT_FAILURE;
    }

    // Initializing the sound variables that will later be used to play the sound effects
    Sound matchs, clicks, eror, mus;
    matchs.setBuffer(match);
    clicks.setBuffer(clicker);
    eror.setBuffer(error);
    mus.setBuffer(music);

    //loading the game graphics into the window
    Texture t1, t2;
    if (!t1.loadFromFile("images/background.png")) {
        cout << "couldn't load background image file" << endl;
        return EXIT_FAILURE;
    }
    t1.loadFromFile("images/background.png");

    if (!t2.loadFromFile("images/gems.png")) {
        cout << "couldn't load gems image file" << endl;
        return EXIT_FAILURE;
    }
    t2.loadFromFile("images/gems.png");

    // Assigning each graphic to it's position in the game
    Sprite background(t1), gems(t2);

    // A for loop to draw the grid/boxes that will be holding the gems
    for (int i = 1; i <= 8; i++){
        for (int j = 1; j <= 8; j++) {
            grid[i][j].setKind(rand() % 3);
            grid[i][j].setCol(j); // number of columns
            grid[i][j].setRow(i); // number of rows
            grid[i][j].setX(j * ts); // columns * tile size to get the x position of each box
            grid[i][j].setY(i * ts); // rows * tile size to get the y position of each box
        }
    }

    int x0, y0, x, y; // x,y positions for the gems in the grid
    int click = 0; // accumulator for how many times the mouse was clicked
    Vector2i pos; // creating another 2d vector that will hold the position of the vector
    bool isSwap = false, isMoving = false; // setting the gems and moving of gems to false

    // a while loop for when the app is open and running smoothly

    // Playing the welcome short music and putting it on a long loop
    mus.setVolume(10);
    mus.setLoop(100);
    mus.play();

    // Initializing the text variables tht will hold the message to the users
    Text time, intro, end, scores;

    // select the font
    time.setFont(font);
    intro.setFont(font);
    end.setFont(font);
    scores.setFont(font);

    // set the character size
    time.setCharacterSize(18);
    intro.setCharacterSize(40);// in pixels, not points!
    end.setCharacterSize(30);// in pixels, not points!
    scores.setCharacterSize(20);

    // set the color and positions of the text
    time.setFillColor(sf::Color::Red);
    time.setPosition(600, 440);
    intro.setFillColor(sf::Color::Green);
    intro.setPosition(30, 200);
    end.setFillColor(sf::Color::Red);
    end.setPosition(30, 200);
    scores.setFillColor(sf::Color::Red);
    scores.setPosition(490, 410);

    // set the style of some texts
    intro.setStyle(sf::Text::Bold);
    end.setStyle(sf::Text::Bold);
    scores.setStyle(sf::Text::Bold);

    // setting the strings to diplay
    intro.setString("\tWelcome to Bejeweled! \n\nPress S to start the game!");
    end.setString("\t\t\tGame Over!\n\n\nPress R to restart the game!");

    float points = 0; // the score variable
    bool start = false; // a bool to check if S was pressed and game was started
    bool restart = false; // a bool that checks if the app is ready to restart
    bool first = false; // bool that checks if user made the first move
    float timer = 100; // the timer variable

    // The while loop that keeps the game running until it's closed
    while (app.isOpen()) {

        // If statment the decrement the timer when the user starts the game
        if (start){
            timer -= 0.02;

        }

        // Intializing the event that will listen to key press
        Event e;

        // The while loop that checks if an event occurred when game was running
        while (app.pollEvent(e)) {

            // check if pop-up window was closed and end the while loop
            if (e.type == Event::Closed) {
                app.close();
            }

            // If the game wasn't started listen to Key code S
            // If S was pressed set start to true and stop the intro music
            if (!start){
                if (e.type == Event::KeyPressed) {
                    if (e.key.code == Keyboard::S) {
                        start = true;
                        mus.stop();
                    }
                }
            }

            // If timer ends listen to key code R to restart the game
            // If R was pressed: Load a new game, reset timer, reset points, and reset restart and first to false
            if (timer < 0){
                if (e.type == Event::KeyPressed) {
                    if (e.key.code == Keyboard::R) {
                        restart = false;
                        timer = 100;
                        points = 0;
                        first = false;
                        for (int i = 1; i <= 8; i++){
                            for (int j = 1; j <= 8; j++) {
                                grid[i][j].setKind(rand() % 3);
                                grid[i][j].setCol(j); // number of columns
                                grid[i][j].setRow(i); // number of rows
                                grid[i][j].setX(j * ts); // columns * tile size to get the x position of each box
                                grid[i][j].setY(i * ts); // rows * tile size to get the y position of each box
                            }
                        }

                    }
                }
            }

            // if timer is > 0 listen to mouse clicks
            if (timer > 0) {
                // check if the mouse button was pressed
                if (e.type == Event::MouseButtonPressed) {
                    // check if left mouse button was pressed
                    if (e.key.code == Mouse::Left) {
                        if (!isSwap && !isMoving) {
                            // increment clicks and play clicks sound effect
                            click++;
                            clicks.play();
                        }
                        // get the mouse cursor position
                        pos = Mouse::getPosition(app) - offset;
                    }
                }
            }
        }

        // If timer is > 0 allow user to play
        if (timer > 0){
            // mouse click
            // get the position of the first click
            if (click == 1) {
                x0 = pos.x / ts + 1;
                y0 = pos.y / ts + 1;
            }
            // get the position of the second click
            if (click == 2) {
                x = pos.x / ts + 1;
                y = pos.y / ts + 1;
                // if position of first click + second click == 1
                if (abs(x - x0) + abs(y - y0) == 1) {
                    // swap gems accordingly, set isSwap to true, and reset clicks to 0
                    swap(grid[y0][x0], grid[y][x]);
                    isSwap = 1;
                    click = 0;
                    first = true;
                }
                else {
                    click = 1;
                }
            }

            //Match finding
            // A for loop to check if swapped gems match
            for (int i = 1; i <= 8; i++){
                for (int j = 1; j <= 8; j++) {
                    if (grid[i][j].getKind() == grid[i + 1][j].getKind()) {
                        if (grid[i][j].getKind() == grid[i - 1][j].getKind()) {
                            for (int n = -1; n <= 1; n++) {
                                grid[i + n][j].setMatch(grid[i + n][j].getMatch() + 1);
                            }
                        }
                    }

                    if (grid[i][j].getKind() == grid[i][j + 1].getKind()) {
                        if (grid[i][j].getKind() == grid[i][j - 1].getKind()) {
                            for (int n = -1; n <= 1; n++) {
                                grid[i][j + n].setMatch(grid[i][j + n].getMatch() + 1);
                            }

                        }
                    }
                }
            }
            //Moving animation
            // implementing gems swapping animation when mouse is clicked and then set isMoving to true
            // if the game was started allow gems motion and set the string for both scores and time to show
            if (start) {

                scores.setString("Score : " + to_string((int)points));
                time.setString("Timer: " + to_string((int)timer) + "s");
                isMoving = false;
                for (int i = 1; i <= 8; i++){
                    for (int j = 1; j <= 8; j++) {
                        Piece &p = grid[i][j];
                        int dx, dy;
                        for (int n = 0; n < 4; n++)   // 4 - speed
                        {
                            dx = p.getX() - p.getCol() * ts;
                            dy = p.getY() - p.getRow() * ts;
                            if (dx) {
                                p.setX(p.getX() - dx / abs(dx));
                            }
                            if (dy) {
                                p.setY(p.getY() - dy / abs(dy));
                            }
                        }
                        if (dx || dy) {
                            isMoving = 1;

                        }
                    }
                }
            }

            //Deleting animation
            // motion for deleting the gems that was matched
            if (!isMoving) {
                for (int i = 1; i <= 8; i++){
                    for (int j = 1; j <= 8; j++) {
                        if (grid[i][j].getMatch()) {
                            if (grid[i][j].getAlpha() > 10) {
                                grid[i][j].setAlpha(grid[i][j].getAlpha() - 10);
                                isMoving = true;
                            }
                        }
                    }
                }

            }

            //Get score
            // implementing the score count based on the gem matches after swapping
            int score = 0;
            for (int i = 1; i <= 8; i++){
                for (int j = 1; j <= 8; j++){
                    score += grid[i][j].getMatch();
                    // if get match is > 0 and the first move was made increment the points variable
                    if (grid[i][j].getMatch() >0 && first)
                        points += 0.009;

                }
            }



            //Second swap if no match and play the error sound effect
            if (isSwap && !isMoving) {
                if (!score) {
                    swap(grid[y0][x0], grid[y][x]);
                    eror.play();
                }
                isSwap = 0;
            }

            // update grid to generate more gems when the swapping is done and gems matched, and play the matching sound effect
            if (!isMoving) {
                for (int i = 8; i > 0; i--){
                    for (int j = 1; j <= 8; j++) {
                        if (grid[i][j].getMatch()) {
                            for (int n = i; n > 0; n--)
                                if (!grid[n][j].getMatch()) {
                                    swap(grid[n][j], grid[i][j]);
                                    matchs.play();
                                    break;
                                }
                        }
                    }
                }

                for (int j = 1; j <= 8; j++){
                    for (int i = 8, n = 0; i > 0; i--) {
                        if (grid[i][j].getMatch()) {
                            grid[i][j].setKind(rand() % 7);
                            grid[i][j].setY(-ts * n++);
                            grid[i][j].setMatch(0);
                            grid[i][j].setAlpha(255);
                        }
                    }
                }
            }


            //////draw///////
            app.draw(background);

            // loading all the graphics and grids into the game pop-up window and setting gems position
            for (int i = 1; i <= 8; i++){
                for (int j = 1; j <= 8; j++) {
                    Piece p = grid[i][j];
                    gems.setTextureRect(IntRect(p.getKind() * 49, 0, 49, 49));
                    gems.setColor(Color(255, 255, 255, p.getAlpha()));
                    gems.setPosition(p.getX(), p.getY());
                    gems.move(offset.x - ts, offset.y - ts);
                    app.draw(gems);
                }
            }

            // show the time text
            app.draw(time);

            // show the score text
            app.draw(scores);

            // show the intro text only when the game is not started
            if (!start) {
                app.draw(intro);
            }


        }

        // if time is < than 0 set restart to true and show the ending text
        else{
            restart = true;
            app.draw(end);
        }

        // displaying all the implemented graphics and animation
        app.display();
    }
    return 0;
}
