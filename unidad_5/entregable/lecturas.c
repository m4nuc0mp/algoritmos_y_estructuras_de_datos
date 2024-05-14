#include "lecturas.h"

reading* reading_create(int32_t min, temp_unit temp)
{
    reading* new_reading = (reading*) malloc(sizeof(reading));

    if (NULL != new_reading)
    {
        new_reading->min = min;
        new_reading->temp = temp;
    }
    return new_reading;
}

void reading_delete(reading* re)
{
    free(re);
}

int32_t reading_get_minute(reading* re)
{
    int32_t time = -1;

    if (NULL != re)
    {
        time = re->min;
    }
    return time;
}

temp_unit reading_get_temp(reading* re)
{
    int32_t temp = -274;

    if (NULL != re)
    {
        temp = re->temp;
    }
    return temp;
}

int8_t reading_cmp(reading* re_1, reading* re_2)
{
    int8_t result = 0;

    if (re_1->temp < re_2->temp)
    {
        result = -1;
    }
    else if (re_1->temp > re_2->temp)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}