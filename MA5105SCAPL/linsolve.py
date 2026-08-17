
# This is my 2 X 1 Vector class 
# I will take two inputs 
# it twill have one init mehtod and 
# one method to print its component values 

class TBTVEC:

    def __init__(self, x1, x2):
        self.x1 = x1
        self.x2 = x2

    def __str__(self):
        return "("+str(self.x1)+","+str(self.x2)+")"


V1 = TBTVEC(1.1, 1.2)

print(V1)

# This is my 2 X 2 matrix class 

class TBTMAT:

    def __init__(self, x11, x12, x21, x22):
        self.x11 = x11
        self.x12 = x12
        self.x21 = x21
        self.x22 = x22

    def __str__(self):
            return "\n"+str(self.x11)+","+str(self.x12)+"\n"+str(self.x21)+","+str(self.x22)

    def det (self):
        return self.x11 * self.x22 - self.x21 * self.x12

    def inv(self):

        determinant = self.det()
        if abs(determinant) < 1e-10:
            print (" singular matrix") 
            return None
        else:
            obd = 1.0 / determinant 
            return TBTMAT(self.x22 * obd, - self.x12 * obd, -self.x21 * obd, self.x11 * obd) 


M1 = TBTMAT(1.1, 1.2, 1.3, 1.4)
print(M1)
print(M1.det())

M2 = M1.inv()

print(M2)

class TBTLSSOLVE:
    def __init__(self, V, M):
        self.V = V
        self.M = M

    def solve(self):

        return 

