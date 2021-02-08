#include <IntervalTimer.h>

IntervalTimer timer();

int counter = 0;

void intervalHandler()
{
    counter++;
}

void setup(void)
{
    Serial.begin(115200);
    while (!Serial);

    timer.setHandler(intervalHandler);
}

void loop(void)
{
    Serial.println(counter);
}
