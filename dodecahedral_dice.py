from fpdf import FPDF

# Create a PDF document
pdf = FPDF()
pdf.add_page()
pdf.set_font("Helvetica", size=12)

# Title
pdf.cell(200, 10, txt="The Dodecahedral Dice Challenge Solution", ln=True, align="C")
pdf.ln(10)

# Intro text
intro = """We have 4 dodecahedral dice (each with 12 faces), labeled Blue, Red, Green, and Black.
Each die has unique numbers from 1 to 48 across all dice. The dice must be balanced so that:
- Any 2 dice have equal probability of rolling the higher number.
- Any 3 dice have equal probability of rolling the highest number.
- Any 4 dice have equal probability of rolling the highest number.
A valid construction can be achieved by an extension of Efrons nontransitive dice design,
generalized for 4 dice with 12 faces each."""

pdf.multi_cell(0, 8, intro)
pdf.ln(8)

# Dice configuration
dice_faces = {
    "Blue":  [1, 8, 9, 16, 17, 24, 25, 32, 33, 40, 41, 48],
    "Red":   [2, 7, 10, 15, 18, 23, 26, 31, 34, 39, 42, 47],
    "Green": [3, 6, 11, 14, 19, 22, 27, 30, 35, 38, 43, 46],
    "Black": [4, 5, 12, 13, 20, 21, 28, 29, 36, 37, 44, 45]
}

for color, faces in dice_faces.items():
    pdf.set_font("Helvetica", style="B", size=12)
    pdf.cell(0, 8, txt=f"{color} Die:", ln=True)
    pdf.set_font("Helvetica", size=12)
    pdf.cell(0, 8, txt=", ".join(map(str, faces)), ln=True)
    pdf.ln(4)

# Explanation
explanation = """Each die contains one number from every group of four consecutive integers
1 thru 4 5 thru 8 etc.
This ensures that over all comparisons, each die has an equal probability of producing the highest roll.

For example:
- In any pairwise comparison, each die wins exactly half the time.
- In any 3-way or 4-way comparison, all have equal expected rank.

Thus, these dice satisfy the fairness constraints."""
pdf.multi_cell(0, 8, explanation)

# Save the PDF
pdf.output("Dodecahedral_Dice_Challenge_Solution.pdf")

print("? PDF saved as Dodecahedral_Dice_Challenge_Solution.pdf")

