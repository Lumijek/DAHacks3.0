#ifndef CHARTS_H
#define CHARTS_H

#include <matplot/matplot.h>
#include <string>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;
using namespace matplot;

class Charts {
public:
    static void distvphase(double a, double e, const std::string& filename) {
        std::vector<double> theta = linspace(0, 2 * M_PI, 500);
        std::vector<double> d(theta.size());

        for (size_t i = 0; i < theta.size(); ++i) {
            d[i] = a * (1 - e * e) / (1 + e * std::cos(theta[i])) / 1.496e+11; // convert to AU
        }

        plot(theta, d, "b")->line_width(2);
        xlabel("Orbital Phase (radians)");
        ylabel("Orbital Distance (AU)");
        title("Orbital Distance vs. Orbital Phase");
        grid(true);
        save_plot(filename);
    }

    static void fluxvphase(double a, double e, double t, double r, const std::string& filename) {
        std::vector<double> theta = linspace(0, 2 * M_PI, 500);
        std::vector<double> F(theta.size());
        const double sig = 5.67e-8;

        for (size_t i = 0; i < theta.size(); ++i) {
            double d = a * (1 - e * e) / (1 + e * std::cos(theta[i]));
            F[i] = (sig * pow(t, 4) * pow(r, 2)) / pow(d, 2);
        }

        plot(theta, F, "orange")->line_width(2);
        xlabel("Orbital Phase (radians)");
        ylabel("Stellar Flux (W/m²)");
        title("Stellar Flux at Planet vs. Orbital Phase");
        grid(true);
        save_plot(filename);
    }

    static void speedvphase(double a, double e, double m, const std::string& filename) {
        std::vector<double> theta = linspace(0, 2 * M_PI, 500);
        std::vector<double> v(theta.size());
        const double G = 6.67430e-11;

        for (size_t i = 0; i < theta.size(); ++i) {
            double d = a * (1 - e * e) / (1 + e * std::cos(theta[i]));
            v[i] = sqrt(G * m * (2 / d - 1 / a));
        }

        plot(theta, v, "green")->line_width(2);
        xlabel("Orbital Phase (radians)");
        ylabel("Orbital Speed (m/s)");
        title("Orbital Speed vs. Orbital Phase");
        grid(true);
        save_plot(filename);
    }

    static void gvmass(double r, const std::string& filename) {
        std::vector<double> m = linspace(0.1, 10, 100);
        const double G = 6.67430e-11;
        std::vector<double> g(m.size());

        for (size_t i = 0; i < m.size(); ++i) {
            g[i] = (G * m[i] * 5.972e24) / pow(r, 2);
        }

        plot(m, g, "b")->line_width(2);
        xlabel("Planet Mass (in Earth Masses)");
        ylabel("Surface Gravity (m/s²)");
        title("Planetary Surface Gravity vs. Planet Mass");
        grid(true);
        save_plot(filename);
    }

    static void radvmass(double m, const std::string& filename) {
        std::vector<double> mpoints = linspace(0, m * 2, 100);
        std::vector<double> r(mpoints.size());

        for (size_t i = 0; i < mpoints.size(); ++i) {
            r[i] = pow(mpoints[i], 0.8);
        }

        plot(mpoints, r, "r")->line_width(2);
        xlabel("Stellar Mass (in Solar Masses)");
        ylabel("Stellar Radius (in Solar Radii)");
        title("Stellar Radius vs. Stellar Mass");
        grid(true);
        save_plot(filename);
    }

    static void periodvaxis(double a, double m, const std::string& filename) {
        std::vector<double> apoints = linspace(0, a * 2, 100);
        const double G = 6.67430e-11;
        std::vector<double> p(apoints.size());

        for (size_t i = 0; i < apoints.size(); ++i) {
            p[i] = 2 * M_PI * sqrt(pow(apoints[i], 3) / (G * m)) / (365 * 24 * 3600); // convert to years
        }

        plot(apoints, p, "g")->line_width(2);
        xlabel("Semi-Major Axis (AU)");
        ylabel("Orbital Period (years)");
        title("Orbital Period vs. Semi-Major Axis");
        grid(true);
        save_plot(filename);
    }

    static void luminosityvrad(double r, double t, const std::string& filename) {
        std::vector<double> rpoints = linspace(0, r * 2, 100);
        const double sigma = 5.67e-8;
        std::vector<double> l(rpoints.size());

        for (size_t i = 0; i < rpoints.size(); ++i) {
            l[i] = (4 * M_PI * pow(rpoints[i] * 6.955e8, 2) * sigma * pow(t, 4)) / 3.828e26;
        }

        plot(rpoints, l, "m")->line_width(2);
        xlabel("Stellar Radius (in Solar Radii)");
        ylabel("Stellar Luminosity (in Solar Luminosities)");
        title("Stellar Luminosity vs. Stellar Radius");
        grid(true);
        save_plot(filename);
    }

    static void tempvrad(double m, const std::string& filename) {
        std::vector<double> mpoints = linspace(0, m * 2, 100);
        std::vector<double> r(mpoints.size()), t(mpoints.size());

        for (size_t i = 0; i < mpoints.size(); ++i) {
            r[i] = pow(mpoints[i], 0.8);
            t[i] = 5600 * pow(r[i], -0.5); // inverse relationship for HR diagram
        }

        plot(r, t, "c")->line_width(2);
        xlabel("Stellar Radius (in Solar Radii)");
        ylabel("Effective Temperature (K)");
        title("Stellar Effective Temperature vs. Stellar Radius");
        grid(true);
        save_plot(filename);
    }

    static void metalvmass(double m, const std::string& filename) {
        std::vector<double> mpoints = linspace(0, m * 2, 200);
        std::vector<double> metallicity(mpoints.size());

        for (size_t i = 0; i < mpoints.size(); ++i) {
            metallicity[i] = -0.5 + 0.5 * pow(mpoints[i], 0.2);
        }

        plot(mpoints, metallicity, "y")->line_width(2);
        xlabel("Stellar Mass (in Solar Masses)");
        ylabel("Metallicity [Fe/H]");
        title("Metallicity vs. Stellar Mass");
        grid(true);
        save_plot(filename);
    }

private:
    static void save_plot(const std::string& filename) {
        fs::create_directories("temp_images");
        save("temp_images/" + filename + ".png");
        clf(); // Clear the figure for the next plot
    }
};

#endif // CHARTS_H