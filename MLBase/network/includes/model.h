#pragma once

#include <iostream>
#include <vector>
#include <cstddef> 
#include <stdexcept>
#include <string>
#include "../../../linalg/includes/matrix.h"
#include "../../losses/includes/losses.h"
#include "node.h"
#include "layer.h"


//for now we will just construct a doubly linked list but in the future will change to dag
struct LayerNode {
    public:
        LayerNode() {next_layer_ = NULL; previous_layer_ = NULL;}
        LayerNode(const Layer& input) {current_layer_ = input; next_layer_ = NULL; previous_layer_ = NULL;}
        void setPreviousLayer(LayerNode* input) {previous_layer_ = input;}
        void setNextLayer(LayerNode* input) {next_layer_ = input;}
        void setLayer(const Layer& input) {current_layer_ = input;}
        LayerNode* getNextLayer() {return next_layer_;}
        LayerNode* getPreviousLayer() {return previous_layer_;}
        Layer getCurrentLayer() {return current_layer_;}
    private:
        Layer current_layer_;
        LayerNode* next_layer_; 
        LayerNode* previous_layer_;
};

// general idea is that we store a linked list / tree of layers and then compile the output. this should make processing easier and faster 
class Model {
    public: 

    private:
        Losses loss;
        LayerNode input_layer_;
        LayerNode output_layer_;

};