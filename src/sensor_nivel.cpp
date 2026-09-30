#include "sensor_nivel.hpp"

#include <sstream>
#include <string>

namespace {
std::string formatarValor(double valor) {
    std::ostringstream saida;
    saida << valor;
    return saida.str();
}
}

SensorNivel::SensorNivel(
    std::string tagInicial,
    double valorInicial,
    std::string unidadeInicial
)
    : tag_(tagInicial),
      valor_(valorInicial),
      unidade_(unidadeInicial),
      ativo_(false),
      totalLeituras_(0) {
}

std::string SensorNivel::tag() const {
    return tag_;
}

double SensorNivel::valor() const {
    return valor_;
}

std::string SensorNivel::unidade() const {
    return unidade_;
}

bool SensorNivel::estaAtivo() const {
    return ativo_;
}

void SensorNivel::ativar() {
    ativo_ = true;
}

void SensorNivel::desativar() {
    ativo_ = false;
}

int SensorNivel::totalLeituras() const {
    return totalLeituras_;
}

bool SensorNivel::registrarLeitura(double valor) {
    if (!ativo_) {
        return false;
    }

    if (!(valor >= 0.0 && valor <= 100.0)) {
        return false;
    }

    valor_ = valor;
    ++totalLeituras_;
    return true;
}

std::string SensorNivel::resumo() const {
    const std::string unidadeTexto = unidade_.empty() ? "" : " " + unidade_;
    const std::string estado = ativo_ ? "ativo" : "inativo";

    return tag_ + ": " + formatarValor(valor_) + unidadeTexto +
           " | " + estado + " | leituras: " + std::to_string(totalLeituras_);
}
