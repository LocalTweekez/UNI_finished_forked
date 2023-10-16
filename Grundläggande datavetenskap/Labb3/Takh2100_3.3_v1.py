#! python3
# filnamn: Takh2100_3.3_v1.py
# Skrivet av: Taha Khudher
# Skapat datum: 2021-10-04
# Senast ändrat: 2021-10-07
# Kurs: Grundläggande Datavetenskap
# Handledare: Martin Kjellqvist
# Beskrivning:


år = int(input("Ange år: "))
if år % 4 == 0:
    if år%100== 0:
        if år%400==0:
            print("Skottår")
        else:
            print("inte skottår")
    else:
        print("skottår")
else:
    print("inte skottår")
    
