# první parametr je cesta k souboru s daty

import matplotlib.pyplot as plt
import sys

# Funkce pro načtení souřadnic ze souboru
def load_coordinates(file_path):
    coordinates = []
    with open(file_path, 'r') as file:
        for line in file:
            x, y, z = map(float, line.strip().split())
            coordinates.append((x, y, z))
    return coordinates

# Načtení souřadnic ze souboru
file_path = '../data.dat'  # Nahraďte skutečným názvem souboru
if len(sys.argv) > 1 and sys.argv[1] != "":
    file_path = sys.argv[1]



coordinates = load_coordinates(file_path)

# Rozdělení souřadnic na x, y, z
x, y, z = zip(*coordinates)

# Vykreslení 3D grafu
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Vykreslení bodů
ax.scatter(x, y, z, c='r', marker='o', label='Body')

# Vytvoření a vykreslení křivky procházející body
ax.plot(x, y, z, c='b', linestyle='-', label='Křivka')

# Přidání popisků os
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# Přidání legendy
ax.legend()

# Zobrazení grafu
plt.show()