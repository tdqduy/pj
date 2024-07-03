#pragma once

#include "layer.h"

namespace nnv2 {

class ReLU : public Layer {
public:
    ReLU();

    void forward() override;
    void backward() override;

    Array *get_grad() { return next->get_grad(); }

    Array *get_output() { return prev->get_output(); }
};

class Softmax : public Layer {
public:
    Softmax();

    void forward() override;
    void backward() override;

    Array *get_grad() { return next->get_grad(); }

    Array *get_output() { return prev->get_output(); }
};

void relu_forward(Array *output, const Array *input);

void relu_backward(Array *input_grad, const Array *output_grad,
                   const Array *input);

void softmax_forward(Array *output, const Array *input);

void softmax_backward(Array *input_grad, const Array *output_grad);

} // namespace nnv2