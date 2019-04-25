import matplotlib
import matplotlib.pyplot as plt
import numpy as np
filenames=["euler.dat","rk4.dat","leapfrog.dat"]
fig, axs = plt.subplots(nrows=3, ncols=3)
ax=axs[0][0]
ax.set_title('Euler')
ax=axs[0][1]
ax.set_title('RK4')
ax=axs[0][2]
ax.set_title('Leap_frog')
for i in range(3):
    f=open(filenames[i],"r")
    s=list(map(float,f.readline().split()))
    s1=list(map(float,f.readline().split()))
    time=list(map(float,f.readline().split()))
    ax=axs[0][i]
    ax.set_xlabel("time")
    ax.set_ylabel("posistion")
    ax.plot(time,s )
    ax.set_ylim(-1.5,1.5)
    ax.set_xlim(0,15)
    ax=axs[1][i]
    ax.plot(time, s1)
    ax.set_ylim(-1.5,1.5)
    ax.set_xlim(0,15)
    ax.set_xlabel("time")
    ax.set_ylabel("velocity")
    ax=axs[2][i]
    ax.plot(s, s1)
    ax.set_ylim(-2.0,2.0)
    ax.set_xlim(-2.0,2.0)
    ax.set_xlabel("position")
    ax.set_ylabel("velocity")
fig.subplots_adjust(hspace=1, wspace=1)
plt.savefig('graficas.png')
plt.show()

