# GPT-2
## Objectives
* Describe how self-attention allows for a combination of contexual and sequential data in transformer networks.
* Instatiate a pre-trained language generating pipeline using GPT-2 and huggingface
* Explain how the process of fine-tuning works and why it is necessary to fine-tune pre-trained neural network models

## Context and aims
Our aim is to gain an intuitive grasp of the transformer.

## What is a transformer?
2017

Sequence and context via self-attention

## What came before transformer
* Bag of words

    `the problem with the pop music industry is the music`

    is turned into an object/array

    `{the, problem, with, pop, music, industry, is, music}`

    This ignores sequence, but takes on context.

* Recurrent neural networks
  
  Here the input is either **one hot encoded** vectors or **embeddings**

  Either way, it is the **sequence**, not the **context** which is modelled here. This is good for translations.

* Encoding sequences
  
  For example, the vocabulary of words are encoded to

  `the problem with the pop music`

  the `100000`  
  problem `010000`

  In this case, we have a 6-word vocabulary, one digit for each word. With this encoding, there is no information on where the words are located in relation to one another.

  That's where space embedding comes in, where statistical information on the words is recorded such that words that tend to have related meaning end up in a similar space, but the feature ignores context.

  We are still encoding the sequence `010000` to a vector, and we feed the vector to a network, a recurrent neural network such as LSTM neural networks to teach it to predict the next symbol from a sequence.

* Self attention: encoding context and sequence

So far we have seen 3 ways of representing a space of words:
* Bag of words
* One hot encoding
* Embedding (dimensionally reduce one hot) to similar spaces

Transformers add a layer known as **self attention** . It as contextual information to the sequential information.

In transformers, from the vector space a word is in, it gets placed into a space in a new layer not just by itself but with information from the other words that were in the sequence vector of the previous layer.

This is what the attention layer does, similarly to convolution where we filter surrounding values by multiplying them, the attention layer does this with the surrounding words.

We can have multiple filters, also known as multi-headed attention, where we have multiple filters processing the word embedding into new self-attention embeddings such that we take account of the balance of words in different ways to extract features and feed it into the training.

## GPT-2

### Too dangerous to realease
> Due to our concerns about malicious applications of the technology, we are not releasing the trained model. -OpenAI blog post, 2019

This happened during the height of election fake news.

### GPT2 config
What is GPT2?
* 40GB of text
* 1.5 billion parameters
* 48 layers

How does it work?

It uses self-attention with multiple 'heads' so it generates multiple attention projections.

It can be used in auto-regressive mode: it can generate an endless stream of words.

### Zeroshot concept
GPT-2 outperformed several state-of-the-art systems in zero-shot mode.

### Hugginface
>"We are on a mission to democratize good machine learning, one commit at a time."

It's a community and a collection of pre-trained models that can be downloaded through a Python API.

```Python
from transformers import pipeline, set_seed
generator = pipeline('text-generation', mode='gpt2-large')
generator.model.summary()
generator("The thing about love is ") #will generate some text
```

### GPT3
Why not GPT-3

As of 2021, some open-source versions are appearing but they have large computational requirements.

>Refer to week 12 code '1-lyrics-gpt2'
