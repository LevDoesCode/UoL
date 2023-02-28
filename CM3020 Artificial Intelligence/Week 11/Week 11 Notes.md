# Learning objectives
* Describe the plan an dkey steps for teh AI and creativity case study.
* Using examples form the literature, explain what a generative system is.
* Implement a generative system that can learn a model of a text document and use it to generate more text.

# Introductions to generative systems
### What is a generative system?

### Passive tools
A tool that represents the user's input directly and stops when the input stops.

### Active tools
A tool that employs the user's input and adds to it in order to complete a determined or related pseudo-random task.

Examples
* SketchRNN (Google Magenta) [Link 1](https://magenta.tensorflow.org/assets/sketch_rnn_demo/index.html) [Link 2](https://magic-sketchpad.glitch.me/)
* Dall-e by Open AI [Link 1](https://openai.com/research/dall-e)
* Dall-e2 [Link 1](https://openai.com/product/dall-e-2)
* Conway's game of life [Link 1](https://copy.sh/life/?pattern=10enginecodership)

### Taxonomy
Boden and Edmonds 11 definitions, here are 3:

2. C-art uses computers as part of the art-making process.
5. G-art works are generated, at least in part, by some process that is not under the artist's direct control.
6. CG-art is produced by leaving a computer program to run by itself, with minimal or zero interference from a human being.

> Margaret A. Boden & Ernest A. Edmonds (2009) What is generative art?, Digital Creativity, 20: 102, 21-46

### Features
* System architecture
* \# of agents
* Roles
* Environment
* Corpus
* Input
* Output
* Communication
* Human interative modality
* Task
* Evaluation

> Tatar, K., & Pasquier, P. (2019). Musical agents: A topology and state of the art towards musical metacreation.

### Worked example of a generative system

Our goal is to create an AI system which can generate pop music.

It will have three parts:

Lyric generator using the GPT-2 transformer model Music generator using Music-VAE auto-encoder model Siging voice synthesis using the DiffSinger model.

### Markov model
Start with a word sequence:

>The problem with the pop music industry is the music"

Let's convert that into a first order model by making a state transition table.

The state will be the word selection we make.

It's first order because the state will only describe one word at a time.

The transition table is composed of the transitions:
* `The` transitions into `problem`
* `problem` transitions into `with`
* `with` transtions into `the`, and so on

Markov model - Transition table:
* The -> problem
* problem -> with
* with -> the
* the -> pop
* pop -> music
* music -> industry
* industry -> is
* is  -> the
* the  -> music

The reorganize it
* The -> problem
*    -> music
*    -> pop
* Problem  -> with
* with -> the
* pop -> music
* music -> industry
* industry -> is
* is -> the

Let's use this algorithm to turn this to a generative sequence that is statistical similar to the sample text.

1. Pick a random state from the observed states.
2. Select from possible next states, back to 2.
3. If no possible next state, go back to 1.

### Second order
We consider the two previous states.

Our state is based on the two previous words.

Transition table:
* The problem -> with
* Problem with -> the
* With the -> music
* The music -> industry
* Music industry -> is
* Industry is -> the
* Is the -> music

### How are more complex models different?
They have a more complex model of the sequence than a transition table. They have have multiple orders

They have a more complex method for pickign the next state/output, including more complex state.

### Examples of more complex generative text models
* Variable order Markov model
* Long short term memory network (LSTM)
* Transformer network (we'll use on of those)

## 11.7 Coding up a Markovian text generator and training it

* Build a model
* Sample from the model
* Generate a sequence
* Train on a larger dataset

The transition is the relation between states

Some words may transition to more than one other state.