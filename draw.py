import matplotlib.pyplot as plt

quantum = []
turnarroud = []

with open("data_HW5_1.txt", "r") as ins:
    for line in ins:
       	data = line.split()
        quantum.append(int(data[0]))
        turnarroud.append(int(data[1]))

plt.plot(quantum, turnarroud)
plt.show()