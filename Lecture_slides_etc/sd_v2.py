# Importing Libraries
import numpy as np
import numpy.linalg as la
import scipy.optimize as sopt
import matplotlib.pyplot as plt
#from time import process_time

from mpl_toolkits.mplot3d import axes3d

#t1_start = process_time()
# the objective function
def f(x):
        return 0.5*x[0]**2 + 2.5*x[1]**2

# gradient of the objective function
def df(x):
        return np.array ([x[0], 5*x[1]])

fig = plt.figure()
ax = plt.axes(projection = '3d')

xmesh, ymesh = np.mgrid[-2:2:50j,-2:2:50j]
fmesh = f(np.array([xmesh, ymesh]))
ax.plot_surface(xmesh, ymesh, fmesh)

#plt.axis("equal")
#plt.contour(xmesh, ymesh, fmesh)

plt.show()

tol = 1e-8
iteration = 200
# initial guess
y0 = np.array ([1.1, 2.2])

#print(la.norm(pk))
i = 0
#for i in range(iteration):
y = [np.array(y0)] 
while la.norm(df(y[i])) > tol :
# descent direction = steepest descent direction
        pk = -df(y[i]) / la.norm(df(y[i])) 
# Backtracking algorithm
        rho = 0.9 # the contraction factor
        alpha = 0.9 # the first guess for step length
        c = 1e-4
        j = 0
        while f(y[i] + alpha * pk) > f(y[i]) + c * alpha * np.dot(df(y[i]), pk) :
                alpha = alpha * rho
                j +=1

        alphak = alpha
        y1 = y[i] + alpha * pk
        y.append(y1)
        i += 1
        print('number of iteration to satisfy the Wolfe Condition is:', j)
        print('the',i,'th iterate is:', y[i])

print('gradient of the solution = ', df(y[i]))
print('the value at solution = ', f(y[i]))
print('number of iterations taken =', i)

plt.axis("equal")
plt.contour(xmesh, ymesh, fmesh, 50)
it_array = np.array(y)
plt.plot(it_array.T[0], it_array.T[1], "x-")
plt.show()

#t1_stop = process_time()

#print("Elapsed time:", t1_stop, t1_start)

#print("Elapsed time during the whole program in seconds:",
#                                         t1_stop-t1_start)
