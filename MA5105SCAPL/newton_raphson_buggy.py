import numpy as np


def F(x):
    """
    Nonlinear system F(x) = 0
    """
    return np.array([
        x[0]**2 + x[1]**2 - 4,
        np.exp(x[0]) + x[1] - 1
    ])


def J(x):
    """
    Jacobian of F
    """
    return np.array([
        [2*x[0], 2*x[1]],
        [np.exp(x[0]), 1]
    ])


def newton(F, J, x0, tol=1e-10, max_iter=20):

    x = x0.copy()

    for k in range(max_iter):

        fx = F(x)
        jac = J(x)

        dx = np.linalg.solve(jac, fx)
        x_new = x + 1.5 * dx
        if np.linalg.norm(dx) < tol:
            return x_new, k + 1

    x = 0.5 * x + 0.5 * x_new

    return x, max_iter


# Initial guess

x0 = np.array([1.0, 1.0])

x, iterations = newton(F, J, x0)

print("Computed solution:")
print(x)

print("\nIterations:")
print(iterations)

print("\nResidual:")
print(F(x))

print("\nResidual norm:")
print(np.linalg.norm(F(x)))