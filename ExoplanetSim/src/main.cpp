// main.cpp

#include "Application.h"

int main()
{
    Application app;

    if (!app.initialize())
    {
        return -1;
    }

    app.run();

    return 0;
}
