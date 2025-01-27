#ifndef AUDITORIA_H
#define AUDITORIA_H

#include <string>

class Auditoria {
public:
    void registrarAtividade(const std::string& atividade);
    void listarAtividades();
    void carregarAtividades(); 
};

#endif // AUDITORIA_H
