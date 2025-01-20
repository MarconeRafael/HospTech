#include <iostream>
#include "usuario.h"
#include "menuadmin.h"
void exibirMenuAdmin() {
    MenuAdmin menuadmin; //redireciona para o menu admin
    menuadmin.exibirMenu();
}

void exibirMenuMedico() {
    std::cout << "================ HOSPTECH - Menu Médico ================\n";
    std::cout << "1. Gerenciamento de Pacientes\n";
    std::cout << "6. Gestão de Prescrições Eletrônicas (PEP)\n";
    std::cout << "0. Sair\n";
    std::cout << "========================================================\n";
    std::cout << "Escolha uma opção: ";
}

void exibirMenuEnfermeiro() {
    std::cout << "================ HOSPTECH - Menu Enfermeiro ================\n";
    std::cout << "1. Gerenciamento de Pacientes\n";
    std::cout << "0. Sair\n";
    std::cout << "========================================================\n";
    std::cout << "Escolha uma opção: ";
}

void exibirMenuRecepcionista() {
    std::cout << "================ HOSPTECH - Menu Recepcionista ================\n";
    std::cout << "4. Controle de Agendamentos\n";
    std::cout << "0. Sair\n";
    std::cout << "========================================================\n";
    std::cout << "Escolha uma opção: ";
}

void exibirMenuFarmaceutico() {
    std::cout << "================ HOSPTECH - Menu Farmacêutico ================\n";
    std::cout << "6. Gestão de Prescrições Eletrônicas (PEP)\n";
    std::cout << "0. Sair\n";
    std::cout << "========================================================\n";
    std::cout << "Escolha uma opção: ";
}

void exibirMenuPaciente() {
    std::cout << "================ HOSPTECH - Menu Paciente ================\n";
    std::cout << "1. Gerenciamento de Pacientes\n";
    std::cout << "0. Sair\n";
    std::cout << "========================================================\n";
    std::cout << "Escolha uma opção: ";
}

void exibirMenuAuditor() {
    std::cout << "================ HOSPTECH - Menu Auditor ================\n";
    std::cout << "1. Gerenciamento de Pacientes\n";
    std::cout << "0. Sair\n";
    std::cout << "========================================================\n";
    std::cout << "Escolha uma opção: ";
}

void exibirMenuPrincipal(const Usuario& usuario) {
    std::cout << "================ HOSPTECH - Menu Principal ================\n";
    std::cout << "7. Sistema de Autenticação\n";
    std::cout << "0. Sair\n";
    std::cout << "===========================================================\n";

    switch (usuario.get_nivel_acesso()) {
        case NivelAcesso::ADMIN:
            exibirMenuAdmin();
            break;
        case NivelAcesso::MEDICO:
            exibirMenuMedico();
            break;
        case NivelAcesso::ENFERMEIRO:
            exibirMenuEnfermeiro();
            break;
        case NivelAcesso::RECEPCIONISTA:
            exibirMenuRecepcionista();
            break;
        case NivelAcesso::FARMACEUTICO:
            exibirMenuFarmaceutico();
            break;
        case NivelAcesso::PACIENTE:
            exibirMenuPaciente();
            break;
        case NivelAcesso::AUDITOR:
            exibirMenuAuditor();
            break;
        default:
            std::cout << "Erro: Nível de acesso desconhecido!\n";
            break;
    }
    std::cout << "Escolha uma opção: ";
}

