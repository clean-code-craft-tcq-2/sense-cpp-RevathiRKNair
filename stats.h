#include <vector>

struct Stats
{
    float average = 0;
    float min = 0;
    float max = 0; 
};



namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>& );
}

class IAlerter
{
    public:
        virtual void update() = 0;
};

class EmailAlert : public IAlerter
{
    public:
        bool emailSent = 0;
        void update();
};


class LEDAlert : public IAlerter
{
    public:
        bool ledGlows = 0;
        void update();
};


class StatsAlerter
{
    private:
        float maxThreshold;
        std::vector<IAlerter*> alertersList;

    public:
        StatsAlerter(float Threshold_value,std::vector<IAlerter*> alerters)
        {
            maxThreshold = Threshold_value;
            alertersList = alerters;
        }
        
        void checkAndAlert(const std::vector<float>& v_data);
        void notify();
};
