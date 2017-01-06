##CSC3221 Programming for Games

###Overview
Abstract classes and inheritance in C++ and collision detection in computer games.

###Specification
An important topic in many computer games is determining when 2 object collide with one another.
Games looks poor if a car appears to drive into a wall or appear to collide with thin air. Physics
Engines devote considerable effort to solving this problem. In this Project we will start to consider
this issue
Implement an abstract base class Shape to represent moving objects in the game. Derive classes
Circle and Square from Shape with appropriate information to store the positions on a flat
2_D surface. The classes should provide methods to move the position of the shape by a given
amount and a method to detect when two shapes overlap. You will need to deal with overlap of 2
circles, 2 squares and circle and square separately (the latter is difficult and will need some research.
A basic but acceptable solution is to embed the square within a circle of the appropriate radius and
use it for the overlap algorithm).
Write a test game program that creates several shapes and stores them in an array or list or other
data structure of your choosing. The program should then iterate through the data, move each
shape by a small random amount (but keeping them within a grid of a given size) and check to see if
there are any shapes overlapping. If there are, it should output the details about the overlapping
shapes (you do not need to deal with the problem of disentangling overlapping shapes - that is a
much trickier problem in game design!). It should then remove the overlapping shapes from the data
structure and continue the game until at most one shape remains. NO GRAPHICAL OUTPUT is
expected or required and providing some will not score any extra marks (this isn’t a graphics
course!) 

###Output
```javascript
***********************
** COLLISON DETECTED **

CIRCLE
Position[Top: 1293.77 , Right: 1946.12 , Bottom: 1285.41 , Left: 1937.75]
Diameter[8.36375]
Radius[4.18188]
Origin[X: 1941.94 , Y: 1289.59]

CIRCLE
Position[Top: 1307.62 , Right: 1944.47 , Bottom: 1292.54 , Left: 1929.38]
Diameter[15.0835]
Radius[7.54173]
Origin[X: 1936.93 , Y: 1300.08]

SHAPES LEFT IN VECTOR: 30
***********************


***********************
** COLLISON DETECTED **

CIRCLE
Position[Top: 1509.99 , Right: 1992.72 , Bottom: 1498.77 , Left: 1981.49]
Diameter[11.2217]
Radius[5.61083]
Origin[X: 1987.1 , Y: 1504.38]

CIRCLE
Position[Top: 1500.47 , Right: 1994.47 , Bottom: 1494.95 , Left: 1988.96]
Diameter[5.51317]
Radius[2.75658]
Origin[X: 1991.72 , Y: 1497.71]

SHAPES LEFT IN VECTOR: 28
***********************


***********************
** COLLISON DETECTED **

SQUARE
Position[Top: 1071.13 , Right: 1836.36 , Bottom: 1061.61 , Left: 1826.84]
Length[9.51506]
Origin[X: 1831.6 , Y: 1066.37]

CIRCLE
Position[Top: 1063.6 , Right: 1840.94 , Bottom: 1057.32 , Left: 1834.65]
Diameter[6.28544]
Radius[3.14272]
Origin[X: 1837.8 , Y: 1060.46]

SHAPES LEFT IN VECTOR: 26
***********************


***********************
** COLLISON DETECTED **

SQUARE
Position[Top: 665.917 , Right: 1793.32 , Bottom: 658.017 , Left: 1785.42]
Length[7.90048]
Origin[X: 1789.37 , Y: 661.967]

SQUARE
Position[Top: 672.502 , Right: 1808.62 , Bottom: 656.951 , Left: 1793.07]
Length[15.5504]
Origin[X: 1800.85 , Y: 664.727]

SHAPES LEFT IN VECTOR: 24
***********************


***********************
** COLLISON DETECTED **

CIRCLE
Position[Top: 1904.49 , Right: 1904.36 , Bottom: 1893.27 , Left: 1893.14]
Diameter[11.2212]
Radius[5.6106]
Origin[X: 1898.75 , Y: 1898.88]

SQUARE
Position[Top: 1899.73 , Right: 1906.87 , Bottom: 1894.21 , Left: 1901.34]
Length[5.52232]
Origin[X: 1904.11 , Y: 1896.97]

SHAPES LEFT IN VECTOR: 22
***********************


***********************
** COLLISON DETECTED **

CIRCLE
Position[Top: 1368.68 , Right: 354.086 , Bottom: 1351.66 , Left: 337.067]
Diameter[17.018]
Radius[8.50902]
Origin[X: 345.577 , Y: 1360.17]

CIRCLE
Position[Top: 1359.2 , Right: 339.4 , Bottom: 1345.42 , Left: 325.616]
Diameter[13.7843]
Radius[6.89215]
Origin[X: 332.508 , Y: 1352.31]

SHAPES LEFT IN VECTOR: 20
***********************


***********************
** COLLISON DETECTED **

CIRCLE
Position[Top: 635.11 , Right: 239.235 , Bottom: 616.323 , Left: 220.449]
Diameter[18.786]
Radius[9.39299]
Origin[X: 229.842 , Y: 625.716]

CIRCLE
Position[Top: 634.983 , Right: 221.371 , Bottom: 625.478 , Left: 211.867]
Diameter[9.50453]
Radius[4.75227]
Origin[X: 216.619 , Y: 630.23]

SHAPES LEFT IN VECTOR: 18
***********************


***********************
** COLLISON DETECTED **

SQUARE
Position[Top: 243.81 , Right: 467.074 , Bottom: 230.492 , Left: 453.755]
Length[13.3192]
Origin[X: 460.414 , Y: 237.151]

CIRCLE
Position[Top: 226.407 , Right: 453.069 , Bottom: 221.305 , Left: 447.967]
Diameter[5.10163]
Radius[2.55081]
Origin[X: 450.518 , Y: 223.856]

SHAPES LEFT IN VECTOR: 16
***********************


***********************
** COLLISON DETECTED **

SQUARE
Position[Top: 73.3295 , Right: 388.875 , Bottom: 58.0498 , Left: 373.594]
Length[15.2794]
Origin[X: 381.235 , Y: 65.6897]

CIRCLE
Position[Top: 57.804 , Right: 368.891 , Bottom: 52.0535 , Left: 363.14]
Diameter[5.74984]
Radius[2.87492]
Origin[X: 366.015 , Y: 54.9287]

SHAPES LEFT IN VECTOR: 14
***********************


***********************
** COLLISON DETECTED **

SQUARE
Position[Top: 1862.62 , Right: 1278.38 , Bottom: 1847.14 , Left: 1262.9]
Length[15.4772]
Origin[X: 1270.64 , Y: 1854.88]

CIRCLE
Position[Top: 1874.94 , Right: 1264.27 , Bottom: 1858.07 , Left: 1247.4]
Diameter[16.8706]
Radius[8.43532]
Origin[X: 1255.83 , Y: 1866.5]

SHAPES LEFT IN VECTOR: 12
***********************


***********************
** COLLISON DETECTED **

SQUARE
Position[Top: 1605.06 , Right: 1443.54 , Bottom: 1598.37 , Left: 1436.85]
Length[6.69286]
Origin[X: 1440.19 , Y: 1601.72]

CIRCLE
Position[Top: 1611.78 , Right: 1467.12 , Bottom: 1593.63 , Left: 1448.97]
Diameter[18.1529]
Radius[9.07643]
Origin[X: 1458.05 , Y: 1602.7]

SHAPES LEFT IN VECTOR: 10
***********************


***********************
** COLLISON DETECTED **

SQUARE
Position[Top: 1859.43 , Right: 943.553 , Bottom: 1850.33 , Left: 934.451]
Length[9.10077]
Origin[X: 939.002 , Y: 1854.88]

CIRCLE
Position[Top: 1882.06 , Right: 949.826 , Bottom: 1863.93 , Left: 931.704]
Diameter[18.1208]
Radius[9.06041]
Origin[X: 940.765 , Y: 1873]

SHAPES LEFT IN VECTOR: 8
***********************


***********************
** COLLISON DETECTED **

SQUARE
Position[Top: 1081.18 , Right: 161.924 , Bottom: 1070.76 , Left: 151.499]
Length[10.4237]
Origin[X: 156.712 , Y: 1075.97]

CIRCLE
Position[Top: 1089.05 , Right: 170.943 , Bottom: 1078.83 , Left: 160.716]
Diameter[10.2255]
Radius[5.11277]
Origin[X: 165.83 , Y: 1083.94]

SHAPES LEFT IN VECTOR: 6
***********************


***********************
** COLLISON DETECTED **

SQUARE
Position[Top: 1527.25 , Right: 1709.12 , Bottom: 1517.13 , Left: 1699]
Length[10.1244]
Origin[X: 1704.06 , Y: 1522.19]

SQUARE
Position[Top: 1533.2 , Right: 1699.02 , Bottom: 1524.88 , Left: 1690.71]
Length[8.31385]
Origin[X: 1694.87 , Y: 1529.04]

SHAPES LEFT IN VECTOR: 4
***********************


***********************
** COLLISON DETECTED **

SQUARE
Position[Top: 729.169 , Right: 48.8051 , Bottom: 714.753 , Left: 34.3916]
Length[14.416]
Origin[X: 41.5984 , Y: 721.961]

CIRCLE
Position[Top: 717.65 , Right: 30.4217 , Bottom: 711.359 , Left: 24.1355]
Diameter[6.28681]
Radius[3.14341]
Origin[X: 27.2786 , Y: 714.505]

SHAPES LEFT IN VECTOR: 2
***********************


***********************
** COLLISON DETECTED **

SQUARE
Position[Top: 141.728 , Right: 1111.72 , Bottom: 135.992 , Left: 1105.99]
Length[5.73382]
Origin[X: 1108.85 , Y: 138.86]

SQUARE
Position[Top: 139.071 , Right: 1106.04 , Bottom: 127.776 , Left: 1094.76]
Length[11.2844]
Origin[X: 1100.4 , Y: 133.424]

SHAPES LEFT IN VECTOR: 0
***********************

Game finished with 0 shape(s) left...
```