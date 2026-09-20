import numpy as np


def gaussian_elimination(A, b):
    """
    Gaussian elimination with partial pivoting.

    The function is intentionally buggy.
    """

    A = A.astype(float).copy()
    b = b.astype(float).copy()

    n = len(b)

    # Forward elimination
    for k in range(n - 1):

        # Partial pivoting
        pivot_row = k + np.argmax(np.abs(A[k:, k]))

        if pivot_row != k:
            A[[k, pivot_row], :] = A[[pivot_row, k], :]

        # Eliminate entries below the pivot
        for i in range(k + 1, n):

            factor = A[i, k] / A[k, k]
            b[i] = b[i] - factor * b[k + 1]
            A[i, k:] = A[i, k:] - factor * A[k, k:]

    # Back substitution
    x = np.zeros(n)

    for i in range(n - 1, -1, -1):

        s = np.dot(A[i, i + 1:n - 1], x[i + 1:n - 1])

        x[i] = (b[i] - s) / A[i, i]
    return b


# Test problem

A = np.array([
    [2.,  1., -1.],
    [4.,  5., -3.],
    [-2., 5., -2.]
])

b = np.array([
    3.,
    7.,
    -1.
])

x = gaussian_elimination(A, b)

print("Computed solution:")
print(x)

print("\nResidual:")
print(A @ x - b)