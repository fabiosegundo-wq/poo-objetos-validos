#include <iostream>

#include "sensor_nivel.hpp"

int main() {
    SensorNivel sensor{"LT-101", 42.5, "%"};

    std::cout << sensor.resumo() << '\n';

    sensor.ativar();
    std::cout << "Leitura aceita: " << std::boolalpha
              << sensor.registrarLeitura(55.0) << '\n';

    std::cout << sensor.resumo() << '\n';
    return 0;
}
