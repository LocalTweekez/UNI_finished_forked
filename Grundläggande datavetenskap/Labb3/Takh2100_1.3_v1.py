#! python3
# filnamn: Takh2100_1.3_v1.py
# Skrivet av: Taha Khudher
# Skapat datum: 2021-10-04
# Senast ändrat: 2021-10-07
# Kurs: Grundläggande Datavetenskap
# Handledare: Martin Kjellqvist
# Beskrivning: Ett pris matas in, momsen räknas ut och aderas med startvärdet
# för att få summan som då är orginella priset utan moms avdrag



PrisUtanMoms= int(input("Mata in priset utan moms: "))
MomsSats = 0.25
moms=PrisUtanMoms*MomsSats
PrisMedMoms = moms + PrisUtanMoms
print("moms: ", moms)
print("Pris med moms: ", PrisMedMoms)
