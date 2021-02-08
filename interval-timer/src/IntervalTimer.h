#ifndef Utils__Interval_Timer_h
#define Utils__Interval_Timer_h

#if defined(ESP8266) || defined(ESP32)
#include <functional>
#endif

#define DEFAULT_INTERVAL_TIME 0

typedef std::function<void()> IntervalHandlerFunction;

class IntervalTimer
{
public:
    IntervalTimer(int intervalMSTime);
    void setHandler(IntervalHandlerFunction handler);
    void setTimeLapse(int intervalMSTime);
    void loop();

private:
    IntervalHandlerFunction _handler;
    int _intervalMSTime;
    // Control flags
    unsigned long _previousMillis;
    unsigned long _currentMillis;
};

IntervalTimer::IntervalTimer(int intervalMSTime = DEFAULT_INTERVAL_TIME)
{
    this->setTimeLapse(intervalMSTime);
}

void IntervalTimer::setHandler(IntervalHandlerFunction handler)
{
    _handler = handler;
}

void IntervalTimer::setTimeLapse(int intervalMSTime)
{
    _intervalMSTime = intervalMSTime;
}

void IntervalTimer::loop()
{
    _currentMillis = millis();
    if (_currentMillis - _previousMillis >= _intervalMSTime)
    {
        _previousMillis = _currentMillis;

        if (_handler)
        {
            _handler();
        }
    }
}

#endif
