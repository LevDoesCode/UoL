# Key components in the creatures system
Genetic Algorithms (GA) has 3 phases
1. Varied population with heredity
2. Some sort of test (selection)
3. Variations of the winners/survivors (breeding)

> The most creative and challenging parts of programming a GA are usually the problem specific aspects - Hervey, Inman (2009)

We will roughly follow Sims, but with simplifications

We'll use the URDF format

We don't have a CM-5 handy, or access to the original Sims code, we'll use an alternative physics engine.

### Genotype
We'll follow Sims somewhat, but with simplifications.

### Fitness function
How far does it move?
But... they are going to cheat!

### Population model
Roulette wheel selection etc.

### Compute in parallel
We can gain a lot of speed by computing in parallel

### Technology stack
* Python
* Pybullet
* URDF format

# Introduction to pybullet
### What is bullet
It's a rigid and soft body physics engine originally developed by Erwin Coumans.

### Demo
It's written in C and C++. It's been translated to JS in ammo.js
http://kripken.github.io/ammo.js/

### Install pybullet
* Create the virtual env and install pybullet

# The URDR file format

Stands for Unified Robot Description Format

It's an XML-based file format for building robot models, including their motors and other dynamics.

To generate a model programmatically is too complex when the problem has a currently viable solution.

Using URDF makes it easier to share the models.

Links are the parts, joints are the points where the parts meet and interact.

# Moving a URDF robot

There are 3 types of joints available in pybullet, though the URDF standard supports more. These are:
* JOINT_REVOLUTE: rotate
* JOINT_PRISMATIC: move along an axis
* JOINT_FIXED: does not move

# Mving a preset robot
Joint info
* getNumJoints
* getJointInfo
