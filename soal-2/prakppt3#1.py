# input user
# definisi fungsi f(x)
# proses metode secant
# output hasil

fungsi = input("Masukkan fungsi f(x): ")

def f(x):
    return eval(fungsi)

x0 = float(input("Masukkan x0: "))
x1 = float(input("Masukkan x1: "))
toleransi = float(input("Masukkan toleransi: "))
max_iter = int(input("Masukkan maksimum iterasi: "))

iterasi = 0

while iterasi < max_iter:
    if f(x1) - f(x0) == 0:
        print("Terjadi pembagian nol!")
        break

    x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))

    error = abs(x2 - x1)

    print(f"Iterasi {iterasi+1}: x = {x2}, error = {error}")

    if error < toleransi:
        break

    x0 = x1
    x1 = x2

    iterasi += 1

print("\nHasil akhir:")
print("Akar =", x2)
print("Jumlah iterasi =", iterasi+1)