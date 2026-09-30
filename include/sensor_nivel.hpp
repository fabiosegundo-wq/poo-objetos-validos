#ifndef SENSOR_NIVEL_HPP
#define SENSOR_NIVEL_HPP

#include <string>

class SensorNivel {
private:
    std::string tag_;
    double valor_;
    std::string unidade_;
    bool ativo_ = false;
    int totalLeituras_ = 0;

public:
    SensorNivel(std::string tagInicial, double valorInicial, std::string unidadeInicial = "");

    std::string tag() const;
    double valor() const;
    std::string unidade() const;
    bool estaAtivo() const;
    void ativar();
    void desativar();
    int totalLeituras() const;
    bool registrarLeitura(double valor);
    std::string resumo() const;
};

#endif
