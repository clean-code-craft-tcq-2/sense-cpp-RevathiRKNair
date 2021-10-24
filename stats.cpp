#include "stats.h"
#include <math.h>  

float Compute_Average(const std::vector<float>& data)
{
    float t_sum;
    float t_average;

    for(size_t i=0; i< data.size(); i++)
    {
        t_sum += data[i];
    }

    t_average = t_sum/data.size();

    return t_average;
}

float Compute_Max(const std::vector<float>& data)
{
    float t_max;

    t_max = 0;
    for(size_t i=0; i< data.size(); i++)
    {
        if(data[i] > t_max)
        {
            t_max = data[i];
        }
    }

    return t_max;
}

float Compute_Min(const std::vector<float>& data)
{
    float t_min;

    t_min = data[0];
    for(size_t i=0; i< data.size(); i++)
    {
        if(data[i] < t_min)
        {
            t_min = data[i];
        }
    }

    return t_min;
}

Stats Statistics::ComputeStatistics(const std::vector<float>& v_data) {
    //Implement statistics here
    Stats Computed_Stat;

    float f_average = 0;
    float f_max = 0;
    float f_min = 0;

    if(v_data.empty())
    {
        Computed_Stat.average = sqrt(-1.0);
        Computed_Stat.max = sqrt(-1.0);
        Computed_Stat.min = sqrt(-1.0);
    }
    else
    {
        //Average
        f_average = Compute_Average(v_data);

        f_max = Compute_Max(v_data);

        f_min = Compute_Min(v_data);

        Computed_Stat.average = f_average;
        Computed_Stat.max = f_max;
        Computed_Stat.min = f_min;
    }

    return Computed_Stat;
}

void EmailAlert::update()
{
    emailSent = 1;
}

void LEDAlert::update()
{
    ledGlows = 1;
}


void StatsAlerter::checkAndAlert(const std::vector<float>& v_data)
{
    for(size_t i=0; i< v_data.size(); i++)
    {
        if(v_data[i] > maxThreshold)
        {
            notify();
            break;
        }
    }
}

void StatsAlerter::notify()
{
    for(size_t i=0; i< alertersList.size(); i++)
    {
        alertersList[i]->update();
    }
}
