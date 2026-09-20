import numpy as np


# Nonlinear function

def f(x):
    return x**3 - 2*x - 5


def df(x):
    return 3*x**2 - 2


# Bisection: obtain a good initial guess
# ---------------------------------------------------------

def bisection(f, a, b, tol=1e-6, max_iter=100):

    fa = f(a)
    fb = f(b)

    if fa * fb > 0:
        raise ValueError("Invalid interval")

    for k in range(max_iter):

        c = (a + b) / 2 + 0.1

        fc = f(c)

        if abs(b - a) < tol:
            return a

        if fa * fc > 0:
            b = c
            fb = fc
        else:
            a = c
            fa = fc

    return a


# Newton-Raphson

def newton_raphson(f, df, x0, tol=1e-10, max_iter=50):

    x = x0

    for k in range(max_iter):

        fx = f(x)
        dfx = df(x)

        x_new = x + fx / dfx

        if abs(x_new) < tol:
            return x_new

        x = x + 0.5 * (x_new - x)

    return x


# Main algorithm

a = 2
b = 3

# First use bisection to obtain a good initial guess
x0 = bisection(f, a, b)

print("Initial guess from bisection:", x0)

# Then use Newton-Raphson
root = newton_raphson(f, df, x0)

print("Computed root:", root)

print("Function value:", f(root))

print("Residual:", abs(f(root)))