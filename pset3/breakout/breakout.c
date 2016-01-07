//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// height and width of the paddle
#define PADDLE_HEIGHT 10
#define PADDLE_WIDTH 70

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    updateScoreboard(window, label, points);

    // Initial parameters
    double xvelocity = drand48()*0.09;
    double yvelocity = 0.09;
    waitForClick();
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // Moves the paddle with the mouse
        GEvent event = getNextEvent(MOUSE_EVENT);
        
        if (event != NULL)
        {
            if (getEventType(event) == MOUSE_MOVED)
            {
                double x = getX(event) - getWidth(paddle) / 2;
                setLocation(paddle, x, HEIGHT - (HEIGHT / 7));
            }
        } 
        // Moves the ball and bounces it of the edges       
        move(ball, xvelocity, yvelocity);
       
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            xvelocity = -xvelocity;
        }    
        if (getX(ball) <= 0)
        {
            xvelocity = -xvelocity;
        }
        if (getY(ball) <= 0)
        {
            yvelocity = -yvelocity;
        }
        
        //Detects if player losses a life
        if (getY(ball) + getHeight(ball) >= getHeight(window))
        {
            lives = lives - 1;
            waitForClick();
            removeGWindow(window, ball);
            ball = initBall(window);
        }
       
        // Detects collision
         
        GObject object = detectCollision(window, ball);
        
        if (object != NULL)
        {
            if (strcmp(getType(object), "GRect") == 0)
            {
                yvelocity = -yvelocity;
                if (object != paddle)
                {
                    removeGWindow(window, object);
                    bricks = bricks - 1;
                    points = points + 1;
                    updateScoreboard(window, label, points);
                }
            }
        }
    }
    
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    int BricksWidth = (WIDTH / COLS) - 6;
    int BricksHeight = 10;
    for(int i = 0; i <= COLS - 1; i++)
    {
        for(int j = 0; j <= ROWS - 1 ; j++)
        {
            GRect bricks = newGRect(i * (WIDTH / COLS) + 2, j * (BricksHeight + 6) + 50 , BricksWidth, BricksHeight);
            if (j == 0)
            {
                setColor(bricks, "GREEN");
            }
            if (j == 1)
            {
                setColor(bricks, "BLUE");
            }
            if (j == 2)
            {
                setColor(bricks, "RED");
            }
            if (j == 3)
            {
                setColor(bricks, "YELLOW");
            }
            if (j == 4)
            {
                setColor(bricks, "CYAN");
            }
            setFilled(bricks, true);
            add(window, bricks);
        }
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval((WIDTH / 2) - RADIUS, (HEIGHT / 2) + RADIUS, RADIUS * 2, RADIUS * 2);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect((WIDTH / 2) - (PADDLE_WIDTH / 2), HEIGHT - (HEIGHT / 7), PADDLE_WIDTH, PADDLE_HEIGHT);
    setColor(paddle, "BLACK");
    setFilled(paddle, true);
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    add(window,label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
