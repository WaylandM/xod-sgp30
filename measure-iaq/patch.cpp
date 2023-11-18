#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto sensor = getValue<input_DEV>(ctx);

        if (! sensor->IAQmeasure()) {
            raiseError(ctx);
            return;
        }

        emitValue<output_CO2>(ctx, sensor->eCO2);
        emitValue<output_TVOC>(ctx, sensor->TVOC);
        emitValue<output_Done>(ctx, 1);

    }
}
