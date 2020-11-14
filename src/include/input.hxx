#pragma once

class Input
{
private:
    bool quit;
public:
    const bool didQuit();
    void poll();
};