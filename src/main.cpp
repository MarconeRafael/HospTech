#include <iostream>
#include "pacientes.h"
#include "menupacientes.cpp"  // Incluindo o arquivo com o menu de pacientes
#include "menuprincipal.cpp" // Incluindo o arquivo com o menu principal

int main() {
    GerenciamentoPacientes gerenciamentoPacientes;
    std::string nomeArquivo = "pacientes.csv"; // Nome padrão para persistência
    int opcaoPrincipal;

    do {
        exibirMenuPrincipal(); // Chama a função para exibir o menu principal
        std::cin >> opcaoPrincipal;

        switch (opcaoPrincipal) {
            case 1: // Gerenciamento de Pacientes
                menuPacientes(gerenciamentoPacientes, nomeArquivo); // Chama o menu de pacientes
                break;
            case 0:
                std::cout << "Saindo do sistema...\n";
                break;
            default:
                std::cerr << "Opção inválida! Tente novamente.\n";
        }
    } while (opcaoPrincipal != 0);

    return 0;
}
