#ifndef PICOLO_H
#define PICOLO_H
#include "personaje.h"
#include "string"
class Picolo: public Personaje{

    private:

    public:

        Picolo();
       
        virtual const bool puntosPorTurno() override;

        virtual int atacar() override;

        virtual bool defender(int) override;
     
        virtual ~Picolo() override;
};

#endif /* ifndef PICOLO_H
#define PICOLO_H

class Picolo{

    private:

}; */
