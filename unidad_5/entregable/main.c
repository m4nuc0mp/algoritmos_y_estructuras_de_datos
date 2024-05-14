#include "cabecera.h"

int main(void)
{
    const int32_t MAX_TIME = 1440; // Entre 0 y 1440 minutos
    const int32_t MIN_TEMP = 263; // Tmin = -10 °C
    const int32_t MAX_TEMP = 313; // Tmax = 40 °C
    const int32_t STEP = 5; // Diferencias de 5 grados Kelvin entre Temps
    const int64_t NEX = rand_times(20, 30); // Entre 20 y 30 medidas por stack
    const int64_t NSLL = rand_times(10, 15); // Entre 10 y 15 listas de stacks
    
    sll_node* measurements_list = NULL;

    measurements_list = sll_temp_stacks_simulation(
        MAX_TIME, MIN_TEMP, MAX_TEMP, STEP, NEX, NSLL
        );

    return 0;
}