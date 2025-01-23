#include <iostream>
#include "usuario.h"
#include "agendamentos.h"
#include "menuadmin.h"
#include "menuprincipal.h"
#include <limits>
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
    Agenda agenda;
    agenda.carregarAgendamentos();
    int opcao = 0;

    do {
        std::cout << "================ HOSPTECH - Menu Recepcionista ================\n";
        std::cout << "1. Controle de Agendamentos\n";
        std::cout << "0. Sair\n";
        std::cout << "========================================================\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        if (std::cin.fail()) { 
                std::cin.clear();// Limpar o estado de erro caso seja digitado um algarismo
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Entrada inválida. Digite um numero!\n"; 
                continue; 
        }
        switch (opcao) {
            case 1:
                agenda.gerenciarAgendamentos(agenda);
                break;
            case 0: 
                    std::cout << "Saindo...\n"; 
                    break;
                default:
                    std::cout << "Opção inválida. Tente novamente.\n";
        } 
    }while (opcao != 0);
    
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

