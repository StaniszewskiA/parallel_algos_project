import matplotlib.pyplot as plt
import numpy as np

# Dane
threads = [1, 2, 4, 8, 16, 32, 64]
time = [0.132495, 0.068386, 0.0464664, 0.0361292, 0.034128, 0.0327024, 0.0323079]
speedup = [np.inf, 0.201262, 0.296203, 0.380952, 0.414224, 0.420871, 0.42601]
efficiency = [np.inf, 0.100631, 0.0740508, 0.047619, 0.025889, 0.0131522, 0.00665641]
karp_flatt = [np.inf, 1.79874, 1.2346, 1.08844, 1.03905, 1.01868, 1.00911]

fig, axes = plt.subplots(3, 1, figsize=(10, 15), sharex=True)

axes[0].plot(threads, speedup, marker='o', label='Przyspieszenie')
axes[0].set_title('Przyspieszenie a liczba wątków')
axes[0].set_ylabel('Przyspieszenie')
axes[0].grid(True)
axes[0].legend()

axes[1].plot(threads, efficiency, marker='o', color='orange', label='Efektywność')
axes[1].set_title('Efektywność a liczba wątków')
axes[1].set_ylabel('Efektywność')
axes[1].grid(True)
axes[1].legend()

axes[2].plot(threads, karp_flatt, marker='o', color='green', label='Metryka Karp-Flatta')
axes[2].set_title('Metryka Karp-Flatta a liczba wątków')
axes[2].set_xlabel('Liczba wątków')
axes[2].set_ylabel('Metryka Karp-Flatta')
axes[2].grid(True)
axes[2].legend()

plt.tight_layout()
plt.show()
