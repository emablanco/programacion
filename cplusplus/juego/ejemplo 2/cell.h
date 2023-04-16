#ifndef CELL_H
#define CELL_H
#include "personaje.h"
#include "string"
class Cell: public Personaje{

    private:

    public:

        Cell();

        virtual const bool puntosPorTurno() override;

        virtual int atacar() override;

        virtual bool defender(int) override;
     
        virtual ~Cell() override;
};

#endif /* ifndef CELL_H
#define CELL_H

class Cell{

    private:

}; */
