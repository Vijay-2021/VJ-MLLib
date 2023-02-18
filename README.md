# VJ-MLLib
 * Vijay Shah, Jacob Stolker
# Project Objectives
 * Use [Keras](https://keras.io/api/) for reference
 * Use ~~strikethough~~ to cross off


## Data Handling
1. Train/Test Split
2. CSV
      * Read from CSV
      * Write to CSV
5. Model
      * Write to file
      * Read from file
6. CSR/COO format


## Linalg Library
1. Matrix/Tensor class
    * reshape
    * broadcasting
    * matrix/tensor.zeros()
    * matrix/tensor.ones()
    * matrix/tensor.identity()
2. Operator overloads
    *~~scalar/vector addition/subtraction~~ (completed for Matrix only so far)
    * ~~scalar multiplication/division~~ (completed for Matrix only so far)
    * ~~dot product (inner product)~~ 
    * cross product (outer product)
    * ~~matrix multiplication (elem-wise)~~ (completed for Matrix only so far)
    * ~~matrix multiplication (standard)~~ (completed for Matrix only so far)
3. Data Processing (static class (ex: Data.Max()))
    * Max/Min/ArgMax/ArgMin
    * Sum
    * Axis functionality
    * ~~Drop/Add~~ (completed for Matrix only so far)
    * Where (for finding null, inf, 0)


## NN Model
1. Layers (see section)
2. Model class
    - Layers (vector)
    - input/output shape
    - loss function
    - evaluate()
    - train()
        - forward prop
        - back prop
    - optimize()
    - weights, biases


3. Node Class
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
4. Optimizers (static class)
    - Adam
    - RMSprop
    - SGD


## Layers (preconfigured node arrays)
1. Abstract layer class
    - node array
    - in/out shape
    - connection
2. input layer
3. Activation layer
4. Conv2D layer
5. Dense layer
6. (Global)MaxPooling
7. (Global)AveragePooling
8. Dropout
9. Normalization
10. Lambda layer (arbitrary function on an activation layer)
 


## Loss functions (loss class)
1. mean_squared_error
    - loss function
    - backprop
2. mean_absolute_error
    - loss function
    - backprop
3. mean_absolute_percentage_error
    - loss function
    - backprop
4. mean_squared_logarithmic_error
    - loss function
    - backprop
5. squared_hinge
    - loss function
    - backprop
6. hinge
    - loss function
    - backprop
7. categorical_hinge
    - loss function
    - backprop
8. logcosh
    - loss function
    - backprop
9. categorical_crossentropy
    - loss function
    - backprop
10. sparse_categorical_crossentropy
    - loss function
    - backprop
11. binary_crossentropy
    - loss function
    - backprop
12. kullback_leibler_divergence
    - loss function
    - backprop
13. poisson
    - loss function
    - backprop
14. cosine_proximity
    - loss function
    - backprop



 ## Test Cases
* Catch
