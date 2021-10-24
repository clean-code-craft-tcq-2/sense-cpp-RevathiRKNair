#include "stats.h"
#include <math.h>  

/* Function to calculate Average */
float Compute_Average(const std::vector<float>& data)
{
    float t_sum=0;
    float t_average=0;

    for(size_t i=0; i< data.size(); i++)
    {
        t_sum += data[i];
    }

    t_average = t_sum/data.size();

    return t_average;
}

/* Function to calculate Max value */
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

/* Function to calculate Min value */
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

/* Function to compute statistics */
Stats Statistics::ComputeStatistics(const std::vector<float>& v_data) {
    
    Stats Computed_Stat;

    float f_average = 0;
    float f_max = 0;
    float f_min = 0;
    
    /* Return NaN if an empty array is passed */
    if(v_data.empty())
    {
        Computed_Stat.average = sqrt(-1.0);
        Computed_Stat.max = sqrt(-1.0);
        Computed_Stat.min = sqrt(-1.0);
    }
    else
    {
        
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
    /* Send an email if threashold exceded */
    emailSent = 1;
}

void LEDAlert::update()
{
    /* Glow LED if threashold exceded */
    ledGlows = 1;
}


void StatsAlerter::checkAndAlert(const std::vector<float>& v_data)
{
    for(size_t i=0; i< v_data.size(); i++)
    {
        /* If Max threashold value is exceded,
		 * Notify to all the listeners to
		 * take necessary actions.
		 */
        if(v_data[i] > maxThreshold)
        {
            notify();
            break;
        }
    }
}

void StatsAlerter::notify()
{
    /* Iterate through all the listeners
	 * and call the respective update function.
	 */
    for(size_t i=0; i< alertersList.size(); i++)
    {
        alertersList[i]->update();
    }
}
