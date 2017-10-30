import matplotlib.pyplot as plt

time = []
guess = []
real = []

with open("data_HW5_3_guess.txt", "r") as ins:
    for line in ins:
       	data = line.split()
        time.append(float(data[0]))
        guess.append(float(data[1]))

plt.plot(time, guess)

with open("data_HW5_3_real.txt", "r") as ins:
    for line in ins:
       	data = line.split()
        time.append(float(data[0]))
        real.append(float(data[1]))

plt.plot(time, real, marker='d', color='blue', drawstyle='steps-pre')
plt.show()