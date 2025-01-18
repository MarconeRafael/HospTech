#include "usuario.h"
#include <iostream>

// Definindo o banco de usuários
std::vector<Usuario> banco_de_usuarios = {
    Usuario("admin", "admin123", NivelAcesso::ADMIN),
    Usuario("medico", "med123", NivelAcesso::MEDICO),
    Usuario("enfermeiro", "enfer123", NivelAcesso::ENFERMEIRO),
    Usuario("tecnico", "tec123", NivelAcesso::TECNICO_LABORATORIO),
    Usuario("recepcionista", "rec123", NivelAcesso::RECEPCIONISTA),
    Usuario("farmaceutico", "farm123", NivelAcesso::FARMACEUTICO),
    Usuario("administracao", "admin1234", NivelAcesso::ADMINISTRACAO),
    Usuario("paciente", "pac123", NivelAcesso::PACIENTE),
    Usuario("auditor", "aud123", NivelAcesso::AUDITOR)
};

Usuario::Usuario(std::string nome, std::string senha, NivelAcesso nivel)
    : nome_usuario(nome), senha(senha), nivel_acesso(nivel) {}

std::string Usuario::get_nome_usuario() const {
    return nome_usuario;
}

NivelAcesso Usuario::get_nivel_acesso() const {
    return nivel_acesso;
}

bool Usuario::validar_login(const std::string& username, const std::string& password) const {
    return (username == nome_usuario && password == senha);
}

// Definição da função autenticar_usuario aqui
Usuario* autenticar_usuario(std::string username, std::string password) {
    for (auto& usuario : banco_de_usuarios) {
        if (usuario.validar_login(username, password)) {
            return &usuario;
        }
    }
    return nullptr; // Caso o usuário não seja encontrado
}
