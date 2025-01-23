#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include <iostream>
#include "usuario.h"
#include "agendamentos.h"


void exibirMenuAdmin();
void exibirMenuMedico();
void exibirMenuEnfermeiro();
void exibirMenuRecepcionista();
void exibirMenuFarmaceutico();
void exibirMenuPaciente();
void exibirMenuAuditor();
void exibirMenuPrincipal(const Usuario& usuario);
void gerenciarAgendamentos(Agenda& agenda);

#endif // MENU_PRINCIPAL_H
