#ifndef PORT_H
#define PORT_H

#include <iostream>

class Port {
private:

	static constexpr size_t style_size = 20;

    char* brand {nullptr};
    char style[style_size]; // e.g. tawny, ruby, vintage
    int bottles;

public:
    Port(const char* br = "none", const char* st = "none", int b = 0);
    Port(const Port& p);
    virtual ~Port() { delete [] brand; }

    Port& operator= (const Port& p);
    Port& operator+= (int b) ; // adds b to bottles
    Port& operator-= (int b); // subtracts b from bottles, if possible

    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend std::ostream& operator<< (std::ostream& os, const Port& p);
};

#endif // PORT_H
