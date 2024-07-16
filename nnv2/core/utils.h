#pragma once

#include <cstdlib>
#include <iostream>
#include <memory>
#include <unordered_map>

#include "array.h"

namespace nnv2 {

using ArrayMap = std::unordered_map<std::string, std::unique_ptr<Array>>;

#define CHECK_EQ(val1, val2, message)                                          \
    do {                                                                       \
        if ((val1) != (val2)) {                                                \
            std::cerr << __FILE__ << "(" << __LINE__ << "): " << (message)     \
                      << std::endl;                                            \
            exit(1);                                                           \
        }                                                                      \
    } while (0)

#define CHECK_COND(cond, message)                                              \
    do {                                                                       \
        if (!(cond)) {                                                         \
            std::cerr << __FILE__ << "(" << __LINE__ << "): " << (message)     \
                      << std::endl;                                            \
            exit(1);                                                           \
        }                                                                      \
    } while (0)

#define INIT_ARRAY(arr_ptr, shape)                                             \
    do {                                                                       \
        if ((arr_ptr).get() == nullptr) {                                      \
            (arr_ptr).reset(new Array((shape)));                               \
        } else {                                                               \
            if ((arr_ptr)->get_shape() != shape) {                             \
                (arr_ptr)->resize((shape));                                    \
            }                                                                  \
            (arr_ptr)->zero();                                                 \
        }                                                                      \
    } while (0)

#define INIT_CACHE(map, key, shape)                                            \
    do {                                                                       \
        if ((map).find((key)) == (map).end()) {                                \
            (map)[(key)] = std::make_unique<Array>((shape));                   \
        }                                                                      \
        INIT_ARRAY((map)[(key)], (shape));                                     \
    } while (0)

} // namespace nnv2