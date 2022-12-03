# Creatures case study
Nature has created solutions for different problems in life design.
Evolutionary theory and genetics.

### Week 1
* What is bio-inspired computing?
* Evolution theory
* Intro to evolving creatures

### Week 2
* Starting coding
* URDF files (used in robotics - ROS)
* Joints, links and motors

### Week 3
* Genetic encoding - Converting random numbers into recursive, moveable creatures

### Week 4
* Fitness functions (evaluate) and population models
* Complete genetic algorithm that can evolve creatures

### Week 5
* What happened after Sims?
* State-of-the-art evolving morphology

# Week 1
Objectives
* Explain the key features of a genetic algorithm and how they can be used to address a given problem
* Compare and contrast examples of artificial life systems
* Develop an argument about the potential of evolutionary computing

### Bio-inspired
Looking at the algorithms and functions in the natural world and deriving knowledge from them.

AI is bio-inspired computing as it's emerged as a main field in AI research study.

### Cyberntics
> The science of control and communication in the animal and the machine - Weiner 1948

From the Greek word for steersman

> Co-ordination, regulation and control will be its themese, for these are the greatest biological and practical interest - Ashby, 1961

### Connectionism
> The perceptron is a minimally constrained 'nerve net' consisting of logically simplified neural elements, which has been shown to be capable of learning to discriminate and to recognize perceptual patterns - F. Rosenblatt

### Artificial life
> Life as it could be

### Genetic algorithms
> Iterate on solutions to improve them

# Evolution theory
Evolution through natural selection:
1. Population
* Variation
* Heredity
2. Selection
3. Breeding

The genotype encodes the range of characteristics of the individual.

DNA = Nature

Enviroment = Nurture

The phenotype is the actual individual that manifests in the world.

The environment applies selective pressure to the phenotypes

Fit phenotypes are more likely to survive to reproduce.

The  underlying genotypes provide heredity

# Artificial evolution and genetic algorithms

John Holland from U. Michigan is considered the inventor of genetic algorithms. Adaptation in natural and artificial systems

>"A genetic algorithm is a probabilistic search procedure designed to work on large spaces involving states that can be represented by strings" -Goldberd, David & Holland, John

probabilistic search - Selection
states - Phenotype - The 'real' representation of the individual
strings - Genotype - How we describe the solutions

What is it for?

A genetic algorithm is a search algorithm that looks for the solution to a problem.

We define space as the space of possible solutions to a problem. So if we can search the space, we can find a solution to a problem.

e.g. The ideal shape of a plane wing. Settings to reduce power consumption. The most efficient robot form for walking.

We select two parents based on their fitness.
We combine parts of the two parents in a crossover method and create a mutation on the child solution and evaluate again.

Summary
* Genetic algorithm
* Encoding: genotype
* Expression: phenotype
* Selection: fitness function
* Breeding

# Why do generic algorithms work?
>The question that most people who are new to the field of genetic algorithms ask at this point is why such a process should do anything useful. -Whitley, Darrel

### Local and global maxima
If there are multiple solutions with some better than others, a close enough solution that increases in performance will only reach the local maxima of that solution, never the global maxima or overall best solution.

### Hyperplane sampling
Genetic algorithms aim to solve this by the use of:
* Hyperplane sampling: being able to break a solution into components and to test those components in multiple combinations with other components

### Schema theorem
It's the idea of describing a pattern, like a simple regular expression. e.g. 1**0 any strings that start with a 1 and end with a 0 would match the schema.

The hyperplane covers the set of coordinates matching the schema.

### Implicit parallelism
* Using a population model to maintain, optimize and even recombine multiple solutions at the same time.

### Computational parallelism
Genetic algorithms lend themselves to being computed in parallel, e.g. assessing multiple solutions at the same time on a multi-processor system.

# Karl Sims creatures
What is evolving morphology

## Evolving morphology

## Sims' creatures

## Morphology

## Control
In order to move the creatures we need a control system.
The control system maps from inputs to actuators.
Simulating creatures
> "Dynamics simulation is used to calculate the movement of creatures resulting from their interaction with a virtual three-dimensinal world"
 
In Sims' simulation, a Connection Machine CM-5 was used, the 1993 world's fastest computer.

## Fitness function
> "In this world, virtual creatures evolved by optimizing for a specific task or behavior"
Competition can also be used.

## Mutation
> "Offspring are generated from the surviving creatures by copying and combining their directed graphs genotypes. When these graphs are reproduced they are subjected to probabilistic variation or mutation, so the corresponding phenotypes are similar to their parents but have been altered or adjusted in random ways."

## Results
> "The walking fitness measure also produced a surprising number of simple creature that could shuffle or hobble along at fairly high speeds. Some walk with lizard-like gaits using the corners of their parts. Some simply wag an appendage in the air to rock back and forth in just the right manner to move forward"
> 