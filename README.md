# Audio-processing-library
I am creating a small audio processing library. It will hear and process what is being spoken and finally return the said word

Currently I have implemented these functions using 32 bit float as datatype

1. fully connected (FC) layer that computes inner product of an input matrix of dimensions AxB and a weight matrix of dimensions BxC, to output a matrix of dimension AxC. To this output, a bias vector of dimension AXC is then added elementwise.
2. non-linear activations of an input matrix of any size with relu and tanh functions on individual matrix elements.
3. subsampling of square input matrices of any size with max pooling and average pooling functions
4. converting a vector of random floats to a vector of probabilities with softmax and sigmoid functions
