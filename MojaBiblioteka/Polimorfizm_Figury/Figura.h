#include "Library_Figura.h"

class Figura_niekulista
{
public:
    virtual void wprowadz()=0;
    virtual float pole()=0;
    virtual float obwod()=0;
    virtual int ile_wierzcholkow()=0;
    virtual int ile_bokow()=0;
};

class Figura_kulista
{
public:
    virtual void wprowadz()=0;
    virtual float obwod()=0;
    virtual float pole()=0;
    virtual float srednica()=0;
};

