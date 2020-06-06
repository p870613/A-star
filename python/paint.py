from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
import os
min = [[10.75, -4.9, 4.8],
        [10.75, -6.5, 3.9],
        [9.95, -7.2, 3.9],
        [10.10, -8.6, 5.4],
        [11.45, -9.0, 4.1],
        [9.95, -9.1, 4.6],
        [10.95, -8.4, 4.9],
        [11.05, -8.9, 4.2],
        [10.45, -9.1, 4.6]]

max =  [[10.95, -4.7, 5.0],
        [11.95, -6.4, 5.9],
        [10.85, -7.1, 5.9],
        [11.1, -8.3, 5.9],
        [11.95, -8.5, 5.1],
        [10.45, -8.6, 5.6],
        [11.15, -8.2, 5.1],
        [11.25, -8.7, 4.4],
        [10.65, -8.9, 4.8]]

fig = plt.figure()
ax = Axes3D(fig)

x = [[1]]
def plot_linear_cube(x, y, z, dx, dy, dz):
    add_line(x, y, z, dx, y, z, color='red')
    add_line(x, y, z, x, dy, z, color='red')
    add_line(x, dy, z, dx, dy, z, color='red')
    add_line(dx, dy, z, dx, y, z, color='red')
    add_line(dx, y, z, dx, y, dz, color='red')
    add_line(x, y, z, x, y, dz, color='red')
    add_line(x, dy, z, x, dy, dz, color='red')
    add_line(dx, dy, z, dx, dy, dz, color='red')
    add_line(x, y, dz, dx, y, dz, color='red')
    add_line(x, y, dz, x, dy, dz, color='red')
    add_line(x, dy, dz, dx, dy, dz, color='red')
    add_line(dx, dy, z, dx, dy, dz, color='red')
    add_line(dx, y, dz, dx, dy, dz, color='red')
    
    
    
def add_line(s_x, s_y, s_z, d_x, d_y, d_z, color = "yellow"):
    x_line = np.linspace(s_x, d_x, 2000)
    y_line = np.linspace(s_y, d_y, 2000)
    z_line = np.linspace(s_z, d_z, 2000)
    ax.plot3D(x_line, y_line, z_line, color)

def line_input(path):
    f = open(path)
    line = f.readline()
    coor_list = []
    while(line):
        tmp = line.split(',')
        coor = []
        for i in range(3):
            tmp[i] = tmp[i].replace('x', '')
            tmp[i] = tmp[i].replace('y', '')
            tmp[i] = tmp[i].replace('z', '')
            tmp[i] = tmp[i].replace(' ', '')
            tmp[i] = tmp[i].replace(':', '')
            coor.append(int(tmp[i]))
        coor_list.append(coor)
        line = f.readline()
    return coor_list


def koz():
    for i in range(9):
        min[i][0] = int((min[i][0] - 9.95) * 100)
        min[i][1] = int( (min[i][1] + 9.75) * 100)
        min[i][2] = int(( min[i][2] - 3.9 ) * 100)
        max[i][0] = int((max[i][0] - 9.95) * 100)
        max[i][1] = int( (max[i][1] + 9.75) * 100)
        max[i][2] = int(( max[i][2] - 3.9 ) * 100)
        print(min[i])
        print(max[i])

def mapping(x, y, z):
    x = int((x - 9.95) * 100)
    y = int( (y + 9.75) * 100)
    z = int(( z -3.9) * 100)
    return x, y, z


def add_point(x, y, z):
    ax.scatter3D(x, y, z)
    
def get_file_path():
    re = []
    for dirpath, dirname, filename in os.walk('./path/'):
        for f in filename:
            re.append(f)
    return re
    
if __name__ == "__main__":
    #setting x, y, z axes
    ax.set_xlim(0,200) 
    ax.set_ylim(0,700) 
    ax.set_zlim(0,200) 
    plt.xticks(range(0, 200, 25))
    plt.yticks(range(0, 700, 25))

    #setting koz
    koz()
    for i in range(9):
        plot_linear_cube(min[i][0], min[i][1], min[i][2], max[i][0], max[i][1], max[i][2])
    
    total_file_path = get_file_path()
    print(total_file_path)


    for path in total_file_path:
        total_point = line_input('path/' + path)
        for i in range(len(total_point)):
            if(i == 0):
                add_point(total_point[i][0], total_point[i][1], total_point[i][2])
                continue
            if(i == len(total_point)-1):
                add_point(total_point[i][0], total_point[i][1], total_point[i][2])
            add_line(total_point[i][0], total_point[i][1], total_point[i][2],
                 total_point[i-1][0], total_point[i-1][1], total_point[i-1][2])

    plt.show()
    
