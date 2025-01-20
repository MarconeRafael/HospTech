#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <string>
#include <vector>

class Item {
public:
    Item(const std::string& nome, int quantidade, const std::string& descricao);

    std::string getNome() const;
    int getQuantidade() const;
    std::string getDescricao() const;
    void setQuantidade(int quantidade);

private:
    std::string nome;
    int quantidade;
    std::string descricao;
};

class Inventario {
public:
    void adicionarItem(const Item& item);
    void atualizarItem(const std::string& nome, int quantidade);
    void buscarItem(const std::string& nome); 
    void listarItens() const;

private:
    std::vector<Item> itens;
};

#endif // INVENTARIO_H
