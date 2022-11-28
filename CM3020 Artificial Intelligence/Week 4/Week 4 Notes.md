# DQN Implementation
We'll use python to implement the network

An episode is an instance of a game run for a number of actions (e.g. 10000) or until the game ends.

https://github.com/keras-team/keras-io/blob/master/examples/rl/deep_q_network_breakout.py

# What does the network look like?

The size of the screen is resized to 84 by 84 before the screenshots enter the network.

The input layers could be thought to have a 3D prism 84x84x3

# Convolution layers
### First convolution layer
`layer 1 = layers.Conv2D(32, 8, strides=4, activation="relu")(inputs)`

32 filters are applied
Size of the filter is 8 by 8 pixels.
The stride is 4, meaning it skips 4 pixels each time it processes, this results in a (20, 20, 32), where we have 32 images of size 20x20, one image for each filter.

### Second convolution layer
`layer2 = layers.Conv2D(64, 4, strides=2, activation="relu")(inputs)`

This layers acts on the result of the previous layer
64 filters, filters of size 4x4 pixels, only skips 2 pixels. This results in a size of (9, 9, 64).

### Third convolution layer
`layer3 = layers.Conv2D(64, 3, strides=1, activation="relu")(inputs)`

This refults to (7, 7, 64). 64 images of 7x7 pixels

# Flatten layer
`layer4 = layers.Flatten()(layer3)`
Turns the 2D tensors into a single layer (or flat) element. In this case 7 times 7 time 64 (7x7x64=3136)

# Dense layer
`layer5 = layers.Dense(512, activation="relu")(layer4)`
In the example, 3136 turns into 512 nodes that is connected with each other. This means that each node contributes to the activation of the next layer of every node.

# Dense Layer_1
`action = layers.Dense(num_action, activation="relu")(layer5)`
Take the result of the previous layer to provide with outputs, which in Breakaway is 4 (possible actions)

At the end we get 4 simple outputs from the Q function, one for each of the moves, which represent the values of the possible actions.

`return keras.Model(inputs=inputs, outputs=action)`

# DQN loss function and training
We normally we have a ground truth such as labeled pictures, this is not the case with Q learning.

### To sample from the replay buffer
We choose 32 items from the replay buffer

`indices = np.random.choice(range(len(done_history)), size=batch_size)`

The current state (s)

`state_sample = np.array([state_history[i]) for i in indices)`

The next state (s-)

`state_next_sample = np.array([state_next_history[i] for i in indices])`

The reward r

`rewards_sample = [rewards_history[i] for i in indices]`

The action a
`action_sample = [action_history[i] for i in indices]`

We then calculate the future reward using the Q- network (model target)

`future_rewards = model_target.predict(state_next_sample)`

We then use the gamma value

`updated_q_values = rewards_sample + gamma * tf.reduce_max(future_rewards, axis=1)`

We calculate the reward on the model

`q_values = model(state_sample)`

We calculate the different between the predicted rewards

`loss = loss_function(updated_q_values, q_action)`

# Watch DQN playing Breakwall
The size of the replay buffer needs to be big, this is an initial limitation (problem). The keras script reduced the usual size to about 12% of the original requirements.

The graph shows the average running score achieved across multiple episodes.

Training is resource intensive, but the inference (running the model) is fast and requires little ram.

# Lab
I was able to follow all instructions except training the model with atari_py, there was an error saying

`'C:\Users\gofor\myvenv\lib\site-packages\atari_py\ale_interface\ale_c.dll' (or one of its dependencies). Try using the full path with constructor syntax.`

I looked for the file online and downloaded it, but even then still got the same error.
