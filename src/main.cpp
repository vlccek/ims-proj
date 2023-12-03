#include <simlib.h>
#include <math.h>


const double beta1 = 0.1;
const double gamma1 = 0.05;
const double beta2 = 0.08;
const double gamma2 = 0.03;

// starting conditions
const double s1Input = 1000;
const double I1Input = 1;
const double s2Input = 1000;
const double I2Input = 0;

struct kapavkaModel {
    Integrator s1, I1, s2, I2; // Integrátory pro výpočet stavu systému
public:
    kapavkaModel() :
            s1((-beta1 * s1 * I2 + gamma1 * I1), s1Input),
            I1((beta1 * s1 * I2 - gamma1 * I1), I1Input),
            s2((-beta2 * s2 * I1 + gamma2 * I2), s2Input),
            I2((beta2 * s2 * I1 - gamma2 * I2), I2Input) {}
};

kapavkaModel mod1;

extern void Sample();


void Sample() {
    Print("%g %g %g %g\n", mod1.s1.Value(), mod1.I1.Value(), mod1.s2.Value(), mod1.I2.Value());
}


int main(int argc, char *argv[]) {
    kapavkaModel mod1; //
    Sampler s(Sample, 0.1); // Sampler pro výpis stavu systému

    // Print("Lorenz System Simulation in C++ \n");
    Init(0, 50.0);     // Initialization of experiment parameters
    SetStep(1e-3, 0.1); // Integration step
    SetAccuracy(0.001); // Max. allowed relative integration error
    Run();             // Simulation
    // Print("End of simulation \n");
    return 0;
}
