
Point Cloud - Intensity Viewer
=================================

# Objective of Program
The objective of this program is to allow visualisation of 3D solid volume fraction distributions (ratio of volume of substrate to domain volume).
Solid Volume Fractions are commonly found in the fields of Chemical Engineering and Mechanical Engineering.

# Motivation
The motivation of this program is to visualise results found from my honours thesis on 3D vision based reconstruction. This thesis aims to develop relationships
with respect to solid volume fractions found within particle curtains to aim in the validation of Computational Fluid Dynamics (CFD) models.

# Details:

## Language and Header Requirements
This program makes extensive use of the C++ programming language and OpenGL libraries.
The graphical front end (not sure yet) has been chosen to maximise cross platform ability.

## Interpretation of Results
The default colour of the particles is white/gray to give adequate contrast to the background where the 'alpha' in the RGBA format will contrast the resulting solid volume fration within the file.
