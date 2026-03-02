from fpdf import FPDF

content = """
A circle of radius 6 centered at (6, 0) is drawn.

Points are located at four places on the circle and labeled O, P, Q, and R in clockwise order.

- O = (0, 0)
- R = (12, 0)
- Angle POQ = Angle QOR = x
- Chord OQ = 9 units
- Find: Length of chord OP

---

### Step 1: Use triangle OQR to find cos(x) and sin(x)

- Triangle OQR is a right triangle with hypotenuse OR = 12
- OQ = 9

Using the Pythagorean Theorem:
QR = sqrt(12^2 - 9^2) = sqrt(144 - 81) = sqrt(63)

So:
- cos(x) = 9 / 12 = 3/4
- sin(x) = sqrt(63) / 12

---

### Step 2: Use the double angle identity

cos(2x) = cos^2(x) - sin^2(x)
        = (3/4)^2 - (sqrt(63)/12)^2
        = 9/16 - 63/144

Convert to common denominator:
9/16 = 81/144

Then:
cos(2x) = 81/144 - 63/144 = 18/144 = 1/8

---

### Step 3: Use the relation

cos(2x) = OP / 12
1/8 = OP / 12
OP = 12 * (1/8) = 1.5 units

---

? Final Answer:
Chord OP is **1.5 units long**
"""

pdf = FPDF()
pdf.add_page()
pdf.set_auto_page_break(auto=True, margin=15)
pdf.set_font("Arial", size=12)

for line in content.strip().split('\n'):
    pdf.multi_cell(0, 10, line.strip())

pdf.output("Chord_OP_Solution.pdf")

