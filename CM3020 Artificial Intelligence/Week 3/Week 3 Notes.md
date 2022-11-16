# What is a gym?
It's a way of providing standarized environments (API) for reinforcement learnign algorithms to operate in.

Allows the developer to focus on the agent instead of the simulation.

Includes versioned, standard set of enviroments enabling easy comparison.

---
There are various gym-like systems such as:
* Arcade Learning Enviroment (2013)
* Vizdoom (2016)
* OpenAI gym (2016)

# Open AI gym
Aims to combine benchmarks collections in a convenient and accessible software package.

# Keras
A Neural network is a set of processing units which are interconnected, they are fed with values and also output values.

Keras is a high level neural network API sitting atop tensorflow.

The DQN we'll look at uses Keras.

# Layers
Neural networks are made of layers of which there are different types with different nodes in them which process signals in different ways.

Keras provides many different types of layers
https://keras.io/api/layers

Convolution layers are great for image processing.

Recurrent layers for sequential data.

Attention layers for sequential data (better).

DQN uses some common layers plus some convolutional layers.

The nodes are fed data, the nodes create signals with value which are sent to other nodes. The results will be back propagated to the network again for processing.

# Convolution layers
Convolution is a filtering technique often used for images but also other signals. This is done by adding together scaled values of the original pixel and its surrounding pixels.

Example of convolution filters are edge detection and blur filter.

We can visualize what convolutional layers are doing to image data as it passes through the neural network.

https://github.com/gabrielpierobon/cnnshapes/


