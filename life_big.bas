 5 REM 10/18/26 - made area twice as big
 
 7 dim customScreen as long
 8 customScreen = _NEWIMAGE(1200, 900, 256) ' Creates an 800x600 screen with 256 colors
 9 screen customScreen

10 Cls
20 Print "LIFE - 10/18/26"
30 Print: Print: Print
40 Dim A(80, 42), B$(42)
50 H = 1
60 Print "Enter a pattern (type END when finished):"
70 Input B$(H)
75 If B$(H) = "RANDOM" Then GoTo 900
80 If B$(H) = "END" Then H = H - 1: GoTo 120
90 If Len(B$(H)) > W Then W = Len(B$(H))
100 H = H + 1
110 GoTo 70
120 XMIN = Int(40 - W / 2): YMIN = Int(21 - H / 2): XMAX = XMIN + W: YMAX = YMIN + H
130 For Y = 1 To H: For X = 1 To W
        140 If Mid$(B$(Y), X, 1) = "." Then GoTo 160
        150 A(X + XMIN, Y + YMIN) = 1
160 Next X: Next Y: Cls
170 RIGHT = 1: LEFT = 80: TOP = 42: BOTTOM = 1
180 For Y = YMIN To YMAX: Locate Y, XMIN: For X = XMIN To XMAX
        190 If A(X, Y) = 11 Then A(X, Y) = 1: If A(X, Y) = 10 Then A(X, Y) = 0
        200 If A(X, Y) = 1 Then Print "*";: GoTo 220
        210 Print " ";: GoTo 260
        220 If X > RIGHT Then RIGHT = X
        230 If X < LEFT Then LEFT = X
        240 If Y < TOP Then TOP = Y
        250 If Y > BOTTOM Then BOTTOM = Y
260 Next X: Next Y
270 For Y = YMAX + 1 To 42: Print: Next Y
280 Print "TIME"; T
285 Sleep 1
290 XMIN = LEFT: YMIN = TOP: XMAX = RIGHT: YMAX = BOTTOM
300 If XMIN < 3 Then XMIN = 3
310 If YMIN < 3 Then YMIN = 3
320 If XMAX > 78 Then XMAX = 78
330 If YMAX > 40 Then YMAX = 40
340 T = T + 1: XMIN = XMIN - 1: YMIN = YMIN - 1: XMAX = XMAX + 1: YMAX = YMAX + 1
350 For Y = YMIN To YMAX: For X = XMIN To XMAX
        360 NBRS = A(X - 1, Y - 1) + A(X, Y - 1) + A(X + 1, Y - 1) + A(X - 1, Y)
        370 NBRS = Int(NBRS / 10)
        380 NBRS = NBRS + A(X + 1, Y) + A(X - 1, Y + 1) + A(X, Y + 1) + A(X + 1, Y + 1)
        390 NBRS = NBRS - 10 * Int(NBRS / 10)
        400 A(X, Y) = A(X, Y) - 10 * Int(A(X, Y) / 10)
        410 A(X, Y) = 10 * A(X, Y)
        420 If NBRS = 3 Then GoTo 450
        430 If NBRS <> 2 Then GoTo 460
        440 If A(X, Y) <> 10 Then GoTo 460
        450 A(X, Y) = A(X, Y) + 1
460 Next X: Next Y
470 GoTo 180
480 End
900 Randomize
910 Print "Enter density:"
920 Input D
930 For Y = 2 To 41: For X = 2 To 79
        940 If Rnd(X + Y) < D Then A(X, Y) = 1
950 Next X: Next Y: Cls
960 XMIN = 3: YMIN = 3: XMAX = 78: YMAX = 40
970 GoTo 180

