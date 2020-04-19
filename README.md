# PHAS0100Assignment2

**Coursework 2 by John Duffy for PHAS0100 Research Computing with C++ 2019/2020.**

## Description

This coursework provides command line applications to implement Social Force Model for Pedestrian Dynamics (Helbing & Molnar).

The names of the applications match the coursework requirements as follows:

* sfmPartASection4App
* sfmPartASection5App
* sfmPartBSection6dApp
* sfmPartBSection6eApp
* sfmPartBSection7aApp
* sfmPartBSection7b1App
* sfmPartBSection7b2App
* sfmPartBSection7b3App

Details on how to use these programs and sample output is provided below. The output from these programs is provided as PNG visualised data or Linux terminal screenshots.

Gnuplot scripts are used to produce the PNG images. The images can be easily viewed from the command line using the Eye of GNOME (eog) command, or a similar image viewer. Details on how to install Gnuplot and eog, and how to use the provided Gnuplot scripts, are also provided below.

## Differences from Coursework Instructions

### Use of sfmTypes instead of sfmBasicTypes

During early development an issue with sfmBasicTypes (provided with the suggested coursework template) was identified. Specifically, because all of the methods of sfmBasicTypes use reference parameters, it was not possible to chain operations together, or use compound statements, using the provided vec2d, pos2d and dir2d types. This issue was susequently rectified, but in the meantime I decided to implement my own functionality as sfmTypes.

sfmTypes provides two classes, Pos2d and Vec2d. Pos2d is used for 2D positions defined by x and y values. Vec2d is used for all 2D vector quantities (e.g. velocity, accelleration, direction) defined by x and y lengths.

sfmTypes methods only support call-by-value parameters. This is a design decision which enables simple chained/compound use.

For clarity and simplicity, sfmTypes only implements the bare minium of operator/methods required.

sfmTypes provides the wrapping functionality of sfmBasicTypes, but enables Pos2d object instantiation at "world boundaries" without immediate wrapping. This removes the restriction of having to set a destination position slightly less than a "world boundary". The wrapping functionality utilises a recursive method, sfmTypes::Wrap. Full unit testing of sfmTypes is provided.

### Pedestrian Border Repulsive Force

The coursework instructions state that only the closest border should be considered when determining the Pedestrian-Border repulsive force, whereas the Helbing and Molnar paper sums all Pedestrian-Border forces.

I made the design decision to sum the top and bottom corridor Pedestrian-Border forces. The reason for this decision is that it is more aligned with the Helbing and Molnar paper, and also cleaner to implement as no test for the closest border is required.

### Use of Gnuplot instead of sfm::Visualiser

Due to time pressure to complete this coursework (due to other pressing coursework deadlines!) and prior to the availability of sfm::Visualiser, I implemented output data visualisation using Gnuplot. This visualisation tool has been used for my final submission after confirmation from Jim (by email) that no marks will be lost for doing so.

## Installation and Build Instructions

This assignment has been submitted as a zip file as required by the assignment instructions.

To install from the zip file:

```
unzip 19154676.zip
cd 19154676
mkdir PHAS0100Assignment2-Build
cd PHAS0100Assignment2-Build
cmake ../PHAS0100Assignment2
make
```
To run the tests (with verbose output):
```
ctest -V
```
The executable applications will be in the PHAS0100Assignment2-Build/bin directory.


Additionally, this assignment can be built from a private GitHub respository. The repository is private to prevent plagiarism, again, as required by the assignment instructions. To obtain the username and password for this repository please contact [John Duffy](mailto:john.duffy.19@ucl.ac.uk). To build from this repository:

```
git clone https://github.com/johnduffymsc/PHAS0100Assignment2.git
mkdir PHAS0100Assignment2-Build
cd PHAS0100Assignment2-Build
cmake ../PHAS0100Assignment2
make
```
To run the tests (with verbose output):
```
ctest -V
```
The executable applications will be in the PHAS0100Assignment2-Build/bin directory.

To install Gnuplot (on Ubuntu 18.04):

```
sudo apt install gnuplot
```

To install Eye of GNOME (on Ubuntu 18.04):

```
sudo apt install eog
```
## Useage

![](sfmPartASection4App.png)
![](sfmPartASection5App.png)
![](sfmPartBSection6dApp.png)
![](sfmPartBSection6eApp.png)
![](sfmPartBSection7aApp.png)
![](sfmPartBSection7b1App.png)
![](sfmPartBSection7b2App.png)
![](sfmPartBSection7b3App.png)




Useage
------

From the PHAS0100Assignment1-Build/bin directory:

```
lrgLeastSquaresSolver --file datafile --solver ['normal_equations'|'gradient_descent']
```
or
```
lrgLeastSquaresSolver --rand theta0 theta1 noise_mean noise_sigma --solver ['normal_equations'|'gradient_descent']
```

The executable will automatically produce a Gnuplot script in the current directory. To produce a PNG plot of the input data and resultant regression line from this script:

```
gnuplot lrgLeastSquaresSolver.plt
```

This will produce lrgLeastSquaresSolver.png in the current directory.

To easily view the plot from the command line using Eye of GNOME:
```
eog lrgLeastSquaresSolver.png
```

Examples
--------

From the PHAS0100Assignment1-Build/bin directory:

```
lrgLeastSquaresSolver --file ../../PHAS0100Assignment1/Testing/Data/TestData1.txt --solver 'normal_equations'
gnuplot lrgLeastSquaresSolver.plt
eog lrgLeastSquaresSolver.png
```


```
lrgLeastSquaresSolver --file ../../PHAS0100Assignment1/Testing/Data/TestData1.txt --solver 'gradient_descent'
gnuplot lrgLeastSquaresSolver.plt
eog lrgLeastSquaresSolver.png
```


```
lrgLeastSquaresSolver --file ../../PHAS0100Assignment1/Testing/Data/TestData2.txt --solver 'normal_equations'
gnuplot lrgLeastSquaresSolver.plt
eog lrgLeastSquaresSolver.png
```


```
lrgLeastSquaresSolver --file ../../PHAS0100Assignment1/Testing/Data/TestData2.txt --solver 'gradient_descent'
gnuplot lrgLeastSquaresSolver.plt
eog lrgLeastSquaresSolver.png
```


```
lrgLeastSquaresSolver --rand 10.0 0.0 0.0 3.0 --solver 'normal_equations'
gnuplot lrgLeastSquaresSolver.plt
eog lrgLeastSquaresSolver.png
```
