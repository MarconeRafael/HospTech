#include <iostream>
#include "usuario.h"
#include "pacientes.h"
#include "menupacientes.h"
#include "menuprincipal.h"  
int main() {
    GerenciamentoPacientes gerenciamentoPacientes;
    std::string nomeArquivo = "../data/pacientes.csv";  // Caminho relativo para salvar em 'data'

    // Etapa 1: Autenticar o usuário
    std::string username, password;
    Usuario* usuarioAutenticado = nullptr;

    while (usuarioAutenticado == nullptr) {
        std::cout << "Digite seu nome de usuario: ";
        std::cin >> username;
        std::cout << "Digite sua senha: ";
        std::cin >> password;

        usuarioAutenticado = autenticar_usuario(username, password);
        if (usuarioAutenticado == nullptr) {
            std::cout << "Nome de usuário ou senha incorretos. Tente novamente.\n";
        }
    }

    // Etapa 2: Exibir o menu com base no nível de acesso
    int opcaoPrincipal;
    do {
        exibirMenuPrincipal(*usuarioAutenticado);  // Passando o usuário autenticado

        std::cin >> opcaoPrincipal;

        // Verifica o nível de acesso e direciona para o menu correspondente
        switch (opcaoPrincipal) {
            case 1:  // Gerenciamento de Pacientes
                if (usuarioAutenticado->get_nivel_acesso() == NivelAcesso::MEDICO ||
                    usuarioAutenticado->get_nivel_acesso() == NivelAcesso::ENFERMEIRO) {
                    menuPacientes(gerenciamentoPacientes, nomeArquivo);  // Chama o menu de pacientes
                } else {
                    std::cout << "Você não tem permissão para acessar o gerenciamento de pacientes.\n";
                }
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
