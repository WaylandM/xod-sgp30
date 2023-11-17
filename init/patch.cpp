#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_INIT

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_INIT>(ctx))
            return;

        auto sensor = getValue<input_DEV>(ctx);
        auto wire = getValue<input_I2C>(ctx);

        // Attempt to initialize sgp30 module; if attempt fails emit error
        if (!sensor->begin(wire, true)) {
            raiseError(ctx);
            return;
        }

        emitValue<output_OK>(ctx, 1);

    }
}
