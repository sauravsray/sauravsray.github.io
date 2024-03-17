# Importing Libraries
import numpy as np
import numpy.linalg as la
import scipy.optimize as sopt
import matplotlib.pyplot as plt
#from time import process_time
import math
from mpl_toolkits.mplot3d import axes3d

#t1_start = process_time()
# the objective function
def f(x):
        return 0.5*x[0]**2 + 2.5*x[1]**2

# gradient of the objective function
def g(x):
        return np.array ([x[0], 5*x[1]])
# Hessian of the objective function
# One may also use approximations as well
def B(x):
		return np.array ([[1, 0], [0, 5]])

# the quadratic model
def m(x, p):
		temp = f(x) + np.dot(g(x), p) + 0.5 * np.dot(np.dot(p, B(x)), p)
		return temp

fig = plt.figure()
ax = plt.axes(projection = '3d')

xmesh, ymesh = np.mgrid[-2:2:50j,-2:2:50j]
fmesh = f(np.array([xmesh, ymesh]))
ax.plot_surface(xmesh, ymesh, fmesh)

#plt.axis("equal")
#plt.contour(xmesh, ymesh, fmesh)

plt.show()

# define reduction ration
zero = np.array ([0, 0])
def rho(x, p) :
		a = f(x) - f(x+p)
		b = m(x, zero) - m(x, p)
		return a / b

tol = 1e-8
Max_iter = 200
delta_max = 0.5
eta = 0.25

# initial guess
y0 = np.array ([1.1, 2.2])
delta = 0.15

#print(la.norm(pk))
i = 0
#for i in range(iteration):
y = [np.array(y0)] 

while (la.norm(g(y[i])) > tol and i < Max_iter):
		temp = np.dot(np.dot(B(y[i]), g(y[i])), g(y[i]))
		if (temp < 0) :
				tau = 1.0
		else :
				tau = pow(la.norm(g(y[i])),3) / (delta * 
									 np.dot(np.dot(g(y[i]),B(y[i])), g(y[i]))) 
		# the cauchy point
		pkc = - tau * delta * g(y[i]) / la.norm(g(y[i]))

		# now starts trust region boundary determination
		rho_k = rho(y[i], pkc)
		if (rho_k < 0.25) :
				delta = 0.25 * delta
		else :
				if ((rho_k > 0.75) and (la.norm(pkc) == delta)) :
						delta = min (2 * delta, delta_max)

		y1 = y[i] + pkc
		y.append(y1)
		i += 1
		print('the',i,'th iterate is:', y[i])

print('gradient of the solution = ', g(y[i]))
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
