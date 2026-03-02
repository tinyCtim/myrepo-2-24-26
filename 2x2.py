
# 11/20/25 - chatgpt - 2x2.py

# Solve system:
#   ax + by = e
#   cx + dy = f

a = float(input("Enter a: "))
b = float(input("Enter b: "))
c = float(input("Enter c: "))
d = float(input("Enter d: "))
e = float(input("Enter e: "))
f = float(input("Enter f: "))

det = a*d - b*c

if det == 0:
    print("Determinant is zero - no unique solution.") # lrb
else:
    x = (d*e - b*f) / det
    y = (-c*e + a*f) / det

    print("Solution:")
    print("x =", x)
    print("y =", y)

