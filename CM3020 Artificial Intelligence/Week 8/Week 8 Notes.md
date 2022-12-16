# Deciding on the parameters and their range

### Get the list of the parameters we want

* The links
  * Geometry
    * Length
    * Shape
    * etc
* Joints
* Control system
Links
0 link-shape        -> cylinder / box
1 link-length       -> 0 - 1
2 link-radius       -> 0 - 1
3 link-recurrence   -> 1 - 4
4 link-mass         -> 0 - 1

Joints
5 joint-type        -> revolute / fixed
6 joint-parent      -> 0 - number of links
7 joint-axis-xyz    -> 3 options [1, 0, 0] or [0, 1,  0] or [0, 0, 1]
8 joint-origin-rpy-1    -> 0 - 2pi
9 joint-origin-rpy-2    -> 0 - 2pi
10 joint-origin-rpy-3   -> 0 - 2pi
11 joint-origin-xyz-1     -> 0 - 1
12 joint-origin-xyz-2     -> 0 - 1
13 joint-origin-xyz-3     -> 0 - 1

Control
14 control-waveform -> sine/pulse/ramp
15 control-amp      -> 0 - 0.25
16 control-freq     -> 0 - 1

# Test-driven development

> You may not write production code unless you've first written a failing unit test.

> You may not write more of a unit test than is sufficient to fail.

> You may not write more production code than is sufficient to make the failing unit test pass.

# Genome spec

`gene[spec["link-length"]["ind"]]`

And also a scalar

`get_scaled_genome_values`

# Convert from flat genes to a graph - Algorithm

# Convert to XML

# Fixing position of children

# Totor test script

* create creature
* write XML to disk
* load XML
* iterate over motors, calling p.setJointMotorControl2 with p.VELOCITY_CONTORL, targetVelocity, force
