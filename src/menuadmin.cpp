#include "menuadmin.h"
#include "inventario.h"
#include "agendamentos.h"
#include "auditoria.h"
#include "menupacientes.h"
#include <iostream>
#include <string>
#include <limits>
void MenuAdmin::exibirMenu() {
    Auditoria auditoria;
    auditoria.carregarAtividades();

    inventario.carregarInventario();
    Agenda agenda;
    agenda.carregarAgendamentos();
    int opcao = 0;

    GerenciamentoPacientes gerenciamentoPacientes; // Crie um objeto GerenciamentoPacientes
    std::string nomeArquivo =  "../data/pacientes.csv";
    
    do {
       std::cout << "================ HOSPTECH - Menu Admin ================\n";
        std::cout << "1. Gerenciamento de Pacientes\n";
        std::cout << "2. Gerenciamento Financeiro\n";
        std::cout << "3. Controle de Inventário Médico\n";
        std::cout << "4. Controle de Agendamentos\n";
        std::cout << "5. Controle de Leitos\n";
        std::cout << "6. Auditoria e Logs\n";
        std::cout << "7. Gestão de Prescrições Eletrônicas (PEP)\n";
        std::cout << "8. Sistema de Autenticação\n";
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
                exibirMenuPacientes();
                menuPacientes(gerenciamentoPacientes, nomeArquivo);
                break;
            case 2:
                
                break;
            case 3:
                gerenciarInventario();
                break;
            case 4:
                agenda.gerenciarAgendamentos(agenda);
                break;
            case 5:
                
                break;
            case 6:
                auditoria.listarAtividades();
                break;
            case 7:
                
                break;
            case 8:
                
                break;
            case 0: 
                std::cout << "Saindo...\n"; 
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 0);
   
}

void MenuAdmin::gerenciarInventario() {
    int opcao = 0;
    Auditoria auditoria;
   
    do {
        std::cout << "Gerenciamento de Inventário Médico\n";
        std::cout << "1. Adicionar Item\n";
        std::cout << "2. Atualizar Item\n";
        std::cout << "3. Buscar Item\n";
        std::cout << "4. Listar Itens\n";
        std::cout << "5. Voltar ao Menu Admin\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        if (std::cin.fail()) { 
            std::cin.clear();// Limpar o estado de erro caso seja digitado um algarismo
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Digite um numero!\n"; 
            continue; 
        }
        std::string nome;
        int quantidade;
        std::string descricao;

        switch (opcao) {
            case 1:
                std::cout << "Nome do item: ";
                std::cin >> nome;
                std::cout << "Quantidade: ";
                std::cin >> quantidade;
                if (std::cin.fail()) { 
                    std::cin.clear();// Limpar o estado de erro caso seja digitado um algarismo
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Ignorar a entrada inválida 
                    std::cout << "Entrada inválida. Digite um numero!\n"; 
                    continue; 
                }
                std::cin.ignore(); // Ignorar o caractere de nova linha deixado no buffer
                std::cout << "Descrição: ";
                std::getline(std::cin, descricao);
                inventario.adicionarItem(Item(nome, quantidade, descricao));
                auditoria.registrarAtividade("Adicionado item: " + nome);
                break;
            case 2:
                std::cout << "Nome do item: ";
                std::cin >> nome;
                std::cout << "Nova quantidade: ";
                std::cin >> quantidade;
                if (std::cin.fail()) { 
                    std::cin.clear(); // Limpar o estado de erro caso seja digitado um algarismo
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada inválida. Tente novamente.\n"; 
                    break; 
                }
                inventario.atualizarItem(nome, quantidade);
                auditoria.registrarAtividade("Atualizando item: " + nome);
                break;
            case 3:
                std::cout << "Nome do item: ";
                std::cin >> nome;
                inventario.buscarItem(nome);
                auditoria.registrarAtividade("Buscado item: " + nome);
                break;
            case 4:
                inventario.listarItens();
                auditoria.registrarAtividade("Listados itens do inventário");
                break;
            case 5:
                std::cout << "Voltando ao Menu Admin...\n";
                auditoria.registrarAtividade("Voltando ao Menu Admin");
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 5);
}
