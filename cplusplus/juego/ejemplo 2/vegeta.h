#ifndef VEGETA_H
#define VEGETA_H
#include "personaje.h"
#include "string"
class Vegeta: public Personaje{

    private:

    public:

        Vegeta();
       
        virtual const bool puntosPorTurno() override;

        virtual int atacar() override;

        virtual bool defender(int) override;
     
        virtual ~Vegeta() override;
};

#endif /* ifndef VEGETA_H
#define VEGETA_H

class Vegeta{

    private:

}; */
