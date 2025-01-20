#ifndef MENUADMIN_H
#define MENUADMIN_H

#include "inventario.h"

class MenuAdmin {
public:
    void exibirMenu();
    void gerenciarInventario();

private:
    Inventario inventario;
};

#endif // MENUADMIN_H
