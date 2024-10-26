import numpy as np
import matplotlib.pyplot as plt

class charts:
    
    def distvphase(a, e): # semi-major axis, eccentricity
        # x value
        theta = np.linspace(0, 2 * np.pi, 500)
        # y value
        d = a * (1 - e**2) / (1 + e * np.cos(theta))

        plt.figure(figsize=(10, 6))
        plt.plot(theta, d / 1.496e+11, label="Orbital Distance", color='b')  # convert to AU
        plt.xlabel("Orbital Phase (radians)")
        plt.ylabel("Orbital Distance (AU)")
        plt.title("Orbital Distance vs. Orbital Phase")
        plt.legend()
        plt.grid(True)
        plt.show()

    def fluxvphase(a, e, t, r): # semi-major axis, eccentricity, stellar effective temperature, stellar radius
        # x value
        theta = np.linspace(0, 2 * np.pi, 500)
        d = a * (1 - e**2) / (1 + e * np.cos(theta))
        sig = 5.67e-8  # Stefan-Boltzmann constant
        # y value
        F = (sig * t**4 * r**2) / d**2

        plt.figure(figsize=(10, 6))
        plt.plot(theta, F, label="Stellar Flux at Planet", color='orange')
        plt.xlabel("Orbital Phase (radians)")
        plt.ylabel("Stellar Flux (W/m²)")
        plt.title("Stellar Flux at Planet vs. Orbital Phase")
        plt.legend()
        plt.grid(True)
        plt.show()

    def speedvphase(a, e, m): # semi-major axis, eccentricity, stellar mass
        # x value
        theta = np.linspace(0, 2 * np.pi, 500)
        d = a * (1 - e**2) / (1 + e * np.cos(theta))
        G = 6.67430e-11
        # y value; vis viva equation
        v = np.sqrt(G * m * (2 / d - 1 / a))

        plt.figure(figsize=(10, 6))
        plt.plot(theta, v, label="Orbital Speed", color='green')
        plt.xlabel("Orbital Phase (radians)")
        plt.ylabel("Orbital Speed (m/s)")
        plt.title("Orbital Speed vs. Orbital Phase")
        plt.legend()
        plt.grid(True)
        plt.show()

    def gvmass(r): # radius
        m = np.linspace(0.1, 10, 100)
        G = 6.67430e-11
        g = lambda mass : (G * mass) / r**2
        plt.plot(m, g(m * 5.972e24), 'b')
        plt.xlabel("Planet Mass (in Earth Masses)")
        plt.ylabel("Surface Gravity (m/s²)")
        plt.title("Planetary Surface Gravity vs. Planet Mass")
        plt.legend()
        plt.grid(True)
        plt.show()

    def radvmass(m): # mass
        mpoints = np.linspace(0, m*2, 100)
        r = mpoints**0.8
        plt.plot(mpoints, r, 'r')
        plt.xlabel("Stellar Mass (in Solar Masses)")
        plt.ylabel("Stellar Radius (in Solar Radii)")
        plt.title("Stellar Radius vs. Stellar Mass")
        plt.legend()
        plt.grid(True)
        plt.show()

    def periodvaxis(a, m): # semi-major axis, mass
        apoints = np.linspace(0, a*2, 100)
        G = 6.67430e-11
        # Kepler's 3rd Law
        p = 2 * np.pi * np.sqrt(apoints**3 / (G * m))
        plt.plot(apoints, p / (365 * 24 * 3600), 'g')
        plt.xlabel("Semi-Major Axis (AU)")
        plt.ylabel("Orbital Period (years)")
        plt.title("Orbital Period vs. Semi-Major Axis")
        plt.legend()
        plt.grid(True)
        plt.show()

    def luminosityvrad(r, t): # radius, temperature
        rpoints = np.linspace(0, r*2, 100)
        sigma = 5.67e-8  # Stefan-Boltzmann constant
        l = lambda radii, temp : 4 * np.pi * radii**2 * sigma * temp**4
        plt.plot(rpoints, l(rpoints * 6.955e8, t) / 3.828e26, 'm')
        plt.xlabel("Stellar Radius (in Solar Radii)")
        plt.ylabel("Stellar Luminosity (in Solar Luminosities)")
        plt.title("Stellar Luminosity vs. Stellar Radius")
        plt.legend()
        plt.grid(True)
        plt.show()

    def tempvrad(m): # mass
        mpoints = np.linspace(0, m*2, 100)
        r = mpoints**0.8
        t = 5600 * (r**-0.5)  # Example inverse relationship for HR diagram
        plt.plot(r, t, 'c')
        plt.xlabel("Stellar Radius (in Solar Radii)")
        plt.ylabel("Effective Temperature (K)")
        plt.title("Stellar Effective Temperature vs. Stellar Radius") # can make an HR diagram
        plt.legend()
        plt.grid(True)
        plt.show()

    def metalvmass(m): # mass
        mpoints = np.linspace(0, m*2, 200)
        metallicity = -0.5 + 0.5 * (mpoints**0.2)
        plt.plot(mpoints, metallicity, 'y')
        plt.xlabel("Stellar Mass (in Solar Masses)")
        plt.ylabel("Metallicity [Fe/H]")
        plt.title("Metallicity vs. Stellar Mass")
        plt.legend()
        plt.grid(True)
        plt.show()

    # TEST VALUES
    a = 1.0 * 1.496e+11 # semi-major axis
    e = 0.2 # eccentricity
    t = 5778 # Stellar effective temperature in Kelvin (Sun's temperature)
    r = 6.955e8 # Stellar radius in meters (Sun's radius)
    m = 1.989e30    # Stellar mass in kg (mass of the Sun)
    metalvmass(m)