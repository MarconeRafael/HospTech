#include "menuadmin.h"
#include "inventario.h"
#include <iostream>
#include <string>
#include <limits>
void MenuAdmin::exibirMenu() {
   
    inventario.carregarInventario();
    int opcao = 0;

    
    do {
       std::cout << "================ HOSPTECH - Menu Admin ================\n";
        std::cout << "1. Gerenciamento de Pacientes\n";
        std::cout << "2. Gerenciamento Financeiro\n";
        std::cout << "3. Controle de Inventário Médico\n";
        std::cout << "4. Controle de Agendamentos\n";
        std::cout << "5. Controle de Leitos\n";
        std::cout << "6. Gestão de Prescrições Eletrônicas (PEP)\n";
        std::cout << "7. Sistema de Autenticação\n";
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
                
                break;
            case 2:
                
                break;
            case 3:
                gerenciarInventario();
                break;
            case 4:
        
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
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
                break;
            case 3:
                std::cout << "Nome do item: ";
                std::cin >> nome;
                inventario.buscarItem(nome);
                break;
            case 4:
                inventario.listarItens();
                break;
            case 5:
                std::cout << "Voltando ao Menu Admin...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 5);
}
