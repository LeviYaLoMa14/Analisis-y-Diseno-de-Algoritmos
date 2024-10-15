import random
import math

def generar_puntos_aleatorios(n):
    puntos = [(random.uniform(-100, 100), random.uniform(-100, 100)) for _ in range(n)]
    return puntos

def distancia(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

def par_mas_cercano(puntos):
    puntos.sort(key=lambda x: x[0])
    
    def par_mas_cercano_rec(P):
        if len(P) <= 3:
            return fuerza_bruta(P)
        mitad = len(P) // 2
        punto_mitad = P[mitad]
        
        dl = par_mas_cercano_rec(P[:mitad])
        dr = par_mas_cercano_rec(P[mitad:])
        
        d = min(dl, dr)
        
        franja = [p for p in P if abs(p[0] - punto_mitad[0]) < d]
        return min(d, franja_cercana(franja, d))
    
    def fuerza_bruta(P):
        dist_min = float('inf')
        for i in range(len(P)):
            for j in range(i + 1, len(P)):
                dist_min = min(dist_min, distancia(P[i], P[j]))
        return dist_min
    
    def franja_cercana(franja, d):
        franja.sort(key=lambda p: p[1])
        dist_min = d
        for i in range(len(franja)):
            for j in range(i + 1, len(franja)):
                if franja[j][1] - franja[i][1] >= dist_min:
                    break
                dist_min = min(dist_min, distancia(franja[i], franja[j]))
        return dist_min
    
    return par_mas_cercano_rec(puntos)

n = 10
puntos = generar_puntos_aleatorios(n)
dist_minima = par_mas_cercano(puntos)
print(f"Puntos generados: {puntos}")
print(f"Distancia mínima entre dos puntos: {dist_minima}")
