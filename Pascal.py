def TrianguloP(numRows):
    lista = [[1] * (i + 1) for i in range(numRows)]

    for i in range(2, numRows):  
        for j in range(1, i):    
            lista[i][j] = lista[i - 1][j - 1] + lista[i - 1][j]

    return lista


print(TrianguloP(6))



