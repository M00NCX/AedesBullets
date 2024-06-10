#ifndef MOUSE_H
#define MOUSE_H

class Mouse {
public:
    int x, y;
    bool leftButtonDown;

    Mouse();
    void updatePosition(int newX, int newY);
    void handleButton(int button, int state);
    void setCursor(bool hover);
};

#endif // MOUSE_H
