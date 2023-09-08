Basic NN:
1. Linear Classfier: 
 * Takes in input vector, does vector dot product and addition with bias, outputs yes or no
 * Functions / classes needed to implement this
    * Matrix Class: Matrix dot product, general matrix storage / functionality (at first matrix will just store doubles, not floats / strings / ints) 
    * Node Class: Transform functionality, gradient computation for basic loss function
    * Data Handling: Load from CSV 
    * Loss function: MSE
2. Classifier with non-linearity: 
 * Takes in an input vector, does vector dot product and addition with bias, commputes non-linearity, computes loss, outputs yes or no
 * Functions / classes to implement this: 
    * Node class additions: create node for sigmoid and update rule for log loss
    * Loss functions: log loss 
3. Classifier with hidden layer: 
 * Takes in an input vector, does dot product against matrix representing the first layer. applies non-linearity, calculates output 
 * Functions / classes needed to implement this: 
    * Node Class: Add ReLU node, add 
    * Model Class: Train function, forward prop function, loss computation, backpropogation(gradient computation and weight update)
      *  
    * Layer Class: Load in multiple nodes, pass inputs to nodes, compile node outputs into output matrix/vector, return output, update weights. 
4. Classifier with multiple layers and multi-class output:    
 * Loss Functions: cross-entropy loss
 * Node Class: 

* We may consider implementing different extraneous functionalties through out this process such as different loss and data handling procedures but this will not be our main goal

Flesh out optimizers / layers: 

1. SGD and Minibatch SGD 
2. RMSProp and momentum: Implement this algorithim. 
3. Adam 

ConvNets: 

Other features: 

Optimization: 

Style: 

- Functions should be written with speed in mind
- Functions should be named in camel case with the first letter lower case 
- Variable names should be in snake case 
- Member variables should be in snake case and have an underscore at the end. 


Ideal model functionality: 

- Model(input_size, output_size, [optimizer, scheduler, etc]) 
- Model.add_layer(output_size, activation), the input size should be remembered 
- Model.add_layer....
- Model.compute_loss()
- Model.forward()
- Model.backward() should implicitly compute the loss and perform backprop      

Ideal Layer functionality: 

-Takes in an input matrix(or tensor) and outputs an output matrix(or tensor)