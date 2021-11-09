from random import randint


file = open("../cmake-build-debug/data.txt", "w")

for i in range(-1000, 1000):
    file.write(str(i) + '\n')

file.close()

print('file created')