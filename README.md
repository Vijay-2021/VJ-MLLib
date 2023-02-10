# VJ-MLLib
 * Vijay Shah, Jacob Stolker
# Project Objectives
 * Use Keras for reference
  - https://keras.io/api/
## Linalg Library
1. Matrix/Tensor class
 * reshape
 * broadcasting
 * matrix/tensor.zeros()
 * matrix/tensor.ones()
2. Operator overloads
 * scalar/vector addition/subtraction
* scalar multiplication/division
* dot product (inner product)
* cross product (outer product)
* matrix multiplication (elem-wise)
* matrix multiplication (standard)



## Loss functions (loss class)
* mean_squared_error
 * loss function
 * backprop
* mean_absolute_error
    ** loss function
    - backprop
 * mean_absolute_percentage_error
    - loss function
    - backprop
 * mean_squared_logarithmic_error
    - loss function
    - backprop
 * squared_hinge
    - loss function
    - backprop
 * hinge
    - loss function
    - backprop
 * categorical_hinge
    - loss function
    - backprop
 * logcosh
    - loss function
    - backprop
 * categorical_crossentropy
    - loss function
    - backprop
 * sparse_categorical_crossentropy
    - loss function
    - backprop
 * binary_crossentropy
    - loss function
    - backprop
 * kullback_leibler_divergence
    - loss function
    - backprop
 * poisson
    - loss function
    - backprop
 * cosine_proximity
   - loss function
   - backprop



## NN Model
 * Layers (see section)
 * Model class
   - Layers (vector)
   - input/output shape
   - loss function
   - evaluate()
   - train()
    - forward prop
    - back prop
   - optimize()
   - weights, biases


 * Node Class
   - abstract node
   - transform (function)
   - backprop(loss funct)
   - type:
    - sigmoid
    - relu
    - softmax
    - gradient
    - standard (no function applied)
    - lambda
 * Optimizers (static class)
   - Adam
   - RMSprop
   - SGD


## Layers
 * Abstract layer class
   - node array
   - in/out shape
   - connection
 * input layer
 * Activation layer
 * Conv2D layer
 * Dense layer
 * (Global)MaxPooling
 * (Global)AveragePooling
 * Dropout
 * Normalization
 * Lambda layer (arbitrary function on an activation layer)
 

 
