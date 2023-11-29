#include <simlib.h>
#include <math.h>

const double xInit = 1.0; // Initial value of x
const double yInit = 1.0; // Initial value of y
const double zInit = 1.0; // Initial value of z

const double nu = 10.0;   // New parameter ν
const double kappa = 1.0; // New parameter κ
const double a = 1.0;     // New parameter a
const double T0 = 1.0;    // New parameter T0
const double alpha1 = 1.0;// New parameter α1
const double alpha2 = 1.0;// New parameter α2

const double sigma = nu / kappa;
const double rho = (a * T0) / (kappa * M_PI * (a * a + 1)) * alpha1 / alpha2;
const double beta = 4.0 / (a * a + 1);

struct LorenzSystem { // struct - same as class but all members are public
    Integrator x, y, z; // State variables: x, y, z
    LorenzSystem() :
            x(sigma * (y - x), xInit),
            y(x * (rho - z) - y, yInit),
            z(x * y - beta * z, zInit) {};
};

LorenzSystem lorenz;

extern void Sample();

Sampler s(Sample, 0.1);

void Sample() {
    Print("%g %g %g\n", lorenz.x.Value(), lorenz.y.Value(), lorenz.z.Value());
}


int main() {
    // Print("Lorenz System Simulation in C++ \n");
    Init(0, 50.0);     // Initialization of experiment parameters
    SetStep(1e-3, 0.1); // Integration step
    SetAccuracy(0.001); // Max. allowed relative integration error
    Run();             // Simulation
    // Print("End of simulation \n");
    return 0;
}
