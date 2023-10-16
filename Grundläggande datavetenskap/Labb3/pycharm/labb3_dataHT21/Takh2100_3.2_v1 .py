#! python3
# filnamn: Takh2100_3.2_v1.py
# Skrivet av: Taha Khudher
# Skapat datum: 2021-10-04
# Senast ändrat: 2021-10-07
# Kurs: Grundläggande Datavetenskap
# Handledare: Martin Kjellqvist
# Beskrivning:

M = int(input("Mata in ett Tal: "))
N = int(input("Mata in ett mindre tal: "))

R = M % N
while R != 0:
    M = N
    N = R
    R= M%N
print(N)
