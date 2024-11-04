import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# データ読み込み
df = pd.read_csv('../build/simout.csv', header=None)
print(df)

# グラフプロット(系列名無し)
fig, ax = plt.subplots(2, 2, figsize=(12,12))

ax[0,0].plot(df.iloc[:,0], df.iloc[:,0], label="graph1")
# ax[0,0].plot([2,3,2,3], label="graph1")
ax[0,0].set_xlabel('time')
ax[0,0].set_ylabel('time')

ax[0,1].plot(df.iloc[:,0], df.iloc[:,1])
ax[0,1].set_title('1')

ax[1,0].plot(df.iloc[:,0], df.iloc[:,2])
ax[1,0].set_title('2')

ax[1,1].plot(df.iloc[:,0], df.iloc[:,3])
ax[1,1].set_title('3')

for i in range(2):
    for j in range(2):
        ax[i,j].legend()
        ax[i,j].grid()


# # 単体プロット
# x = np.linspace(0, 1, 100)
# y = x ** 2
# fig2 = plt.figure()
# ax2 = fig2.add_subplot(111)
# ax2.plot(x, y)
        
# # matlab style単体プロット
# plt.plot(df.iloc[:,0], df.iloc[:,2])

# object style単体プロット
fig2, ax2 = plt.subplots()
ax2.plot(df.iloc[:,0], df.iloc[:,2], label="graph1")
ax2.plot(df.iloc[:,0], df.iloc[:,3], label="graph2")
ax2.legend()
ax2.grid()



plt.show()