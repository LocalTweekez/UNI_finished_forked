import matplotlib.pyplot as plt
import numpy as np

data_file = open("cmake-build-debug/text", "r")

algorithmName = ""
interval = 0
counter = 1

x = []
y1 = []
y_mean = []
y_std = []


for line in data_file:
    if line.startswith("M//"):

        header = line.lstrip("M//").rstrip("\n").split("//")
        algorithmName = header[0]
        interval = int(header[1])

        print(interval)

        for i in range(interval):
            line = data_file.readline()
            values = line.strip().split("#")
            x.append(int(values[1]))
            y1.append(int(values[2]))
            y_std.append(int(values[3]))

        timeframe = "nanoseconds"


        plt.plot(x, y1, label="Average search time")
        plt.xlabel("Input size")
        plt.ylabel("Average execution time ("+timeframe+")")

        ax = plt.gca()

        y_max = np.mean(y1)*3

        ax.set_ylim([0, y_max])

        plt.title(algorithmName + " (Interval: " + str(interval) + ")")
        plt.legend()

        #plt.savefig('results\\plot'+str(counter)+'_'+algorithmName+'.png')

        plt.show()

        x.clear()
        y1.clear()

        counter += 1


data_file.close()
