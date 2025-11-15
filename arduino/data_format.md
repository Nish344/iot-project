# Arduino → Laptop Data Format (API Contract)

Transport: USB Serial  
Baud Rate: 9600  
Encoding: ASCII  
End-of-line: newline `\n`

## Line Format

angle,distance

Example:
45,120

## Rules

- `angle` is 0–180 degrees
- `distance` is:
  - -1 (invalid or <10cm)
  - 1–400 cm (valid)
- One reading per angle
- No extra text, spaces, units, or labels

Correct:
30,105

Incorrect:
Angle = 30 degrees, distance = 105 cm
