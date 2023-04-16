#ifndef GOKU_H
#define GOKU_H
#include "personaje.h"
#include "string"
class Goku: public Personaje{

    private:

    public:

        Goku();
      
        virtual const bool puntosPorTurno() override;

        virtual int atacar() override;

        virtual bool defender(int) override;
     
        virtual ~Goku() override;
};

#endif /* ifndef GOKU_H
#define GOKU_H

class Goku{

    private:

}; */
