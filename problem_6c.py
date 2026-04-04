
# problem_6c.py - lrb - 4/2/26
# initial program used AI

import cmath

z1 = complex(3, -7)
r1 = abs(z1)
theta1 = cmath.phase(z1)

print(f"{r1=}")
print(f"{theta1=}")

z2 = complex(2, 3)
r2 = abs(z2)
theta2 = cmath.phase(z2)

print(f"{r2=}")
print(f"{theta2=}")

z3 = z1*z2

r3 = abs(z3)
theta3 = cmath.phase(z3)
print(f"{r3=}")
print(f"{theta3=}")

z4 = z1+z2

r4 = abs(z4)
theta4 = cmath.phase(z4)
print(f"{r4=}")
print(f"{theta4=}")

