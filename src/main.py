from sensor_nivel import SensorNivel


sensor = SensorNivel("LT-101", 42.5, "%")
print(sensor.resumo())
sensor.ativar()
print(f"Leitura aceita: {sensor.registrar_leitura(55.0)}")
print(sensor.resumo())
