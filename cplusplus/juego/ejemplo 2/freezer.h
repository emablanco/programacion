#ifndef FREEZER_H
#define FREEZER_H
#include "personaje.h"
#include "string"
class Freezer: public Personaje{

    private:

    public:

        Freezer();
       
        virtual const bool puntosPorTurno() override; 
       
        virtual int atacar() override;

        virtual bool defender(int) override;
     
        virtual ~Freezer() override;
};

#endif /* ifndef FREEZER_H
#define FREEZER_H

class Freezer{

    private:

}; */
