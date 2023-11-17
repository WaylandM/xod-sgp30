// Tell XOD where it can download the libraries:
#pragma XOD require "https://github.com/adafruit/Adafruit_BusIO"
#pragma XOD require "https://github.com/adafruit/Adafruit_Sensor"
#pragma XOD require "https://github.com/adafruit/Adafruit_SGP30"

//Include C++ libraries
#include <Adafruit_SGP30.h>

node {

    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = Adafruit_SGP30*;
    }

    // Keep Adafruit_SGP30 object in state
    Adafruit_SGP30 sensor = Adafruit_SGP30();


    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;
        emitValue<output_DEV>(ctx, &sensor);
    }
}
