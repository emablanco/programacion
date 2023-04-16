#include "coliciones.h"

bool Coliciones::comprobarSiColiciona(Coliciones &obj)const{
    return this-> buscarGlobal().intersects(obj.buscarGlobal());
}
