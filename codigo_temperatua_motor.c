#define FACTOR_ACELERACAO 0.1
#define FATOR_RESFRIAMENTO_AR 0.05
#define MAX_TEMP_MOTOR 140
#define BASE_TEMP 80

double calculate_engine_temp(double velocidade, double rpm) {
    double temp_rise = rpm/10 * FACTOR_ACELERACAO;
    double cooling_effect = velocidade * FATOR_RESFRIAMENTO_AR;
    double temp = BASE_TEMP + temp_rise - cooling_effect;
    return fmin(MAX_TEMP_MOTOR, temp);
}