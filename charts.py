import numpy as np
import matplotlib.pyplot as plt

class charts:

    def distvphase(a, e): # semi-major axis, eccentricity
        # x value
        theta = np.linspace(0, 2 * np.pi, 500)
        # y value
        d = a * (1 - e**2) / (1 + e * np.cos(theta))

        # Plotting Orbital Distance vs Orbital Phase
        plt.figure(figsize=(10, 6))
        plt.plot(theta, d / 1.496e+11, label="Orbital Distance", color='b')  # convert to AU
        plt.xlabel("Orbital Phase (radians)")
        plt.ylabel("Orbital Distance (AU)")
        plt.title("Orbital Distance vs. Orbital Phase")
        plt.legend()
        plt.grid(True)
        plt.show()

    a = 1.0 * 1.496e+11 # semi-major axis
    e = 0.2 # eccentricity
    distvphase(a, e)