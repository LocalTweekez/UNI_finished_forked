import matplotlib.pyplot as plt
x = []
y = []
order = ""
method=""
print(len(x))
file = open("cmake-build-debug/data.txt", "r")
for line in file:
    if(line.startswith("Method:")):
        if(len(x) != 0):
            plt.plot(x, y, label=order)
            plt.xlabel("Input size")
            plt.ylabel("Average execution time (ms)")

            ax = plt.gca()
            maxy = y[-1]
            ax.set_ylim(0, maxy)
            plt.title(method + " Performance")
            # Add legend to the plot
            plt.legend()
            # Show the plot
            plt.show()
            x.clear()
            y.clear()

        method = line.lstrip("Method:")
        method = method.rstrip("\n")
        continue

    if(line.startswith("order:")):
        order = line.lstrip("order:")
        order = order.rstrip("\n")
        continue
    line = file.readline()
    values = line.strip().split("|")
    x.append(float(values[0]))
    y.append(float(values[1]))
file.close()

plt.plot(x, y, label=order)
plt.xlabel("Input size")
plt.ylabel("Average execution time (ms)")

ax = plt.gca()
maxy = y[-1]
ax.set_ylim(0, maxy)
plt.title(method + " Performance")
# Add legend to the plot
plt.legend()

# Show the plot
plt.show()
